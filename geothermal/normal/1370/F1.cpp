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
struct CentroidDecomposition {
	vector<set<int>> tree; // it's not vector<vector<int>>!
	vector<int> dad;
	vector<int> sub;

	CentroidDecomposition(vector<set<int>> &tree, int v) : tree(tree) {
		int n = tree.size();
		dad.resize(n);
		sub.resize(n);
		build(v, -1);
	}

	void build(int u, int p) {
		int n = dfs(u, p); // find the size of each subtree
		int centroid = dfs(u, p, n); // find the centroid
		if (p == -1) p = centroid; // dad of root is the root itself
		dad[centroid] = p;
		// for each tree resulting from the removal of the centroid
        while (!tree[centroid].empty()) {
            int v = *(tree[centroid].begin());
			tree[centroid].erase(v); // remove the edge to disconnect
			tree[v].erase(centroid); // the component from the tree
			build(v, centroid);
        }

	}

	int dfs(int u, int p) {
		sub[u] = 1;

		for (auto v : tree[u])
			if (v != p) sub[u] += dfs(v, u);

		return sub[u];
	}

	int dfs(int u, int p, int n) {
		for (auto v : tree[u])
			if (v != p and sub[v] * 2 > n) return dfs(v, u, n);

		return u;
	}

	int operator[](int i) {
		return dad[i];
	}
};

pi query(vi A) {
    if (sz(A) == 0) return {0, 0};
    cout << "? " << sz(A) << " ";
    F0R(i, sz(A)) {
        cout << A[i]+1 << " ";
    }
    cout << endl;
    int X, Y; cin >> X >> Y;
    return {X-1, Y};
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
    int T; cin >> T;
    while (T--) {

        int N; cin >> N;
        vector<set<int> > graph(N);
        F0R(i, N-1) {
            int X, Y; cin >> X >> Y; X--; Y--;
            graph[X].ins(Y);
            graph[Y].ins(X);
        }
        vector<set<int> > ograph = graph;
        CentroidDecomposition cd(graph, 0);

        vi Q;
        F0R(i, N) if (cd.dad[i] != i) Q.pb(i);
        int cent;
        F0R(i, N) if (cd.dad[i] == i) cent = i;
        pi res = query(Q);
        if (res.f < 0) return 0;

        int dist = res.s;
        int cur = res.f;

        queue<int> q;
        bool vis[N]; F0R(i, N) vis[i] = false;
        int lst;
        vis[cur] = true;
        q.push(cur);
        while (!q.empty()) {
            int X = q.front(); q.pop();
            trav(a, graph[X]) {
                if (a == cent) {
                    lst = X;
                } else {
                    if (!vis[a]) {
                        vis[a] = true; q.push(a);
                    }
                }
            }
        }
        if (graph[lst].count(cent)) graph[lst].erase(cent);

        cd = CentroidDecomposition(graph, lst);
        F0R(i, N) if (vis[i] && cd.dad[i] == i) cur = i;
        int ans;
        while (true) {
//            cout << cur << endl;

            bool in[N], bad[N];
            F0R(i, N) {
                in[i] = false; bad[i] = false;
            }
            Q.clear();
            queue<int> q;
            q.push(cur);
            in[cur] = true;
            while (!q.empty()) {
                int X = q.front(); q.pop();
                trav(a, graph[X]) {
                    if (!in[a]) {
                        in[a] = true; q.push(a);
                    }
                }
            }
            int coIn = 0;
            F0R(i, N) if (in[i]) coIn++;
/*            F0R(i, N) if (in[i]) cout << i+1 << " ";
            cout << endl;*/
            if (coIn == 1) {
                ans = cur; break;
            }

            bad[lst] = true;
            if (lst != cur) q.push(lst);
            int bpar;
            while (!q.empty()) {
                int X = q.front(); q.pop();
                trav(a, graph[X]) {
                    if (!bad[a]) {
                        bad[a] = true;
                        if (a == cur) {
                            bpar = X;
                        } else {
                            q.push(a);
                        }
                    }
                }
            }

            F0R(i, N) {
                if (in[i] && !bad[i]) {
                    Q.pb(i);
                }
            }


            if (sz(Q) == 0) Q.pb(cur);
            res = query(Q);
            if (res.f < 0) {
                return 0;
            }
//            cout << coIn << endl;
            if (coIn == 2) {
                if (res.s == dist) {
                    ans = res.f; 
                } else {
                    F0R(i, N) {
                        if (in[i] && i != res.f) {
                            ans = i; 
                        }
                    }
                }
                break;
            }

            if (res.s == dist) {
                //cut off all other segments
                F0R(i, N) vis[i] = false;
                vis[res.f] = true;
                q.push(res.f);

                while (!q.empty()) {
                    int X = q.front(); q.pop();
                    trav(a, graph[X]) {
                        if (a == cur) {
                            lst = X;
                        } else {
                            if (!vis[a]) { vis[a] = true; q.push(a); }
                        }
                    }
                }
                graph[lst].erase(cur);
            } else {
                F0R(i, N) {
                    if (i != bpar) graph[cur].erase(i);
                }

                F0R(i, N) vis[i] = false;
                vis[cur] = true;
                q.push(cur);
                while (!q.empty()) {
                    int X = q.front(); q.pop();
                    trav(a, graph[X]) {
                        if (!vis[a]) {vis[a] = true; q.push(a);}
                    }
                }

            }

            CentroidDecomposition ncd(graph, lst);
/*            cout << cur << " " << bpar << endl;
            cout << sz(graph[cur]) << endl;*/
            F0R(i, N) if (vis[i] && ncd.dad[i] == i) cur = i;
//            cout << lst << " " << cur << endl;
/*            if (lst == 1 && cur == 8) {
                cout << ncd.dad[1] << " " << ncd.dad[8] << " " << ncd.dad[2] << " " << vis[1] << endl;
            }*/

        }

        int D[N]; F0R(i, N) D[i] = -1;
        D[ans] = 0;
        q.push(ans);
        while (!q.empty()) {
            int X = q.front(); q.pop();
            trav(a, ograph[X]) {
                if (D[a] == -1) {
                    D[a] = D[X] + 1;
                    q.push(a);
                }
            }
        }
/*        F0R(i, N) {
            cout << D[i] << " ";
        }
        cout << endl;*/
        Q.clear();
        F0R(i, N) {
            if (D[i] == dist) {
                Q.pb(i);
            }
        }
        pi finalVal = query(Q);
        if (finalVal.f < 0) {
            return 0;
        }

        cout << "! " << ans+1 << " " << finalVal.f+1 << endl;

        string S; cin >> S;
        if (S != "Correct") {
            return 0;
        }
    }
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343