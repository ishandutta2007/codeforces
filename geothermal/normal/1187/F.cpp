#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;

template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()

const int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 100001; //check the limits, dummy

ll modExp(ll base, ll power) {
    if (power == 0) {
        return 1;
    } else {
        ll cur = modExp(base, power / 2); cur = cur * cur; cur = cur % MOD;
        if (power % 2 == 1) cur = cur * base;
        cur = cur % MOD;
        return cur;
    }
}

ll inv(ll base) {
    return modExp(base, MOD-2);
}

ll mul(ll A, ll B) {
    return (A*B)%MOD;
}

ll add(ll A, ll B) {
    return (A+B)%MOD;
}

ll unm(ll A, ll B) {
    return mul(A, inv(B));
}

ll sub(ll A, ll B) {
    return (A-B+MOD)%MOD;
}

struct Frac {
    ll A, B;

    Frac(ll A1, ll B1) {
        A = A1, B = B1;
        A %= MOD; B %= MOD;
    }

    ll ans() {
        A %= MOD; B %= MOD;
        return unm(A, B);
    }

    Frac operator+(const Frac& F) {
        A %= MOD; B %= MOD;
        ll num = add(mul(A, F.B), mul(B, F.A));
        ll den = mul(B, F.B);
        Frac res(num, den);
        res.A %= MOD; res.B %= MOD;
        return res;
    }

    Frac operator-(const Frac& F) {
        A %= MOD; B %= MOD;
        ll num = sub(mul(A, F.B), mul(B, F.A));
        ll den = mul(B, F.B);
        Frac res(num, den);
        res.A %= MOD; res.B %= MOD;
        return res;
    }

    Frac operator*(const Frac& F) {
        A %= MOD; B %= MOD;
        ll num = mul(A, F.A);
        ll den = mul(B, F.B);
        Frac res(num, den);
        res.A %= MOD; res.B %= MOD;
        return res;
    }

    Frac operator/(const Frac& F) {
        A %= MOD; B %= MOD;
        ll num = mul(A, F.B);
        ll den = mul(B, F.A);
        Frac res(num, den);
        res.A %= MOD; res.B %= MOD;
        return res;
    }

    Frac& operator+=(const Frac& F) { return *this = (*this) + F; }
    Frac& operator-=(const Frac& F) { return *this = (*this) - F; }
    Frac& operator*=(const Frac& F) { return *this = (*this) * F; }
    Frac& operator/=(const Frac& F) { return *this = (*this) / F; }
};

Frac computeProb(ll L1, ll R1, ll L2, ll R2) {
    L1 = L1 % MOD; L2 = L2 % MOD; R1 = R1 % MOD; R2 = R2 % MOD;
    if (L1 > R1 || L2 > R2) return Frac(1, 1);
    if (L1 > R2 || L2 > R1) return Frac(1, 1);
    Frac ans = Frac(1, 1) - Frac(min(R1, R2) - max(L1, L2) + 1, mul((R1 - L1 + 1), (R2 - L2 + 1)));
    ans.A = ans.A % MOD; ans.B = ans.B % MOD;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int N; cin >> N;
    ll L[N], R[N];
    F0R(i, N) cin >> L[i];
    F0R(i, N) cin >> R[i];

    vector<Frac> prob;
    prob.pb(Frac(1, 1));
    Frac sum(1, 1);
    F0R(i, N-1) {
        prob.pb(computeProb(L[i], R[i], L[i+1], R[i+1]));
        sum += prob[i+1];
    }

    Frac ans(0, 1);

    F0R(i, N) {
        if (prob[i].A == 0) continue;
        Frac curSum = sum;
        curSum -= prob[i];
        curSum += Frac(1, 1);
        if (i > 1) {
            curSum -= prob[i-1];
            Frac cur = prob[i-1];
            Frac temp = computeProb(L[i-2], R[i-2], max(L[i], L[i-1]), min(R[i], R[i-1]));
            temp = temp * (Frac(1, 1) - prob[i]);
            cur -= temp;
            cur = cur / prob[i];
            curSum += cur;
        }
        if (i > 0 && i < N-1) {
            curSum -= prob[i+1];
            Frac cur = prob[i+1];
            Frac temp = computeProb(L[i+1], R[i+1], max(L[i], L[i-1]), min(R[i], R[i-1])) * (Frac(1, 1) - prob[i]);
            cur = cur - temp;
            cur = cur / prob[i];
            curSum += cur;
        }
        ans += curSum * prob[i];
    }

    cout << ans.ans() << endl;

    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343