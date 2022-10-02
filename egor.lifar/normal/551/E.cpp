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


int n, q;
long long a[1000000];
long long d[10000];
vector<pair<long long, int> > v[10000];


int main() {    
    cin >> n >> q;
    int l1 = (int)sqrt(n) + 1;
    vector<int> t;
    t.push_back(0);
    int l = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i - t.back() + 1 > l1) {
            t.push_back(i);
            l++;
        }
        v[l].push_back(make_pair(a[i], i));
    }
    t.push_back(n);
    for (int i = 0; i <= l; i++) {
        sort(v[i].begin(), v[i].end());
    }
    for (int i = 0; i < q; i++) {
        int tt;
        scanf("%d", &tt);
        if (tt == 2) {
            int y;
            scanf("%d", &y);
            int ll = -1;
            for (int j = 0; j <= l; j++) {
                int t = distance(v[j].begin(), lower_bound(v[j].begin(), v[j].end(), make_pair(1LL * (y - d[j]), 0)));
                if (t == (int)v[j].size()) {
                    continue;
                }
                if (v[j][t].first != y - d[j]) {
                    continue;
                }
                ll = v[j][t].second;
                break;
            }
            if (ll == -1) {
                printf("%d\n", -1);
                continue;
            }
            int rr = -1;
            for (int j = l; j >= 0; j--) {
                int t = distance(v[j].begin(), upper_bound(v[j].begin(), v[j].end(), make_pair(1LL * (y - d[j]), 1000 * 1000))) - 1;
                if (t == -1) {
                    continue;
                }
                if (v[j][t].first != y - d[j]) {
                    continue;
                }
                rr = v[j][t].second;
                break;
            }
            printf("%d\n", rr - ll);
        } else {
            int ll, rr, x;
            scanf("%d %d %d", &ll, &rr, &x);
            ll--;
            rr--;
            for (int j = 0; j <= l; j++) {
                if (t[j] >= ll && t[j + 1] - 1 <= rr) {
                    d[j] += 1LL * x;
                } else {
                    if (!(t[j + 1] - 1 < ll || t[j] > rr)) {
                        for (int k = max(t[j], ll); k <= min(rr, t[j + 1] - 1); k++) {
                            a[k] += 1LL * x;
                        }
                        v[j].clear();
                        for (int k = t[j]; k < t[j + 1]; k++) {
                            v[j].push_back(make_pair(a[k], k));
                        }
                        sort(v[j].begin(), v[j].end());
                    }
                }
            }
        }
    }
    return 0;
}