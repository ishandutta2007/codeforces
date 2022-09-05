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
const int MX = 101; //check the limits, dummy

const double EPS = 1e-7;
const int INF = 100000; // it doesn't actually have to be infinity or a big number

ll base1[MX], base2[MX];

ll modExpTest(ll base, ll power, ll prime) {
		if (power == 0) {
				return 1;
		} else {
				ll cur = modExpTest(base, power / 2, prime); cur = cur * cur; cur = cur % prime;
				if (power % 2 == 1) cur = cur * base;
				cur = cur % prime;
				return cur;
		}
}

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
            push_back(S[i] - 'a');
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
       	//inVal1s.pb(modExp(val1, p1-2));
				//inVal2s.pb(modExp(val2, p2-2));
    }


		pl get(int L, int R) {
			ll A = (val1s[R+1] - (val1s[L] * base1[R-L+1]) % p1 + p1) % p1;
			ll B = (val2s[R+1] - (val2s[L] * base2[R-L+1]) % p2 + p2) % p2;
			return {A, B};
		}

	ll value() {
		return val1 * (MOD+2) + val2;
	}

};
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);  
	
	int base = uniform_int_distribution<int>(1000, MOD-2)(rng);

	base1[0] = 1; base2[0] = 1;
	FOR(i, 1, MX) {
		base1[i] = base1[i-1] * base; base1[i] %= MOD;
		base2[i] = base2[i-1] * base; base2[i] %= (MOD+2);
	}  
	
	int N; cin >> N;
	int A[N]; F0R(i, N) cin >> A[i];
	
	gp_hash_table<ll, ll> poss;
	
	F0R(x, (1 << 15)) {
		hsh hash(base, "");
		vi curList;
		F0R(i, N) {
			int cur = A[i] ^ x;
			int cnt = 0;
			F0R(j, 15) {
				if (cur & (1 << j)) cnt++;
			}
			curList.pb(cnt);
			
		}
		
		F0Rd(i, N) {
			curList[i] += 50 - curList[0];
		}
		
		F0R(i, N) hash.pb(curList[i]);
		
		poss.insert({hash.value(), x});
	}
	
	F0R(x, (1 << 15)) {
		vi profile;
		int highest = 0;
		F0R(i, N) {
			int cur = A[i] ^ (x << 15);
			int cnt = 0;
			F0R(j, 15) {
				if (cur & (1 << (j+15))) cnt++;
			}
			highest = max(highest, cnt);
			profile.pb(cnt);
		}
		
		FOR(i, 50 + profile[0], 51 + profile[0]) {
			hsh curHash(base, "");
			F0R(j, N) {
				curHash.pb(i - profile[j]);
			}
			
			if (poss.find(curHash.value()) != poss.end()) {
				cout << (x << 15) + poss[curHash.value()] << endl;
				return 0;
			}
		}
			
	}
	
	cout << -1 << endl;
	
	/*F0R(x, 31) {
		//have i digits
		vector<vd> equations;
		F0R(i, N) {
			vd curEq;
			int totalCount = 0;
			F0R(j, 30) {
				if (A[i] & (1 << j)) {
					curEq.pb(-1);
					totalCount++;
				} else {
					curEq.pb(1);
				}
			}
			curEq.pb(x - totalCount);
			equations.pb(curEq);
		}
		
		vd res(30); 
		gauss(equations, res);
		int ans = 0;
		
		/*if (x == 16) {
			F0R(i, 30) {
				cout << res[i] << " ";
			}
		}
		cout << endl;*/
		
		/*F0R(i, 30) {
			if (abs(res[i] - 0) > EPS && abs(res[i] - 1) > EPS) goto bad;
		}
		
		F0R(i, 30) if (abs(res[i] - 1) < EPS) ans += (1 << i);
		cout << ans << endl;
		return 0;
		
		bad:;
	}
	
	cout << -1 << endl;*/
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343