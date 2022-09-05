#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
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
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 200011; //check the limits, dummy
 
ll base1[MX], base2[MX];

struct hsh  {
    ll base, p1, p2;

    ll val1, val2;
    ll inv1, inv2;

	vl val1s, val2s;

	vl inVal1s, inVal2s;

	ll modExp(ll power, ll prime) {
        if (power == 0) {
            return 1;
        } else {
            ll cur = modExp(power / 2, prime); cur = cur * cur; cur = cur % prime;
            if (power % 2 == 1) cur = cur * base;
            cur = cur % prime;
            return cur;
        }
    }

    hsh() {
    }


    hsh(ll b, string S) {
        p1 = 1000000007;
        p2 = 1000000009;
        base = b;
        val1 = 0;
        val2 = 0;

        inv2 = modExp(p2-2, p2);
        inv1 = modExp(p1-2, p1);
				val1s.pb(0); val2s.pb(0);
        F0R(i, sz(S)) {
            push_back(S[i] - '0');
        }

    }

    void push_back(ll v) {
        val1 *= base;
        val1 %= p1;
        val1 += v;
        val1 %= p1;
        val2 *= base;
        val2 %= p2;
        val2 += v;
        val2 %= p2;

		val1s.pb(val1);
		val2s.pb(val2);
    }


		pl get(int L, int R) {
			ll A = (val1s[R+1] - (val1s[L] * base1[R-L+1]) % p1 + p1) % p1;
			ll B = (val2s[R+1] - (val2s[L] * base2[R-L+1]) % p2 + p2) % p2;
			return {A, B};
		}



};

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
	int base = uniform_int_distribution<int>(1000, MOD-2)(rng);

	base1[0] = 1; base2[0] = 1;
	FOR(i, 1, MX) {
		base1[i] = base1[i-1] * base; 
        base1[i] %= MOD;
		base2[i] = base2[i-1] * base;
        base2[i] %= MOD+2;
	}

    int N; cin >> N;
    string S; cin >> S;
    hsh hash(base, S);

    int pref[N+1][2]; pref[0][0] = 0; pref[0][1] = 0;
    F0R(i, N) {
        pref[i+1][0] = pref[i][0];
        pref[i+1][1] = pref[i][1];
        if (S[i] == '1') {
            pref[i+1][i%2]++;
        }
    }
    string zers;
    int zed[N], zed2[N];
    F0R(i, N) {
        zed[i] = sz(zers);
        if (S[i] == '0') {
            zers.pb((char) ('0' + i % 2));
        }
        zed2[i] = sz(zers);
    }

    hsh zHash(base, zers);
    string ones; F0R(i, sz(zers)) ones.pb('1');
    hsh fullHash(base, ones);



    set<int> chains;

    F0R(i, N-1) {
        if (S[i] == '1' && S[i+1] == '1') chains.insert(i);
    }

    int Q; cin >> Q;
    F0R(i, Q) {
        int A, B, C; cin >> A >> B >> C; A--; B--;
//        cout << hash.get(A, A+C-1).f << " " << hash.get(B, B+C-1).f << endl;
        if (hash.get(A, A+C-1) == hash.get(B, B+C-1)) {

            cout << "YES" << endl; continue;
        }
        if (chains.lb(A) == chains.end() || chains.lb(B) == chains.end() || *chains.lb(A) >= A+C-1 || *chains.lb(B) >= B+C-1) {
            cout << "NO" << endl; continue;
        }
        if (zed2[A+C-1] - zed[A] != zed2[B+C-1] - zed[B]) {
            cout << "NO" << endl; continue;
        }
        pl val1 = zHash.get(zed[A], zed2[A+C-1]-1), val2 = zHash.get(zed[B], zed2[B+C-1]-1);
        pl big = fullHash.get(zed[A], zed2[A+C-1]-1);
        if (val1 == val2 && (A % 2 == B % 2)) {
            cout << "YES" << endl;
        } else if ((val1.f + val2.f) % MOD == big.f && (val1.s + val2.s) % (MOD+2) == big.s && (A % 2 != B % 2)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
/*        int cnt1 = pref[A+C][A%2] - pref[A][A%2];
        int cnt2 = pref[A+C][1-(A%2)] - pref[A][1-(A%2)];
        int cnt3 = pref[B+C][B%2] - pref[B][B%2];
        int cnt4 = pref[B+C][1-(B%2)] - pref[B][1 - (B%2)];
        if (cnt1 == cnt3 && cnt2 == cnt4) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }*/
    }
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343