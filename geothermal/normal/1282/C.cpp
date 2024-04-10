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
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    int M; cin >> M;
    while(M--) {
        ll N, T, A, B; cin >> N >> T >> A >> B;
        bool ishard[N]; F0R(i, N) {
            int cur; cin >> cur;
            ishard[i] = cur == 1;
        }
        vi easy, hard;
        F0R(i, N) {
            int X; cin >> X;
            if (ishard[i]) {
                hard.pb(X);

            } else {
                easy.pb(X);
            }
        }
        sort(all(easy));
        sort(all(hard));
        ll remTime = 0;
        ll lastTime = 0;
        ll pE = 0, pH = 0;
        ll ans = 0;
        vi times; F0R(i, sz(easy)) times.pb(easy[i]);
        F0R(i, sz(hard)) times.pb(hard[i]);
        sort(all(times));
        F0R(i, N) {
            ll curTime;
            bool useEasy = false;
            if ((pE != sz(easy)) && (pH == sz(hard) || easy[pE] < hard[pH])) {
                curTime = easy[pE];
                useEasy = true;
            } else {
                curTime = hard[pH];
            }
            ll curAns, countA, countB, curRem;
            if (curTime == 0) goto bad;
            if (i > 0 && times[i] == times[i-1]) goto bad;
            remTime = curTime - 1; 
            curAns = pE + pH;
            curRem = remTime - pE *A - pH * B;;
            if (curRem < 0) goto bad;
            countA = curRem/A;
            countA = min(countA, sz(easy) - pE);
            curRem -= countA * A;
            curAns += countA;
            countB = curRem/B;
            countB = min(countB, sz(hard) - pH);
            curRem -= countB*B;
            curAns += countB;
            ans = max(ans, curAns);
            bad:;


            remTime = curTime;
            if (useEasy) {
                lastTime = easy[pE];
                pE++;
            } else {
                lastTime = hard[pH];
                pH++;
            }
            if (i == N-1) {
                remTime = T; 
                curAns = pE + pH;
                curRem = remTime - pE * A - pH * B;
                if (curRem < 0) goto bad2;
                countA = curRem/A;
                countA = min(countA, sz(easy) - pE);
                curRem -= countA * A;
                curAns += countA;
                countB = curRem/B;
                countB = min(countB, sz(hard) - pH);
                curRem -= countB*B;
                curAns += countB;
                ans = max(ans, curAns);
                bad2:;
            }
        }

        cout << ans << endl;

    }
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343