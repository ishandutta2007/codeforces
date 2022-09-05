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
	
    int N, K; cin >> N >> K;
    if (K == 1) {
        cout << "! 1" << endl; return 0;
    }

    bool found[N]; F0R(i, N) found[i] = false;
    int val[N];
    F0R(i, N-K+1) {
        cout << "? ";
        int used = 0;
        F0R(j, N) {
            if (!found[j]) {
                cout << j+1 << " ";
                used++;
            }
            if (used == K) break;
        }
        cout << endl;
        int P, V; cin >> P >> V; P--;
        found[P] = true;
        val[P] = V;
    }

    vpi poss;
    F0R(i, N) {
        if (found[i]) {
            poss.pb({val[i], i});
        }
    }
    sort(all(poss));
    vi imPos;
    F0R(i, N) {
        if (!found[i]) {
            imPos.pb(i);
        }
    }

    int status[N]; F0R(i, N) status[i] = -1;
    vector<vi> graph;
    F0R(i, N) {
        vi blank;
        graph.pb(blank);
    }
    if (sz(poss) >= K) {
        cout << "? ";
        F0R(i, K) {
            cout << poss[i].s+1 << " ";
        }
        cout << endl;
        int A, B; cin >> A >> B;
        F0R(i, K) {
            if (B == poss[i].f) {
                cout << "! " << i+1 << endl;
                return 0;
            }
        }
    }

    //once we know how many lowers were in the final query...
    int last = -1;
    int lastVal = 0;
    int lastPre = -1;
    set<int> use;
    F0R(i, K-sz(poss)) {
        use.insert(imPos[(i)%sz(imPos)]);
    }
    bool used[N]; F0R(i, N) used[i] = false;
    used[imPos[0]] = true;
    F0R(i, K-1) {
        cout << "? ";
        F0R(j, sz(poss)) {
            cout << poss[j].s+1 << " ";
        }
        int nxt;
        for (auto it = use.begin(); it != use.end(); it++) {
            cout << *it + 1 << " ";
        }
/*        F0R(j, K-sz(poss)) {
            cout << imPos[(i+j)%sz(imPos)]+1 << " ";
            nxt = imPos[(i+j)%sz(imPos)];
        }*/
        cout << endl;
        int A, B; cin >> A >> B;
        if (last == -1) {
            last = B;
        } else {
            int pre = lastPre;
            int nxt = lastVal;
            if (last == B) {
                graph[pre].pb(nxt); graph[nxt].pb(pre);
            } else if (last < B) { //added a higher
                status[pre] = 0;
                status[nxt] = 1;
            } else {
                status[pre] = 1;
                status[nxt] = 0;
            }

            last = B;
        }
        if (i == 0) {
            lastPre = imPos[0];
            lastVal = imPos[(K-sz(poss))%sz(imPos)];
            used[lastVal] = true;
            use.erase(lastPre);
            use.insert(lastVal);
        } else if (i != K-2) {
            F0R(k, sz(imPos)) {
                if (!used[imPos[k]]) {
                    F0R(j, sz(imPos)) {
                        if (used[imPos[j]] && use.count(imPos[j]) != use.count(imPos[k])) {
                            if (use.count(imPos[j])) {
                                use.erase(imPos[j]); use.insert(imPos[k]);
                                lastPre = imPos[j]; lastVal = imPos[k];
                            } else {
                                use.erase(imPos[k]); use.insert(imPos[j]);
                                lastPre = imPos[k]; lastVal = imPos[j];
                            }
                            used[imPos[k]] = true;
                            goto done;
                        }
                    }
                }
            }
            done:;
        }
    }

    queue<int> q;
    F0R(i, N) {
        if (status[i] != -1) {
            q.push(i);
        }
    }
    if (sz(q) == 0) {
        if (last == poss[0].f) {
            cout << "! 1" << endl;
        } else {
            cout << "! " << K << endl;
        }
        return 0;
    }
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        F0R(i, sz(graph[cur])) {
            int nxt = graph[cur][i];
            if (status[nxt] == -1) {
                status[nxt] = status[cur];
                q.push(nxt);
            }
        }
    }

    int j = K-2;
    int countLo = 0;
/*    F0R(i, K-sz(poss)) {
        if (status[imPos[(i+j)%sz(imPos)]] == 0) {
            countLo++;
        }
    }*/
    for (auto it = use.begin(); it != use.end(); it++) {
        if (status[*it] == 0) countLo++;
    }
    F0R(i, sz(poss)) {
        if (last == poss[i].f) {
            cout << "! " << countLo+1 << endl;
            return 0;
        } 
        countLo++;
    }
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343