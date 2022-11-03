#include <bits/stdc++.h>

#define f first
#define s second
//#define x first
//#define y second
//#define int li
#define err if(debug_out)cout

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
using pld = pair<ld, ld>;

const int INF = 1e9 + 13;
const li INF64 = 1e18 + 13;
const int N = 3e5 + 13;
const int LOGN = 20;
const int K = 22;
const int M = 998244353;//1e9 + 7;
const int A = 26;
const ld eps = 1e-8;

mt19937 rnd(45768);

/*
*/

int a[N];

void solve() {
    int n, m;
    cin >> n >> m;


    map<int, int> cnt;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }

    set<pii> st;
    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;

        st.insert({x, y});
        st.insert({y, x});
    }
//    cout << "tjdyh" << endl;


    map<int, vector<int>> mp;
    for(auto it = cnt.rbegin(); it != cnt.rend(); it++) {
        mp[it->s].push_back(it->f);
    }
//    cout << "asrg" << endl;

    li ans = 0;
    for(auto pr : cnt) {
        int x = pr.f;
        int c = pr.s;
//cout << pr.f << ' ' << pr.s << endl;
        for(auto it = mp.begin(); it != mp.end(); it++) {
            for(int y : it->s) {
                if(x != y && !st.count({x, y})) {
                    ans = max(ans, (x + y) * 1ll * (it->f + c));
                    break;
                }
            }
        }
    }

    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}