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

const int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 100001;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);


    int T;
    cin >> T;
    F0R(testNum, T) {
        int N; cin >> N;
        vector<vi> graph;
        int data[N];
        F0R(i, N) {
            cin >> data[i];
            vi blank; graph.pb(blank);
        }

        stack<pi> unprocessed;

        F0R(i, N) {

            while (!unprocessed.empty() && unprocessed.top().s == i) unprocessed.pop();
            if (unprocessed.empty() == false) {
                graph[i].pb(unprocessed.top().f);
            }
            int nxt = data[i]-1;
            if (nxt != -2) {
                if (nxt < N) {
                    graph[i].pb(nxt);
                }
                unprocessed.push(mp(i, nxt));
            }
        }

        vi sorted;
        queue<int> todo;
        int countIncoming[N]; F0R(i, N) countIncoming[i] = 0;
        F0R(i, N) {
            F0R(j, sz(graph[i])) {
                countIncoming[graph[i][j]]++;
            }
        }

        F0R(i, N) {
            if (countIncoming[i] == 0) todo.push(i);
        }

        while (!todo.empty()) {
            int cur = todo.front(); todo.pop();
            sorted.pb(cur);
            F0R(i, sz(graph[cur])) {
                int x = graph[cur][i];
                countIncoming[x]--;
                if (countIncoming[x]==0) todo.push(x);
            }
        }
        if (sz(sorted) != N) {
            cout << -1 << endl;

        } else {
            int ans[N];
            F0R(i, N) {
                ans[sorted[i]] = i+1;
            }
            F0R(i, N) {
                cout << ans[i] << " ";
            }
            cout << endl;
        }

    }


    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343