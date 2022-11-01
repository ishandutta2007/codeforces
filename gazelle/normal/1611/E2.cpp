#include <bits/stdc++.h>
#define FOR(i, n, m) for(long long i = (n); i < (long long)(m); i++)
#define REP(i, n) FOR(i, 0, n)
#define ALL(v) v.begin(), v.end()
#define pb push_back
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll, ll>;
constexpr ll inf = 1000000000;
constexpr ll mod = 998244353;
constexpr ld eps = 1e-6;

template <typename T1, typename T2>
ostream &operator<<(ostream &os, pair<T1, T2> p) {
    os << to_string(p.first) << " " << to_string(p.second);
    return os;
}
template <typename T> ostream &operator<<(ostream &os, vector<T> &v) {
    REP(i, v.size()) {
        if(i)
            os << " ";
        os << v[i];
    }
    return os;
}

void dfs(int v, int p, vector<vector<int>> &t, vector<bool> &occ,
         vector<bool> &guard, deque<int> &dq) {
    dq.push_back(v);
    if(occ[v])
        guard[dq[(int)dq.size() / 2]] = true;
    for(auto ch : t[v]) {
        if(ch == p)
            continue;
        dfs(ch, v, t, occ, guard, dq);
    }
    dq.pop_back();
}

bool dfs2(int v, int p, vector<vector<int>> &t, vector<bool> &guard, int &ans) {
    if(guard[v]) {
        ans += 1;
        return true;
    }
    if(v != 0 && (int)t[v].size() == 1)
        return false;

    bool ret = true;
    for(auto ch : t[v]) {
        if(ch == p)
            continue;
        ret &= dfs2(ch, v, t, guard, ans);
    }

    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    REP(testcase, t) {
        int n, k;
        cin >> n >> k;
        vector<bool> occ(n, false);
        vector<bool> guard(n, false);
        REP(i, k) {
            int x;
            cin >> x;
            occ[x - 1] = true;
        }

        vector<vector<int>> t(n);
        REP(i, n - 1) {
            int a, b;
            cin >> a >> b;
            a--;
            b--;
            t[a].pb(b);
            t[b].pb(a);
        }

        deque<int> dq;
        dfs(0, -1, t, occ, guard, dq);
        int ans = 0;
        if(dfs2(0, -1, t, guard, ans))
            cout << ans << "\n";
        else
            cout << -1 << "\n";
    }

    return 0;
}