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
    const int MX = 100001; //check the limits, dummy
     
    vi primes, leastFac;
    void compPrimes(int N) {
    	F0R(i, N) {
    		leastFac.pb(0);
    	}
    	leastFac[0] = 1; leastFac[1] = 1;
    	FOR(i, 2, N) {
    		if (leastFac[i] == 0) {
    			primes.pb(i);
    			leastFac[i] = i;
    		}
    		for (int j = 0; j < sz(primes) && i*primes[j] < N && primes[j] <= leastFac[i]; j++) {
    			leastFac[i*primes[j]] = primes[j];
    		}
    	}
    }
     
    ll process(vpl &curList, ll P) {
    ll curAns = 2000000000000000000;
                ll cntUnder = 0, cntOver = P, curPos = curList[0].f, totalUnder = 0;
                ll totalOver = 0;
                F0R(i, sz(curList)) {
                    totalOver += (curList[i].f - curList[0].f) * curList[i].s; 
                }
                F0R(i, sz(curList)) {
                    totalUnder += cntUnder * (curList[i].f - curPos);
                    totalOver -= cntOver * (curList[i].f - curPos);
                    curPos = curList[i].f;
                    curAns = min(curAns, totalUnder + totalOver);
                    //cout << i << " " << totalUnder << " " << totalOver << endl;
                    //cout << curList[i].f << " " << curList[i].s << endl;
                    cntOver -= curList[i].s;
                    cntUnder += curList[i].s;
                }
                return curAns;
     
     
    }
     
    int main() {
    	ios_base::sync_with_stdio(0); cin.tie(0);    
        compPrimes(1000000);
        int N; cin >> N;
        ll total= 0;
        vl data(N);
        F0R(i, N) cin >> data[i];
        F0R(i, N) total += data[i];
     
        vl facs; F0R(i, sz(primes)) {
            if (total % primes[i] == 0) {
                facs.pb(primes[i]);
                while (total % primes[i] == 0) total /= primes[i];
            }
        }
        if (total > 1) {
            facs.pb(total);
        }
        if (sz(facs) == 0) {
            cout << -1 << endl;
            return 0;
        }
     
        ll ans = 2000000000000000000;
     
        F0R(curIndex, sz(facs)) {
            ll P = facs[curIndex];
            vpl curList;
            ll cnt = 0;
            ll totalAns = 0;
            F0R(i, N) {
                ll val = data[i];
                if (cnt + val >= P && cnt != 0) {
                    curList.pb({i, P-cnt});
                    totalAns += process(curList, P);
                    vpl blank; curList = blank;
                    val -= P-cnt;
                    cnt = 0;
                }
                val %= P;
                if (val > 0) {
                    cnt += val;
                    curList.pb({i, val});
                }
            }
     
            ans = min(ans, totalAns);
        }
        cout << ans << endl;
    	
    	return 0;
    }
     
    // read the question correctly (ll vs int)
    // template by bqi343