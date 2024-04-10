
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
    const int MX = 1000001; //check the limits, dummy
     
     
    const int identity = 0;
    const int SZ = 131072*8;
     
    int lo[2*SZ], hi[2*SZ], lazy[2*SZ];
     
    int combine(int A, int B) {
        return A+B;
    }
     
    int combineUpd(int A, int B) {
        return A+B;
    }
     
    void push(int index, int L, int R) {
        lo[index] += lazy[index];
        hi[index] += lazy[index];
        if (L != R) lazy[2*index] = combineUpd(lazy[2*index], lazy[index]), lazy[2*index+1] = combineUpd(lazy[2*index+1], lazy[index]);
        lazy[index] = 0;
    }
     
    void pull(int index) {
        lo[index] = min(lo[index*2], lo[index*2+1]);
        hi[index] = max(hi[index*2], hi[index*2+1]);
    }
     
    int queryMin(int low, int hih, int index = 1, int L = 0, int R = SZ-1) {
        push(index, L, R);
        if (low > R || L > hih) return 10000000;
        if (low <= L && R <= hih) return lo[index];
     
        int M = (L+R) / 2;
        return min(queryMin(low, hih, 2*index, L, M), queryMin(low, hih, 2*index+1, M+1, R));
    }
     
    int queryMax(int low, int hih, int index = 1, int L = 0, int R = SZ-1) {
        push(index, L, R);
        if (low > R || L > hih) return -10000000;
        if (low <= L && R <= hih) return hi[index];
     
        int M = (L+R) / 2;
        return max(queryMax(low, hih, 2*index, L, M), queryMax(low, hih, 2*index+1, M+1, R));
    }
     
    void update(int low, int hih, int increase, int index = 1, int L = 0, int R = SZ-1) {
        push(index, L, R);
        if (hih < L || R < low) return;
        if (low <= L && R <= hih) {
            lazy[index] = increase;
            push(index, L, R);
            return;
        }
     
        int M = (L+R) / 2;
        update(low, hih, increase, 2*index, L, M); update(low, hih, increase, 2*index+1, M+1, R);
        pull(index);
    }
     
    int main() {
    	ios_base::sync_with_stdio(0); cin.tie(0);    
    	
        int N; cin >> N;
        string S; cin >> S;
        
        int pos = 0;
        int cur[MX]; F0R(i, MX) cur[i] = 0;
        F0R(i, N) {
            if (S[i] == 'L') {
                pos--; pos = max(pos, 0);
            } else if (S[i] == 'R') {
                pos++;
            } else if (S[i] == '(') {
                update(pos, SZ-1, 1-cur[pos]);
                cur[pos] = 1;
            } else if (S[i] == ')') {
                update(pos, SZ-1, -1-cur[pos]);
                cur[pos] = -1;
            } else {
                update(pos, SZ-1, -1*cur[pos]);
                cur[pos] = 0;
            }
     
            if (queryMin(0, SZ-1) < 0 || queryMin(SZ-2, SZ-2) != 0) {
                cout << -1 << " ";
            } else {
                cout << queryMax(0, SZ-1) << " ";
            }
     
    /*        cout << "TEST OUTPUT" << endl;
            F0R(i, 10) {
                cout << queryMax(i, i) << " ";
            } cout << endl;*/
        }
        cout << endl;
     
     
    	return 0;
    }
     
    // read the question correctly (ll vs int)
    // template by bqi343