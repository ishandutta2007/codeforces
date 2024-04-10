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
    int T; cin >> T;
    while(T--) {
        vector<vi> data;
        int N; cin >> N;
        set<int> locs[N];
        map<pi, int> cnts;
        F0R(i, N-2) {
            int A, B, C; cin >> A >> B >> C;
            A--; B--; C--;
            locs[A].insert(i);
            locs[B].insert(i);
            locs[C].insert(i);
            vi cur; cur.pb(A); cur.pb(B); cur.pb(C);
            
            sort(all(cur));
            data.pb(cur);
            F0R(x, 3) {
                FOR(y, x+1, 3) {
                    cnts[{cur[x], cur[y]}]++;
                }
            }

        }

        queue<int> q;
        int aft[N], bef[N];
        F0R(i, N) {
            aft[i] = -1, bef[i] = -1;
        }
        F0R(i, N) {
            if (sz(locs[i]) == 1) {
                q.push(i);
            }
        }
        vi ans;
        while (!q.empty()) {
            int curRoot = q.front(); q.pop();
            if (sz(locs[curRoot]) == 0) continue;
            int curLoc = *locs[curRoot].begin();
            ans.pb(curLoc);
            int A, B;
            int found = 0;
            F0R(i, 3) {
                locs[data[curLoc][i]].erase(curLoc);
                if (sz(locs[data[curLoc][i]]) == 1) {
                    q.push(data[curLoc][i]);
                }
                int cur = data[curLoc][i];
                if (cur == curRoot) continue;
                if (found == 0) {
                    found++; A = cur;
                } else {
                    B = cur;
                }
            }


        }

        map<int, set<int> > edges;
        for (auto it = cnts.begin(); it != cnts.end(); it++) {
            if (it->s == 1) {
                int X = it->f.f;
                int Y = it->f.s;
                edges[X].insert(Y);
                edges[Y].insert(X);
            }
        }

        cout << 1 << " ";
        int nxt = *edges[0].begin();
        edges[0].erase(nxt); edges[nxt].erase(0);
        F0R(i, N-1) {
            cout << nxt+1 << " ";
            int nxt2 = *edges[nxt].begin();
            edges[nxt].erase(nxt2);
            edges[nxt2].erase(nxt);
            nxt = nxt2;
        }

        cout << endl;
        if (sz(ans) < N-2) return 0;
        F0R(i, N-2) {
            cout << ans[i]+1 << " ";
        }
        cout << endl;

/*        int root; F0R(i, N) if (sz(locs[i]) == 1) root = i;

        clock.pb(root);
        int rootPos = locs[root][0];
        int found = 0;
        vi ans; ans.pb(rootPos);
        F0R(i, 3) {
            if (data[rootPos][i] == root) continue;
            if (found == 0) {
                found++;
                clock.pb(data[rootPos][i]);
            } else {
                counter.pb(data[rootPos][i]);
            }
        }
        F0R(i, 3) {
            FOR(j, i+1, 3) {
                occurs[{data[rootPos][i], data[rootPos][j]}].erase(rootPos);
            }
        }

        F0R(i, N-3) {
            int A = clock[sz(clock) - 1];
            int B = counter[sz(counter) - 1];
            bool swapped = false;
            if (A > B) {
                swapped = true;
            swap(A, B); }
            int nxt = *occurs[{A, B}].begin();
            occurs[{A, B}].erase(nxt);

            int newVal; F0R(i, 3) if (data[nxt][i] != A && data[nxt][i] != B) newVal = data[nxt][i];
            cout << A << " " << B << " " << nxt << " " << newVal << endl;
            ans.pb(nxt);
            F0R(i, 3) {
                FOR(j, i+1, 3) {
                    occurs[{data[nxt][i], data[nxt][j]}].erase(nxt);
                }
            }
            int I = min(A, newVal);
            int J = max(A, newVal);
            if (occurs[{I, J}].size() > 0) {
                cout << i << " this happened" << endl;
                swapped = !swapped;
            } 
                if (swapped) {
                    counter.pb(newVal);
                } else {
                    clock.pb(newVal);
                }
           
        }

        F0R(i, sz(clock)) {
            cout << clock[i] + 1 << " ";
        }
        F0Rd(i, sz(counter)) {
            cout << counter[i] + 1 << " ";
        }
        cout << endl;
        F0R(i, sz(ans)) {
            cout << ans[i] +1 << " ";
        }
        cout << endl;*/




    }
    
        
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343