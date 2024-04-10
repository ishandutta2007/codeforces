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

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    compPrimes(5000);

    vector<vi> seqs(5001);
    int counts[5000]; F0R(i, 5000) counts[i] = 0;
    F0R(x, 5001) {
        int cur = x;
        if (x > 0) {
            F0R(i, sz(primes)) {
                while (cur % primes[i] == 0) {
                    cur /= primes[i];
                    counts[primes[i]]++;
                }
            }
        }
        F0R(i, 5000) {
            F0R(j, counts[i]) {
                seqs[x].pb(i);
            }
        }
    }

    ll data[5001]; F0R(i, 5001) data[i] = 0;
    int N; cin >> N;
    //int N = 1000000;
    F0R(i, N) {
        int X; 
        cin >> X; 
        /*if (i%2) {
            X = 0;
        } else {
            X = 5000;
        }*/
        data[X]++;
    }
    
    ll sum = 0;
    F0R(i, 5001) sum += sz(seqs[i]);

    F0R(i, 5001) reverse(all(seqs[i]));

    int mxLength = sz(seqs[5000]);

    ll ans = 0;
    vector<pair<vi, ll> > vals[mxLength+1];
    vi all; F0R(i, 5001) all.pb(i);
    vals[0].pb({all, 0});

    vi used;
    vector<vi> ex(5001);
    bool isUse[5001]; F0R(i, 5001) isUse[i] = false;
    F0R(pos, mxLength) {
        for (auto it = vals[pos].begin(); it != vals[pos].end(); it++) {
            vi curVec = it->f;
            ll curVal = it->s;

            F0R(i, sz(curVec)) {
                int cur = curVec[i];
                if (sz(seqs[cur]) == pos) continue;
                int nxt = seqs[cur][pos];
                used.pb(nxt);
                isUse[nxt] = true;
                ex[nxt].pb(cur);
            }

            F0R(i, sz(used)) {
                int cur = used[i];
                if (!isUse[cur]) continue;
                isUse[cur] = false;
                ll curCnt = 0;
                F0R(j, sz(ex[cur])) curCnt += data[ex[cur][j]];

                if (sz(ex[cur]) > 1) vals[pos+1].pb({ex[cur], curVal + curCnt});
                ll newVal = curVal + curCnt; newVal *= -2;
                newVal += ((ll) pos+1) * ((ll) N);
                ans = min(ans, newVal);
                if (sz(ex[cur]) == 1) {
                    ll cnt = data[ex[cur][0]];
                    ll len = sz(seqs[ex[cur][0]]);
                    
                    ans = min(ans, len*N - 2*curVal - 2*(len-pos)*cnt);
                }

                ex[cur].clear();
            }

            used.clear();

        }
    }


    F0R(i, 5001) {
        ans += data[i] * sz(seqs[i]);
    }

    cout << ans << endl;
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343