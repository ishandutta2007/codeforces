#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
#include <bits/stdc++.h>
 
using namespace std;
 
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
 
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define trav(a,x) for (auto& a : x)
 
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const int MOD = 1000000007;
const char nl = '\n';
const int MX = 100001; //check the limits, dummy
 
const ll identity = 2e9;
const ll SZ = 131072*4;

ll sum[2*SZ], lazy[2*SZ];

ll combine(ll A, ll B) {
    return min(A, B);
}

ll combineUpd(ll A, ll B) {
    return A+B;
}

void push(int index, ll L, ll R) {
    sum[index] = combineUpd(sum[index], lazy[index]);
    if (L != R) lazy[2*index] = combineUpd(lazy[2*index], lazy[index]), lazy[2*index+1] = combineUpd(lazy[2*index+1], lazy[index]);
    lazy[index] = 0;
}

void pull(int index) {
    sum[index] = combine(sum[2*index], sum[2*index+1]);
}

ll query(int lo, int hi, int index = 1, ll L = 0, ll R = SZ-1) {
    push(index, L, R);
    if (lo > R || L > hi) return identity;
    if (lo <= L && R <= hi) return sum[index];

    int M = (L+R) / 2;
    return combine(query(lo, hi, 2*index, L, M), query(lo, hi, 2*index+1, M+1, R));
}

void update(int lo, int hi, ll increase, int index = 1, ll L = 0, ll R = SZ-1) {
    push(index, L, R);
    if (hi < L || R < lo) return;
    if (lo <= L && R <= hi) {
        lazy[index] = increase;
        push(index, L, R);
        return;
    }

    int M = (L+R) / 2;
    update(lo, hi, increase, 2*index, L, M); update(lo, hi, increase, 2*index+1, M+1, R);
    pull(index);
}

struct F {
    int T;
    ll cap;
    ll cost;
    int pos;
};

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    int T; cin >> T;
    F0R(i, 2*SZ) sum[i] = 0, lazy[i] = 0;
    while(T--) {
        int N, M, C, I; cin >> N >> M >> C >> I;
        vector<F> friends;
        friends.pb({0, I, 0, 0});
        friends.pb({M, 0, (ll) 1e9, 0});
//        set<int> times; times.ins(0); times.ins(M);
        F0R(i, N) {
            int X, Y, Z; cin >> X >> Y >> Z;
            friends.pb({X, Y, Z, 0});
//            times.ins(X);
        }

        multiset<pl> S;
        sort(all(friends), [](const F &a, const F &b) -> bool {return a.T < b.T; });
        N = sz(friends);
        ll cs = 0, ans = 0;
        F0R(i, N) {
            cs += friends[i].cap;
            S.ins({friends[i].cost, friends[i].cap});
            while (cs > C) {
                ll curCnt = S.rbegin()->s;
                ll curCost = S.rbegin()->f;
                if (curCnt > cs-C) {
                    S.erase(S.find(*S.rbegin()));
                    curCnt -= cs-C;
                    cs = C;
                    S.ins({curCost, curCnt});
                } else {
                    cs -= curCnt;
                    S.erase(S.find(*S.rbegin()));
                }
            }

            ll need = 0; if (i < N-1) need = friends[i+1].T - friends[i].T;
            while (need > 0) {
                if (cs == 0) {
                    cout << -1 << nl; goto done;
                }
                ll curCnt = S.begin()->s;
                ll curCost = S.begin()->f;
                if (curCnt > need) {
                    S.erase(S.begin());
                    curCnt -= need;
                    ans += need * curCost;
                    cs -= need;
                    need = 0;
                    S.ins({curCost, curCnt});
                } else {
                    need -= curCnt;
                    cs -= curCnt;
                    ans += curCnt * curCost;
                    S.erase(S.begin());
                }
            }
//            cout << cs << " " << i << nl;
        }
        cout << ans << nl;

        done:
        ;

/*        vi stimes; trav(a, times) stimes.pb(a);
        sort(all(stimes));
        FOR(i, 1, sz(stimes)) {
            update(i-1, sz(stimes) - 1, stimes[i-1] - stimes[i]);
        }
        map<int, int> tmap; F0R(i, sz(stimes)) tmap.ins({stimes[i], i});
        F0R(i, sz(friends)) {
            friends[i].pos = tmap[friends[i].T];
        }
        N = sz(friends);
        int ct = sz(stimes);

        sort(all(friends), [](const F &a, const F &b) -> bool {return a.cost < b.cost; });
        ll ans = 0;
        F0R(i, N) {
            ll prev = query(friends[i].pos, friends[i].pos);
            if (friends[i].pos < sz(stimes) - 1) {
                prev += stimes[friends[i].pos+1] - stimes[friends[i].pos];
            }
            if (friends[i].pos > 0) {
                prev += max(0ll, -query(0, friends[i].pos - 1));
            }
            //prev is current flow to this point


            ll needFlow = query(friends[i].pos, ct-1) * -1;
            if (friends[i].pos > 0) {
                needFlow -= max(0ll, -query(0, friends[i].pos-1)); //if we get more from others, decrease needed flow
            }
            ckmax(needFlow, 0ll);
            ll cur = needFlow;

            
            ckmin(cur, C - query(friends[i].pos, friends[i].pos) - prev); //can't go above cap
            ckmin(cur, friends[i].cap);

            cur = max(cur, 0ll); //can't push above zero



//            cout << cur << " " << friends[i].T << " " << friends[i].cost << nl;
            ans += cur * friends[i].cost;
            update(friends[i].pos, ct-1, cur);
        }
        F0R(i, ct) {
            cout << query(i, i) << " ";
        }
        cout << nl;
        if (query(0, ct-1) >= 0) {
            cout << ans << nl;
        } else {
            cout << -1 << nl;
        }
        F0R(i, ct) update(i, i, -query(i, i));*/

    }
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343