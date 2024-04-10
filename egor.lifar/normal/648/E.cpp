#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <sstream>
#include <queue>
#include <unordered_map>
#include <set>


using namespace std;


int n, k;
int a[1000002];
int cnt[1000002];
int d[1021];
pair<int, int> ans[1021];
set<pair<int, int> > s;
int ss[11][1021];
long long f[1021];


int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if (a[i] == 0) {
            cout << "YES" << endl;
            cout << 0 << endl;
            return 0;
        }
        int b = a[i];
        while (b != 0) {
            b /= 10;
            cnt[i]++;
        }
        ss[cnt[i]][a[i] % k] = i + 1;
    }
    for (int i = 0; i < k; i++) {
        d[i] = 1000000000;
    }   
    int t = 0;
    for (int i = 0; i < n; i++) {
        d[a[i] % k] = min(d[a[i] % k], cnt[i]);
        if (d[a[i] % k] == cnt[i]) {
            ans[a[i] % k] = make_pair(a[i], -1);
        }
        if (a[i] % k == 0) {
            t = 1;
        }
    }
    f[0] = 1;
    for (int i = 1; i <= 10; i++) {
        f[i] = f[i - 1] * 10;
    }
    for (int i = 0; i < k; i++) {
        s.insert(make_pair(d[i], i));
    }
    while (!s.empty()) {
        int aa = (*s.begin()).second;
        s.erase(*s.begin());
        if (d[aa] == 1000000000) {
            continue;
        }
        if (aa == 0) {
            t = 1;
            break;
        }
        for (int j = 0; j <= 10; j++) {
            for (int g = 0; g < k; g++) {
                if (ss[j][g]) {
                    int newc = ((1LL * aa * f[j]) % k + g) % k;
                    if (d[newc] > d[aa] + j) {
                        s.erase(make_pair(d[newc], newc));
                        d[newc] = d[aa] + j;
                        ans[newc] = make_pair(a[ss[j][g] - 1], aa);
                        s.insert(make_pair(d[newc], newc));
                    }
                }
            }
        }
    }
    if (t) {
        cout << "YES" << endl;
        int l = 0;
        vector<int> v;
        while (l != -1) {
            v.push_back(ans[l].first);
            l = ans[l].second;
        }
        reverse(v.begin(), v.end());
        for (int i = 0; i < (int)v.size(); i++) {
            printf("%d", v[i]);
        }
        printf("\n");
    } else {
        cout << "NO" << endl;
    }
    return 0;   
}