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
    const int MX = 10101; //check the limits, dummy
     
    vector<vi> graph;
    int subsize[MX];
    int spec[MX];
    int datas[4];
    int totalSize[4];
     
    int dfs(int v, int p) {
        spec[v] = -1;
        F0R(i, 4) if (v == datas[i]) spec[v] = i;
        int cur = 0;
        F0R(i, sz(graph[v])) {
            int nxt = graph[v][i];
            if (nxt == p) continue;
            cur += dfs(nxt, v);
            spec[v] = max(spec[v], spec[nxt]);
        }
        if (cur == 0) cur++;
        subsize[v] = cur;
        return cur;
    }
     
    bool possPos[MX][4];
     
    void computePoss(int p) {
        bool curPoss[MX];
        F0R(i, MX) curPoss[i] = false;
        curPoss[0] = true;
        int v = 0;
        F0R(i, sz(graph[0])) {
            if (spec[graph[0][i]] == p) v = graph[0][i];
        }
    //    cout << v << endl;
        int lst = 0;
        totalSize[p] = subsize[v];
        while (v != datas[p]) {
    //        cout << p << " " << v << " TEST" << endl;
     
    /*        F0R(i, 20) {
                cout << p << " " << v << " " << i << " " << (curPoss[i] ? "YES" : "NO") << endl;
            }*/
     
            F0R(i, sz(graph[v])) {
                int nxt = graph[v][i];
                if (nxt == lst) continue;
                if (spec[nxt] >= 0) continue;
    //            cout <<nxt << " " << " " << spec[7] << " " << subsize[nxt] << endl;
                F0Rd(j, MX) {
                    if (curPoss[j]) {
                        curPoss[j+subsize[nxt]] = true;
                    }
                }
            }
     
     
            F0R(i, sz(graph[v])) {
                int nxt = graph[v][i];
                if (nxt != lst && spec[nxt] == p) {
                    lst = v;
                    v = nxt;
                    break;
                }
            }
        }
        F0R(i, MX) {
            possPos[i][p] = curPoss[i];
        }
    }
     
    int main() {
    	ios_base::sync_with_stdio(0); cin.tie(0);    
        int N; cin >> N;
        F0R(i, N) {
            vi blank; graph.pb(blank);
        }
        F0R(i, 4) cin >> datas[i];
        F0R(i, 4) datas[i]--;
        FOR(i, 1, N) {
            int P; cin >> P; P--;
            graph[P].pb(i); graph[i].pb(P);
        }
     
        dfs(0, -1);
    /*    F0R(i, N) cout << spec[i] << " ";
        cout << endl;*/
     
        F0R(i, 4) computePoss(i);
     
        F0R(i, 4) {
            F0R(j, 20) {
    //            cout << i << " " << j << " " << (possPos[j][i] ? "YES" : "NO") << endl;
            }
        }
     
        bool possOne[MX], possTwo[MX];
        F0R(i, MX) possOne[i] = false, possTwo[i] = false;
        F0R(i, MX) {
            F0R(j, MX) {
                if (possPos[i][0] && possPos[j][1]) {
                    int val = totalSize[0] - i + j - 1;
                    possOne[val] = true;
                }
                if (possPos[i][2] && possPos[j][2]) {
                    int val = totalSize[2] - i + j - 1;
                    possTwo[val] = true;
                }
            }
        }
     
        F0Rd(i, MX) {
            if (possOne[i]) {
                possOne[i+totalSize[2]] = true;
            }
            possOne[i] = false;
        }
     
        F0Rd(i, MX) {
            if (possTwo[i]) {
                possTwo[i+totalSize[1]] = true;
            }
            possTwo[i] = false;
        }
     
        F0R(i, sz(graph[0])) {
            int nxt = graph[0][i];
            if (spec[nxt] >= 0) continue;
            F0Rd(j, MX) {
                if (possOne[j]) {
                    possOne[j+subsize[nxt]] = true;
                }
                if (possTwo[j]) {
                    possTwo[j + subsize[nxt]] = true;
                }
            }
        }
        
        int K = subsize[0] / 2;
        if (subsize[0] % 2) {
            cout << "NO" << endl; return 0;
        }
     
        cout << (possOne[K-1] && possTwo[K-1] ? "YES" : "NO") << endl;
    	
    	return 0;
    }
     
    // read the question correctly (ll vs int)
    // template by bqi343