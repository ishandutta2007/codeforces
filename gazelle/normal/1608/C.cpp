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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    REP(i, t) {
        int n;
        cin >> n;
        vector<pair<int, int>> p(n);
        REP(i, n) cin >> p[i].first;
        REP(i, n) cin >> p[i].second;
        vector<bool> used(n, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq1, pq2;
        REP(i, n) {
            pq1.push({p[i].first, i});
            pq2.push({p[i].second, i});
        }
        vector<pair<int, int>> ppq(n);
        REP(i, n) ppq[i] = {p[i].first, i};
        sort(ALL(ppq));
        int sum = 0;
        vector<bool> ans(n, false);
        REP(i, n) {
            queue<int> q;
            if(not used[ppq[i].second]) {
                q.push(ppq[i].second);
                used[ppq[i].second] = true;
            }
            while(not q.empty()) {
                int pq = q.front();
                q.pop();
                sum += 1;
                while(not pq2.empty() && pq2.top().first < p[pq].second) {
                    int qq = pq2.top().second;
                    pq2.pop();
                    if(not used[qq])
                        q.push(qq);
                    used[qq] = true;
                }
                while(not pq1.empty() && pq1.top().first < p[pq].first) {
                    int qq = pq1.top().second;
                    pq1.pop();
                    if(not used[qq])
                        q.push(qq);
                    used[qq] = true;
                }
            }
            if(sum == n)
                ans[ppq[i].second] = true;
        }
        string anstr = "";
        REP(i, n) {
            if(ans[i])
                anstr += "1";
            else
                anstr += "0";
        }
        cout << anstr << endl;
    }

    return 0;
}