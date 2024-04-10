#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <sstream>
#include <queue>
#include <map>
#include <set>
#include <cstring>
#include <cmath>


using namespace std;


#define M 1000000007
#define P 424243


int n;
int a[1000000];
map<int, int> m, m1;
int r[100001];
int p[100001];
int h[100001];


int gethash(int l, int r) {
    return (h[r] - (l > 0 ? 1LL * h[l - 1] * p[r - l + 1]: 0) % M + M) % M;
}


int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    p[0] = 1;
    for (int i = 1; i <= n; i++) {
        p[i] = (1LL * p[i - 1] * P) % M;
    }
    for (int i = 0; i < n; i++) {
        h[i] = ((i > 0 ? 1LL * h[i - 1] * P: 0) % M + a[i]) % M;
    }
    for (int i = n - 1; i >= 0; i--) {
        r[i] = m1[a[i]];
        m1[a[i]] = i;
    }
    vector<pair<int, int> > v;
    for (int i = 0; i < n; i++) {
        if (r[i] != 0) {
            for (int j = r[i]; j > 0; j = r[j]) {
                if (j + i - j - 1 >= n) {
                    break;
                }
                if (gethash(i, j - 1) == gethash(j, j + j - i - 1)) {
                    v.push_back(make_pair(j - i, i));
                }
            }
        }
    }
    sort(v.begin(), v.end());
    int ll = 0;
    for (int i = 0; i < (int)v.size(); i++) {
        if (v[i].second >= ll) {
            ll = v[i].first + v[i].second;
        }
    }
    cout << n - ll << endl;
    for (int j = ll; j < n; j++) {
        cout << a[j] << ' ';
    }
    cout << endl;
    return 0;
}