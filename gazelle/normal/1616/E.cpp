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

template <typename T> struct segment_tree {
  private:
    int n;
    const function<T(T, T)> op;
    const T ie;
    vector<T> seq;

  public:
    segment_tree(int _n, function<T(T, T)> op, const T ie) : op(op), ie(ie) {
        n = 1;
        while(n < _n)
            n *= 2;
        seq.resize(2 * n - 1);
        for(int i = 0; i < 2 * n - 1; i++)
            seq[i] = ie;
    }

    void update(int k, const T e) {
        k += n - 1;
        seq[k] = e;
        while(k > 0) {
            k = (k - 1) / 2;
            seq[k] = op(seq[k * 2 + 1], seq[k * 2 + 2]);
        }
    }

    T get(int k) {
        k += n - 1;
        return seq[k];
    }

    T query(int a, int b, int k = 0, int l = 0, int r = -1) {
        if(r == -1)
            r = n;
        if(r <= a || b <= l)
            return ie;
        if(a <= l && r <= b)
            return seq[k];
        T vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
        T vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
        return op(vl, vr);
    }
};
// segment_tree<ll> rsq(n, [] (ll a, ll b) { return a + b; }, 0)
// segment_tree<ll> rMq(n, [] (ll a, ll b) { return max(a, b); }, -1e18)
// segment_tree<ll> rmq(n, [] (ll a, ll b) { return min(a, b); }, 1e18)

int n;
int real_i(int i, segment_tree<int> &rsq) { return i + rsq.query(i, n + 1); }

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    REP(testcase, t) {
        cin >> n;
        string s, t;
        cin >> s >> t;
        vector<queue<int>> q(26);
        REP(i, n) { q[s[i] - 'a'].push(i); }
        string sorted_s = s;
        sort(ALL(sorted_s));
        if(sorted_s >= t) {
            cout << -1 << "\n";
            continue;
        }
        segment_tree<int> rsq(
            n + 1, [](int a, int b) { return a + b; }, 0);
        ll ans = inf * inf;
        ll sum = 0;
        REP(i, n) {
            for(int c = 0; c < (int)(t[i] - 'a'); c++) {
                if(not q[c].empty()) {
                    ans = min(ans, sum + real_i(q[c].front(), rsq) - i);
                }
            }
            if(q[t[i] - 'a'].empty())
                break;
            int index = q[t[i] - 'a'].front();
            q[t[i] - 'a'].pop();
            sum += real_i(index, rsq) - i;
            rsq.update(index, 1);
            // cout << sum << endl;
        }
        cout << ans << "\n";
    }
    return 0;
}