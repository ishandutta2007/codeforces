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

    int n;
    cin >> n;

    constexpr int M = 200000;

    vector<vector<int>> ms(M + 1, vector<int>(21, 0));

    REP(i, n) {
        int m, k;
        cin >> m >> k;
        ms[m][k] += 1;
    }

    long double mx = 0.0;
    int arg_max = -1;

    for(int num = 1; num <= 20; num += 1) {
        vector<pair<int, int>> pows(M + 1, {0, 0});
        FOR(i, 1, M + 1) {
            pows[i].second = i;
            REP(j, 21) {
                if(j <= num)
                    pows[i].first += j * ms[i][j];
                else
                    pows[i].first += num * ms[i][j];
            }
        }
        sort(ALL(pows));
        reverse(ALL(pows));
        ll sum_pow = 0;
        REP(i, num) { sum_pow += pows[i].first; }
        if(sum_pow / (long double)num >= mx - 1e-9) {
            mx = sum_pow / (long double)num;
            arg_max = num;
        }
    }

    vector<pair<int, int>> pows(M + 1, {0, 0});
    FOR(i, 1, M + 1) {
        pows[i].second = i;
        REP(j, 21) { pows[i].first += j * ms[i][j]; }
    }
    sort(ALL(pows));

    ll sum_pow = 0;
    REP(i, 20) sum_pow += pows[i].first;

    for(int num = 21; num <= M; num += 1) {
        sum_pow += pows[num - 1].first;
        if(sum_pow / (long double)num >= mx - 1e-9) {
            mx = sum_pow / (long double)num;
            arg_max = num;
        }
    }

    vector<int> ans;
    if(arg_max <= 20) {
        vector<pair<int, int>> ppows(M + 1, {0, 0});
        FOR(i, 1, M + 1) {
            ppows[i].second = i;
            REP(j, 21) {
                if(j <= arg_max)
                    ppows[i].first += j * ms[i][j];
                else
                    ppows[i].first += arg_max * ms[i][j];
            }
        }
        sort(ALL(ppows));
        reverse(ALL(ppows));
        REP(i, arg_max) ans.pb(ppows[i].second);
    } else {
        REP(i, arg_max) ans.pb(pows[i].second);
    }

    cout << (int)ans.size() << endl;
    cout << ans << endl;

    return 0;
}