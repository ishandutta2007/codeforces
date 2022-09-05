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

struct node {
    int L1, L2, R1, R2;
    bool Lt, Rt;
    int A1, A2;
    int S;

};
const node LP = {1, 0, 1, 0, true, true, 1, 1, 1};
const node RP = {1, 0, 1, 0, false, false, 1, 1, 1};
const node identity = {-1, -1, -1, -1, false, false, -1, -1, -1};
const ll SZ = 131072*4;

node sum[2*SZ]; 
bool lazy[2*SZ];
void print(node X) {
    cout << "Runs: " << X.L1 << " " << X.L2 << " " << X.R1 << " " << X.R2 << nl;
    cout << "Types: " << X.Lt << " " << X.Rt << nl;
    cout << "Ans: " << X.A1 << " " << X.A2 << nl;
    cout << "Size: " << X.S << nl;
}

node combine(node A, node B) {
    if (A.L1 < 0) return B;
    if (B.L1 < 0) return A;
    node res;
    res.Lt = A.Lt;
    res.Rt = B.Rt;
    if (A.L1 == A.S) {
        if (A.Lt == B.Lt) {
            res.L1 = A.L1 + B.L1;
            res.L2 = B.L2;
        } else {
            res.L1 = A.L1;
            res.L2 = B.L1;
        }
    } else if (A.L1 + A.L2 == A.S) {
        res.L1 = A.L1;
        res.L2 = A.L2;
        if (A.Lt != B.Lt) res.L2 += B.L1;
    } else {
        res.L1 = A.L1;
        res.L2 = A.L2;
    }

    if (B.R1 == B.S) {
        if (B.Rt == A.Rt) {
            res.R1 = B.R1 + A.R1;
            res.R2 = A.R2;
        } else {
            res.R1 = B.R1;
            res.R2 = A.R1;
        }
    } else if (B.R1 + B.R2 == B.S) {
        res.R1 = B.R1;
        res.R2 = B.R2;
        if (B.Rt != A.Rt) res.R2 += A.R1;
    } else {
        res.R1 = B.R1;
        res.R2 = B.R2;
    }

    res.S = A.S + B.S;

    res.A1 = max(A.A1, B.A1);
    res.A2 = max(A.A2, B.A2);

    if (A.Rt != B.Lt) {
        if (A.Rt) {
            ckmax(res.A1, A.R1 + B.L1);
        } else {
            ckmax(res.A2, A.R1 + B.L1);
        } 
    } else {
        if (A.Rt) {
            ckmax(res.A2, A.R1 + A.R2 + B.L1);
            ckmax(res.A1, A.R1 + B.L1 + B.L2);
        } else {
            ckmax(res.A1, A.R1 + A.R2 + B.L1);
            ckmax(res.A2, A.R1 + B.L1 + B.L2);

        }
    }
/*    if (res.R2 > 10 || res.R2 < 0) {
        cout << "NODE A" << nl;
        print(A);
        cout << "NODE B" << nl;
        print(B);
        cout << "RESULT" << nl;
        print(res);
    }*/
    return res;
}


node flip(node A) {
    if (A.L1 < 0) return A;
    A.Lt = !A.Lt;
    A.Rt = !A.Rt;
    swap(A.A1, A.A2);
    return A;
}

void push(int index, ll L, ll R) {
    if (lazy[index]) {
        sum[index] = flip(sum[index]);
    }
    if (L != R && lazy[index]) lazy[2*index] = !lazy[2*index], lazy[2*index+1] = !lazy[2*index+1];
    lazy[index] = false;
}

void pull(int index) {
    sum[index] = combine(sum[2*index], sum[2*index+1]);
}

node query(int lo, int hi, int index = 1, ll L = 0, ll R = SZ-1) {
    push(index, L, R);
    if (lo > R || L > hi) return identity;
    if (lo <= L && R <= hi) return sum[index];

    int M = (L+R) / 2;
    return combine(query(lo, hi, 2*index, L, M), query(lo, hi, 2*index+1, M+1, R));
}

void update(int lo, int hi, int index = 1, ll L = 0, ll R = SZ-1) {
    push(index, L, R);
    if (hi < L || R < lo) return;
    if (lo <= L && R <= hi) {
        lazy[index] = !lazy[index];
        push(index, L, R);
        return;
    }

    int M = (L+R) / 2;
    update(lo, hi, 2*index, L, M); update(lo, hi, 2*index+1, M+1, R);
    pull(index);
}

int solve(int lo, int hi) {
    update(lo, hi);
    node res = query(lo, hi);
    return res.A1;
}


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    int N, Q; cin >> N >> Q;
    string S; cin >> S;

    F0R(i, 2*SZ) lazy[i] = false;
    F0R(i, SZ) {
        sum[i+SZ] = identity;
    }
    F0R(i, N) {
        if (S[i] == '>') {
            sum[i+SZ] = LP;
        } else {
            sum[i+SZ] = RP;
        }
    }
    FORd(i, 1, SZ) {
        pull(i);
    }

    F0R(i, Q) {
        int L, R; cin >> L >> R; L--; R--;
        cout << solve(L, R) << nl;
    }

	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343