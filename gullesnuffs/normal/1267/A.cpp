#include <bits/stdc++.h>
using namespace std;

#define rep(i,f,t) for (int i = (f); i < (t); i++)
#define all(x) (x).begin(), (x).end()
#define trav(a,x) for (auto& a : x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, int> pii;

ll res = 0;
ll T = 0;
vi len;
vi starts;
vi endt;

set<pii> active;
set<pii> nextStart;

int main() {
    cin.sync_with_stdio(false);
    int N;
    cin >> N;
    len.resize(N);
    starts.resize(N);
    endt.resize(N);

    rep(i,0,N) {
        ll s, t, l;
        cin >> s >> t >> l;

        len[i] = l;
        starts[i] = s;
        endt[i] = t;

        nextStart.emplace(s, i);
    }

    while (!active.empty() || !nextStart.empty()) {
        if (active.empty()) {
            int nx = nextStart.begin()->second;
            nextStart.erase(nextStart.begin());
            active.emplace(len[nx], nx);
            continue;
        }

        int cur = active.begin()->second;
        if (T + len[cur] > endt[cur]) {
            active.erase(active.begin());
            continue;
        }

        ll curt = max(T, starts[cur]);
        ll fastfw = (endt[cur] - curt) / len[cur];
        if (!nextStart.empty()) fastfw = min(fastfw, (nextStart.begin()->first - curt) / len[cur]);
        if (fastfw) {
            T = curt + fastfw * len[cur];
            res += fastfw;
            continue;
        }

        ll nt = curt + len[cur];
        while (!nextStart.empty() && nextStart.begin()->first <= nt) {
            int nx = nextStart.begin()->second;
            nextStart.erase(nextStart.begin());
            active.emplace(len[nx], nx);
            
            ll nxt = max(T, starts[nx]);
            if (nxt + len[nx] <= endt[nx] && nxt + len[nx] < nt) {
                nt = nxt + len[nx];
            }
        }
        res++;
        T = nt;
    }

    cout << res << endl;
}