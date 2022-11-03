#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii= pair<int, int>;

const int INF = 1e9 + 13;
const int M = 998244353;
const int N = 2e5 + 13;
const int B = 350;
const int K = 20;



vector<int> g[N], r[N];

// k >= 20
namespace fir {
    pii dp[N][2];
    set<pair<pii, pii>> st;

    void upd(int v, bool rev, pii p) {
        if(dp[v][rev] > p) {
            st.erase({dp[v][rev], {v, rev}});
            dp[v][rev] = p;
            st.insert({dp[v][rev], {v, rev}});
        }
    }

    pii get(int n) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < 2; j++)
                dp[i][j] = {INF, INF};
        }
        dp[0][0] = {0, 0};

        st.insert({dp[0][0], {0, 0}});

        while(!st.empty()) {
            int v = st.begin()->s.f;
            bool rev = st.begin()->s.s;
            st.erase(st.begin());

            if(v == n - 1) {
                return dp[v][rev];
            }

            if(rev) {
                pii nw = dp[v][1];
                nw.f++;
                upd(v, 0, nw);

                nw.f--;
                nw.s++;

                for(auto u : r[v])
                    upd(u, 1, nw);
            } else {
                pii nw = dp[v][0];
                nw.f++;
                upd(v, 1, nw);

                nw.f--;
                nw.s++;

                for(auto u : g[v])
                    upd(u, 0, nw);
            }
        }
    }

};

// k < 20
namespace sec {
    int dp[N][K];
    set<pair<int, pii>> st;

    void upd(int v, int k, int nw) {
        if(dp[v][k] > nw) {
            st.erase({dp[v][k], {v, k}});
            dp[v][k] = nw;
            st.insert({dp[v][k], {v, k}});
        }
    }

    int get(int n) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < K; j++) {
                dp[i][j] = INF;
            }
        }

        dp[0][0] = 0;
        st.insert({0, {0, 0}});

        while(!st.empty()) {
            int v = st.begin()->s.f;
            int k = st.begin()->s.s;
            st.erase(st.begin());

            if(v == n - 1)
                return dp[v][k];

            if(k == K - 1)
                continue;

            upd(v, k + 1, dp[v][k] + (1 << k));

            if(k % 2 == 0) {
                for(auto u : g[v])
                    upd(u, k, dp[v][k] + 1);
            } else {
                for(auto u : r[v])
                    upd(u, k, dp[v][k] + 1);
            }
        }

        return -1;
    }
}

int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int v, u;
        cin >> v >> u;

        v--;
        u--;

        g[v].push_back(u);
        r[u].push_back(v);
    }

    pii r1 = fir::get(n);
    int r2 = sec::get(n);

    int ans = 1;
    for(int i = 0; i < r1.f; i++)
        ans = ans * 2ll % M;
    ans = (ans + r1.s) % M;
    ans = (ans + M - 1) % M;



    if(r2 == -1) {
        cout << ans << endl;
        return 0;
    }

    if(r1.f >= 30) {
        cout << r2 << endl;
        return 0;
    }

    cout << min((1 << r1.f) - 1 + r1.s, r2) << endl;
}