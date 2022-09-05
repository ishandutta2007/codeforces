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
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
 
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
 

const int SZ = 131072;

vi id = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
vl sum[2*SZ]; vi lazy[2*SZ];

vl combine1(vl& A, vl& B) {
    vl res; F0R(i, 10) res.pb(A[i] + B[i]);
    return res;
}

vl combine2(vl& A, vi& B) {
    vl res(10);
    F0R(i, 10) {
        res[B[i]] += A[i];
    }
    return res;
}

vi combine3(vi& A, vi& B) {
    vi res(10);
    F0R(i, 10) {
        res[i] = B[A[i]];
    }
    return res;
}

void push(int index, ll L, ll R) {
    vl cur(10);
    F0R(i, 10) {
        cur[lazy[index][i]] += sum[index][i];
    }
    sum[index] = cur;
    if (L != R) {
        vi cur2(10, 0);
        F0R(i, 10) {
            cur2[i] = lazy[index][lazy[2*index][i]];
        }
        lazy[2*index] = cur2;
        F0R(i, 10) cur2[i] = 0;
        F0R(i, 10) {
            cur2[i] = lazy[index][lazy[2*index+1][i]];
        }
        lazy[2*index+1] = cur2;

        //lazy[2*index] = combine3(lazy[2*index], lazy[index]), lazy[2*index+1] = combine3(lazy[2*index+1], lazy[index]);
    }
    lazy[index] = id;
}

void pull(int index) {
    F0R(i, 10) sum[index][i] = sum[2*index][i] + sum[2*index+1][i];
}

vl query(int lo, int hi, int index = 1, ll L = 0, ll R = SZ-1) {
    push(index, L, R);
    if (lo > R || L > hi) return vl(10, 0);
    if (lo <= L && R <= hi) return sum[index];

    int M = (L+R) / 2;
    vl A = query(lo, hi, 2*index, L, M);
    vl B = query(lo, hi, 2*index+1, M+1, R);
    vl res; F0R(i, 10) res.pb(A[i] + B[i]);
    return res;
}

void update(int lo, int hi, int X, int Y, int index = 1, ll L = 0, ll R = SZ-1) {
    push(index, L, R);
    if (hi < L || R < lo) return;
    if (lo <= L && R <= hi) {
        lazy[index][X] = Y;
        push(index, L, R);
        return;
    }

    int M = (L+R) / 2;
    update(lo, hi, X, Y, 2*index, L, M); update(lo, hi, X, Y, 2*index+1, M+1, R);
    pull(index);
}


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    int N, Q; cin >> N >> Q;
    F0R(i, 2*SZ) {
        lazy[i] = id;
        sum[i] = vl(10, 0);
    }

    F0R(i, N) {
        int X; cin >> X;
        int cur = 1;
        while (X > 0) {
            sum[i+SZ][X%10] += cur;
            X /= 10;
            cur *= 10;
        }
    }
    FORd(i, 1, SZ) {
        pull(i);
    }

    while(Q--) {
        int T; cin >> T;
        int L, R; cin >> L >> R; L--; R--;
        if (T == 1) {
            int X, Y; cin >> X >> Y;
            update(L, R, X, Y);
        } else {
            vl val = query(L, R);
            ll ans = 0;
            F0R(i, 10) ans += val[i] * i;
            cout << ans << nl;
        }
/*        F0R(i, N) {
            vl val = query(i, i);
            ll ans = 0;
            F0R(i, 10) {
                ans += val[i] * i;

            }
//            cout << ans << " ";
        }*/
//        cout << nl;
    }
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343