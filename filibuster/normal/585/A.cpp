#include <bits/stdc++.h>

#define f first
#define s second
#define int long long

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9;
const int M = 1e9 + 7;
const int N = 1000 + 13;

/*
*/

signed main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int n;
    cin >> n;

    vector<int> v(n), d(n), p(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i] >> d[i] >> p[i];
    }

    vector<bool> is(n, true);
    vector<int> ans;
    for(int i = 0; i < n; i++) {
        if(is[i]) {
            ans.push_back(i);

            for(int j = i + 1; j < n; j++) {
                if(is[j]) {
                    p[j] -= max(0ll, v[i]);
                    v[i]--;
                }
            }

            int cur = 0;
            for(int j = i + 1; j < n; j++) {
                if(is[j]) {
                    p[j] -= cur;
                    if(p[j] < 0) {
                        is[j] = false;
                        cur += d[j];
                    }
                }
            }
        }
    }

    cout << ans.size() << endl;
    for(auto x : ans)
        cout << x + 1 << ' ';
}