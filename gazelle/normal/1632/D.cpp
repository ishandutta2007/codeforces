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


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> a(n);
    REP(i, n) cin >> a[i];
    segment_tree<int> rgq(n, [] (int a, int b) { return gcd(a, b); }, 0);
    REP(i, n) rgq.update(i, a[i]);
    int ans = 0;
    REP(i, n) {
        int r = i, l = -1;
        while(r - l > 1) {
            int m = (l + r) / 2;
            if((i - m + 1) - rgq.query(m, i + 1) <= 0)
                r = m;
            else
                l = m;
        }
        if(rgq.query(r, i + 1) == (i - r + 1)) {
            ans++;
            rgq.update(i, 1000000007);
        }
        cout << ans;
        if(i < n - 1) cout << " ";
    }
    cout << endl;
    return 0;
}