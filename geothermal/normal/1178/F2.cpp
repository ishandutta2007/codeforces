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
 
const int MOD = 998244353;
const ll INF = 1e18;
const int MX = 100001; //check the limits, dummy
 
ll SZ = 262144*4;
ll* seg = new ll[2*SZ]; //segtree implementation by bqi343's Github


ll combine(ll a, ll b) { return min(a, b); }

void build() { F0Rd(i,SZ) seg[i] = combine(seg[2*i],seg[2*i+1]); }

void update(int p, ll value) {  
    for (seg[p += SZ] = value; p > 1; p >>= 1)
        seg[p>>1] = combine(seg[(p|1)^1], seg[p|1]);
}

ll query(int l, int r) {  // sum on interval [l, r]
    ll resL = 10000, resR = 10000; r++;
    for (l += SZ, r += SZ; l < r; l >>= 1, r >>= 1) {
        if (l&1) resL = combine(resL,seg[l++]);
        if (r&1) resR = combine(seg[--r],resR);
    }
    return combine(resL,resR);
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    int N, M; cin >> N >> M;
    int data[M]; F0R(i, M) cin >> data[i];

    int first[N], last[N];
    F0R(i, N) first[i] = -1;

    F0R(i, M) {
        data[i]--;
        if (first[data[i]] == -1) {
            first[data[i]] = i;
        }
        last[data[i]] = i;
    }

    stack<int> curStack;
    F0R(i, M) {
        if (i == first[data[i]]) {
            if (!curStack.empty() && curStack.top() > data[i]) {
                cout << 0 << endl; return 0;
            }
            curStack.push(data[i]);
        }
        if (curStack.top() > data[i]) {
            cout << 0 << endl; return 0;
        }
        if (i == last[data[i]]) {
            if (curStack.empty() || curStack.top() != data[i]) {
                cout << 0 << endl; return 0;
            }
            curStack.pop();
        }
    }

    F0R(i, 2*SZ) {
        seg[i] = 100000;
    }
    F0R(i, M) {
        update(i, data[i]);
    }
    vector<vi> pos(N);
    F0R(i, M) {
        pos[data[i]].pb(i);
    }
    bool isRange[N][N];
    vector<pair<int, pi> > ranges;
    int nxtVal[N][N];
    F0R(i, N) {
        F0R(j, N) {
            auto it = lower_bound(all(pos[j]), first[i]);
            if (it == pos[j].end()) {
                nxtVal[i][j] = M+1;
            } else {
                nxtVal[i][j] = *it;
            }
        }
    }
    F0R(i, N) {
        F0R(j, N) {
            bool good = true;
            if (first[i] > first[j] || last[i] > last[j]) good = false;
            F0R(k, N) {
                if (!(last[k] < first[i] || last[j] < first[k] || (first[i] <= first[k] && last[k] <= last[j]) || (first[k] < first[i] && last[j] < last[k]))) {
                    good = false;
                }
                if (nxtVal[i][k] < last[j] && (first[k] < first[i] || last[k] > last[j])) {
                    //cout << i << " " << j << " bad with " << k << endl;
                    good = false;
                }
            }
            //if something contained in this range is also outside of it?
            
            isRange[i][j] = good;
            if (good) {
                ranges.pb({last[j]-first[i], {i, j}});
            }
        }
    }

    ll inner[N]; F0R(i, N) inner[i] = -1;
    ll dp[N][N];

    sort(all(ranges));
    F0R(index, sz(ranges)) {
        pi range = ranges[index].s;
        int beg = range.f, end = range.s;
        //cout << beg << " " << end << endl;
        int mindex = query(first[beg], last[end]);
        if (beg == mindex && end == mindex) {
            //compute inner product
            ll ans = 1;
            F0R(i, sz(pos[beg]) - 1) {
                int bInd = pos[beg][i];
                int eInd = pos[beg][i+1];
                if (bInd == eInd-1) continue;
                bInd = data[bInd+1];
                eInd = data[eInd-1];
                ans *= dp[bInd][eInd];
                ans %= MOD;
            }
            dp[beg][end] = ans;
            inner[beg] = ans;
        } else {
            ll ans = inner[mindex];
            ll begSum = 0, endSum = 0;
            int minB = first[mindex], maxB = last[mindex];
            if (beg == mindex) {
                begSum = 1;
            } else {
                begSum = dp[beg][data[minB-1]]*2;
            }
            if (end == mindex) {
                endSum = 1;
                
            } else {
                endSum = dp[data[maxB+1]][end]*2;
            }

            F0R(i, N) {
                if (i == beg || i == end) continue;
                if (first[i] > first[beg] && last[i] < first[mindex]) {
                    if(isRange[beg][data[first[i]-1]] && isRange[i][data[first[mindex]-1]]) {
                        begSum += dp[beg][data[first[i] - 1]] * dp[i][data[first[mindex]-1]];
                    }
                    begSum %= MOD;
                }
                if (first[i] > last[mindex] && last[i] < last[end]) {
                    if (isRange[data[last[mindex]+1]][i] && isRange[data[last[i]+1]][end]) {
                        endSum += dp[data[last[mindex]+1]][i] * dp[data[last[i]+1]][end];
                    }
                    endSum %= MOD;
                }
            }
            ans *= begSum; ans %= MOD;
            ans *= endSum; ans %= MOD;
            dp[beg][end] = ans;
        }
    }

    F0R(i, N) {
        F0R(j, N) {
            //if (isRange[i][j]) cout << i << " " << j << " " << dp[i][j] << endl; 
        }
    }

    cout << dp[data[0]][data[M-1]] << endl;
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343