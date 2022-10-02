#include <iostream>
#include <algorithm>
#include <cstdio>
#include <sstream>
#include <cmath>
#include <map>
#include <string.h>
#include <vector>


using namespace std;


int n, m;
vector<int> v;
int k = 1000000000;
long long ans = 0;


int main() {
    cin >> m;
    for (int i = 0; i < m; i++) {
        int a;
        cin >> a;
        k = min(a, k);
    }
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }
    sort(v.rbegin(), v.rend());
    int t = 0;
    for (int i = 0; i < n; i++) {
        if (t >= 0) {
            ans += v[i];
        }
        t++;
        if (t == k) {
            t = 0;
            if (i < n - 1) {
                t--;
                if (i < n - 2) {
                    t--;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}