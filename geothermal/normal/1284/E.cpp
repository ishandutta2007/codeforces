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
const int MX = 2501; //check the limits, dummy
 
ll SZ = 4096;
ll* seg = new ll[2*SZ]; //segtree implementation by bqi343's Github


ll combine(ll a, ll b) { return a+b; }

void build() { F0Rd(i,SZ) seg[i] = combine(seg[2*i],seg[2*i+1]); }

void update(int p, ll value) {  
    for (seg[p += SZ] = value; p > 1; p >>= 1)
        seg[p>>1] = combine(seg[(p|1)^1], seg[p|1]);
}

ll query(int l, int r) {  // sum on interval [l, r]
    ll resL = 0, resR = 0; r++;
    for (l += SZ, r += SZ; l < r; l >>= 1, r >>= 1) {
        if (l&1) resL = combine(resL,seg[l++]);
        if (r&1) resR = combine(seg[--r],resR);
    }
    return combine(resL,resR);
}

ll total = 0;
ll value[MX][MX];
void solve(vector<pair<ld, pi> > *vals, int N, int root) {
    ll cur = 0;
/*    cout << root << endl;
    F0R(i, N) {
        cout << (*vals)[i].s.f << (*vals)[i].s.s << " ";
    }
    cout << endl;*/
    F0R(i, N) {
        update((*vals)[i].s.f, 1);
    }
    F0R(i, N) {
        update((*vals)[i].s.f, 0);
        ll q = query((*vals)[i].s.f, 4000);
        value[(*vals)[i].s.s][root] = q;
    }

}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    F0R(i, 2*SZ) seg[i] = 0;

    int N; cin >> N;
    vector<pd> data;
    ld co = cos(1 * acos(0) / 180), si = sin(1 * acos(0) / 180);
    F0R(i, N) {
        ld a, b; cin >> a >> b;
        ld x = a * co - b * si;
        ld y = b * co + a * si;
        data.pb({x, y});
    }

    ld countTris = 0;
    sort(all(data));

    vector<pair<ld, int> > used;
    int pos[N];
    F0R(i, N) {
        used.pb({data[i].s, i});
    }
    sort(all(used));
    F0R(i, N) {
        pos[used[i].s] = i;
    }
/*    F0R(i, N) {
        cout << i << " " << data[i].f << " " << data[i].s << " " << pos[i] << endl;
    }*/
    F0R(root, N) {
        vector<pair<ld, pi> > los;
        vector<pair<ld, pi> > his;
        F0R(i, N) {
            if (i == root) continue;
            pd cur = data[i];
            bool low = false;
            if (data[i].s < data[root].s) {
                cur = {data[i].f, 2*data[root].s-data[i].s};
                low = true;
            }

            ld angle = (cur.f-data[root].f)/(cur.s-data[root].s);
            if (low) {
                los.pb({angle, {N-pos[i], i}});
            } else {
                his.pb({angle, {pos[i], i}});
            }
        }
        sort(all(los));
//        reverse(all(los));
        sort(all(his));
//        reverse(all(his));
        solve(&los, sz(los), root);
//        cout << root << " " << total << endl;
        solve(&his, sz(his), root);
//        cout << root << " " << total << endl;
    }
    
/*    ans += (total * (total - 1)) / 2;*/

    ll ans = 0;
    F0R(i, N) {
        ll total = 0;
        F0R(j, N) {
            total += value[i][j] * (N-3);
//            cout << i << " " << j << " " << value[i][j] << endl;
            ll V = value[i][j];
            ans -= (V * (V-1)) ;
        }
        total /= 2; ans += total;
    }
    cout << (ans * (N-4)) / 2 << endl;
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343