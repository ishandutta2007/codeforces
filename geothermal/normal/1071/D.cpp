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

const int loPrimes[7] = {2, 3, 5, 7, 11, 13, 17};
const int maxPows[7] = {20, 8, 5, 3, 2, 2, 2};
vl primePowers[7];
map<ll, vi> decompressBig;

vi primes, leastFac;
void compPrimes(int N) {
    N++;
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

vi decompress(ll N) {
    vi compression;
    F0R(i, 7) {
        compression.pb(N % maxPows[i]);
        N /= maxPows[i];
    }
    return compression;
}

ll compress(vi fac) {
    ll ans = 0;
    F0Rd(i, 7) {
        ans = ans * maxPows[i];
        ans = ans + fac[i];
    }
    return ans;
}

ll evaluate(vi fac) {
    ll ans = 1;
    F0R(i, 7) {
        ans = ans * primePowers[i][fac[i]];
    }

    return ans;
}

int countDivisors(vi fac) {
    int ans = 1;
    F0R(i, sz(fac)) ans = ans * (fac[i]+1);
    return ans;
}

ll compressBig(vi fac) {
	ll res = 0;
	F0R(i, sz(fac)) {
		res = res * 1000;
		res = res % MOD;
		res = res + fac[i];
		res = res % MOD;
	}
	if (!decompressBig.count(res)) decompressBig.insert(mp(res, fac));
	return res;
}

vi profile(int N) {
    vi ans;
    if (N != 1) {
        int last = leastFac[N];
        int count = 1;
        N /= last;
        while (N != 1) {
            int nxt = leastFac[N];
            if (nxt != last) {
                ans.pb(count);
                last = nxt;
                count = 0;
            }
            count++;
            N /= last;
        }
        ans.pb(count);
    }
    sort(all(ans));
    reverse(all(ans));
    FOR(i, sz(ans), 7) {
        ans.pb(0);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    compPrimes(1000000);

    F0R(i, 7) {
        primePowers[i].pb(1);
        F0R(j, maxPows[i] - 1) {
            primePowers[i].pb(primePowers[i][j] * loPrimes[i]);
        }
    }

    map<int, int> compressionTable;
    map<int, vi> ogVecs;
    map<int, int> divisors;
    vector<vi> graph;
    map<int, int> divisorCompress;
    int nxt = 0;
    int nextDivisors = 0;
    vi blank;
    F0R(i, 19200) {
        vi cur = decompress(i); int numDivs;
        F0R(i, 6) {
            if (cur[i] < cur[i+1]) goto bad;
        }
        if (evaluate(cur) > 1000000) goto bad;



        compressionTable.insert(mp(i, nxt));
        numDivs = countDivisors(cur);
        ogVecs.insert(mp(nxt, cur));
        if (!divisorCompress.count(numDivs)) {
            divisorCompress.insert(mp(numDivs, nextDivisors));
            nextDivisors++;
        }
        divisors.insert(mp(nxt, divisorCompress[numDivs]));

        graph.pb(blank);
        F0R(i, 7) {
            if (cur[i] > 0 && (i == 6 || cur[i] > cur[i+1])) {
                cur[i] -= 1;
                int res = compressionTable[(int) compress(cur)];
                cur[i]++;
                graph[nxt].pb(res);
                graph[res].pb(nxt);
            }
        }

        nxt++;
        bad:;
    }

    int earlyDistance[nxt][300];
    F0R(i, nxt) F0R(j, 300) earlyDistance[i][j] = 10000;
    F0R(root, nxt) {

        map<ll, int> vecDist;
        vi curVec = ogVecs[root];
        while (curVec.back() ==0) curVec.pop_back();
        earlyDistance[root][countDivisors(curVec)] = 0;
        vecDist.insert(mp(compressBig(curVec), 0));
        queue<int> q;
        q.push(compressBig(curVec));
        while (!q.empty()) {
        	ll compressed = q.front();
        	vi cur = decompressBig[compressed];
        	q.pop();
        	F0R(i, sz(cur)) {
        		if (i == 0 || cur[i] != cur[i-1]) {
        			cur[i]++;
        			ll val = compressBig(cur);
        			if (!vecDist.count(val)) {

        				int nDivs = countDivisors(cur);
        				if (nDivs >= 300) {cur[i]--; continue; }
        				vecDist.insert(mp(val, vecDist[compressed]+1));
        				if (earlyDistance[root][nDivs] == 10000) {
        					earlyDistance[root][nDivs] = vecDist[compressed]+1;
        				}
                        if (vecDist[compressed]+1 < 15) q.push(val);
        			}
        			cur[i]--;
        		}
        	}

            F0R(i, sz(cur)) {
                if (i == sz(cur)-1 || cur[i] != cur[i+1]) {
                    cur[i]--;
                    bool isZero = cur[i] == 0;
                    if (isZero) cur.pop_back();
                    ll val = compressBig(cur);
                    if (!vecDist.count(val)) {

                        int nDivs = countDivisors(cur);
                        if (nDivs >= 300) { if(isZero) {cur.pb(0); } cur[i]++; continue; }
                        vecDist.insert(mp(val, vecDist[compressed]+1));
                        if (earlyDistance[root][nDivs] == 10000) {
                            earlyDistance[root][nDivs] = vecDist[compressed]+1;
                        }
                        if (vecDist[compressed]+1 < 15) q.push(val);
                    }
                    if (isZero) cur.pb(0);
                    cur[i]++;
                }
            }
        	cur.pb(1);
			ll val = compressBig(cur);
			if (!vecDist.count(val)) {

				int nDivs = countDivisors(cur);
				if (nDivs >= 300) continue;
				vecDist.insert(mp(val, vecDist[compressed]+1));
				if (earlyDistance[root][nDivs] == 10000) {
					earlyDistance[root][nDivs] = vecDist[compressed]+1;
				}
				if (vecDist[compressed]+1 < 15) q.push(val);
			}

        }
    }

    int distance[nxt][nxt];

    F0R(i, nxt) F0R(j, nxt) distance[i][j] = earlyDistance[i][countDivisors(ogVecs[j])];


    F0R(i, nxt) {
        F0R(j, nxt) {
            FOR(k, 1, 300) {
                distance[i][j] = min(distance[i][j], earlyDistance[i][k] + earlyDistance[j][k]);
            }
        }
    }

    int tests; cin >> tests;
    F0R(testCase, tests) {
        int A, B; cin >> A >> B;
        vi profA = profile(A), profB = profile(B);
        int compA = compress(profA), compB = compress(profB);
        int X = compressionTable[compress(profile(A))], Y = compressionTable[compress(profile(B))];
        cout << distance[X][Y] << endl;
    }



    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343