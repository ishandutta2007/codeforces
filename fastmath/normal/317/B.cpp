#include<bits/stdc++.h>
using namespace std;
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcount
#define ll long long
#define mp make_pair
#define f first
#define s second
#define Time (double)clock()/CLOCKS_PER_SEC
vector <ii> v = { {0, -1}, {0, 1}, {-1, 0}, {1, 0 } };
const int N = 2007, ADD = 1000;
int cnt[N][N];
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n, m;
    cin >> n >> m;
    cnt[ADD][ADD] = n;
    queue <ii> q;
    q.push(mp(0, 0));
    while (q.size()) {
        auto p = q.front(); q.pop();
        if (cnt[p.f + ADD][p.s + ADD] >= 4) {
            cnt[p.f + ADD][p.s + ADD] -= 4;
            if (cnt[p.f + ADD][p.s + ADD] >= 4)
                q.push(p);
            for (auto e : v) {
                auto t = mp(p.f + e.f, p.s + e.s);
                ++cnt[t.f + ADD][t.s + ADD];
                if (cnt[t.f + ADD][t.s + ADD] >= 4)
                    q.push(t);
            }   
        }   
    }   
    while (m--) {
        int x, y;
        cin >> x >> y;
        if (abs(x) > 1000 || abs(y) > 1000) 
            cout << 0 << endl;
        else
            cout << cnt[x + ADD][y + ADD] << endl;
    }   
}