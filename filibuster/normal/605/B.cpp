#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9;
const int M = 1e9 + 7;
const int N = 500 + 13;

/*
*/

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<pii, int>> a(m);
    for(int i = 0; i < m; i++) {
        cin >> a[i].f.s >> a[i].f.f;
        a[i].f.f = -a[i].f.f;
        a[i].s = i;
    }

    sort(a.begin(), a.end());

    vector<pii> ans(m, {-1, -1});
    vector<int> in(n, 0);
    int lv = -1, lu = 0;
    for(auto p : a) {
//        cout << p.f.f << ' ' << p.f.s << ' ' << p.s << ' '<< lv << ' ' << lu << endl;
        if(p.f.f == 0) {
            if(lv == n - 2) {
                lv = 0;
                lu = 1;
            }

            if(lu - lv <= 2) {
                lu++;
                lv = 0;
            } else {
                lv++;
            }

            ans[p.s] = {lv, lu};
//            cout << lu << ' ' << in[lu] << endl;
            if(p.f.s < in[lu]) {
//                cout << lv + 1 << ' ' << lu + 1 << ' ' << in[lu] << endl;
                cout << -1;
                return 0;
            }
        } else {
            ans[p.s] = {lu, lu + 1};
            in[lu + 1] = p.f.s;
            lv++;
            lu++;

        }
    }

    for(auto p : ans) {
        cout << p.f + 1 << ' ' << p.s + 1 << endl;
    }
}