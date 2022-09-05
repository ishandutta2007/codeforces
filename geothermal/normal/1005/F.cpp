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

int N, M, K;
vector<vpi > graph;
vector<vi > backs;
vector<vi > answer;
int curCase = 0;
vi curAns;

void dfs(int cur) {
    if (cur == N) {
        answer.pb(curAns);
        K--;
        return;
    }

    F0R(i, sz(backs.at(cur))) {
        curAns.pb(backs.at(cur).at(i));
        dfs(cur+1);
        curAns.pop_back();
        if (K == 0) return;
    }

    return;

}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);



    cin >> N >> M >> K;

    F0R(i, N) {
        vpi blank; graph.pb(blank);
        vi blank2; backs.pb(blank2);
    }

    F0R(i, M) {
        int a, b; cin >> a >> b;
        a--; b--;
        graph.at(a).pb(mp(b, i));
        graph.at(b).pb(mp(a, i));
    }

    int dist[N];
    F0R(i, N) dist[i] = -1;
    dist[0] = 0;
    queue<int> q; q.push(0);
    while (!q.empty()) {
        int city = q.front();
        q.pop();
        int nextDist = dist[city] + 1;
        for (auto p : graph.at(city)) {
            int next = p.f; int road = p.s;
            if (dist[next] == -1) {
                dist[next] = nextDist;
                q.push(next);
            }
            if (dist[next] == nextDist) {
                backs.at(next).pb(road);
            }
        }
    }

    /*F0R(i, sz(backs)) {
        F0R(j, sz(backs.at(i))) {
            cout << backs.at(i).at(j);
        }
        cout << endl;
    }*/

    dfs(1);

    cout << sz(answer) << endl;

    F0R(i, sz(answer)) {
        sort(all(answer.at(i)));
        int curIndex = 0;
        F0R(j, M) {
            if (curIndex < sz(answer.at(i)) && answer.at(i).at(curIndex) == j) {
                cout << 1;
                curIndex++;
            } else {
                cout << 0;
            }
        }
        cout << endl;
    }

    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343