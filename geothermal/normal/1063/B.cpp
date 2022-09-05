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
#define shandom_ruffle random_shuffle

const int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 100001; //check the limits, dummy

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int N; int M; cin >> M >> N;

    int A, B; cin >> B >> A;

    A--; B--;

    int X, Y; cin >> X >> Y;

    vi compY;
    vpi compX;

    bool data[N][M];
    int comp[N][M];
    F0R(j, M) {
        F0R(i, N) {
            char C; cin >> C;
            data[i][j] = C == '*';
        }
    }



    //can move through Y freely

    int nxtComp = 0;
    F0R(i, N) {
        int start = 0;
        F0R(j, M) {
            comp[i][j] = nxtComp;
            if (data[i][j]) {
                comp[i][j] = -1;
                if (start == j) {
                    start++; continue;
                }

                compY.pb(i);
                compX.pb(mp(start, j-1));

                nxtComp++;
                start = j+1;
            }
        }
        if (!data[i][M-1]) {
            compY.pb( i);
            compX.pb(mp(start, M-1));

            nxtComp++;
        }

    }

    pi dist[nxtComp];
    F0R(i, nxtComp) {
        dist[i] = mp(1000000001, 1000000001);
    }
    dist[comp[A][B]] = mp(0, 0);

    //priority_queue<pair<pi, int>, vector<pair<pi, int> >, greater<pair<pi, int>>> q;

    //q.push(mp(mp(0, 0), comp[A][B]));

    queue<int> q; q.push(comp[A][B]);

    bool found[nxtComp]; F0R(i, nxtComp) found[i] = false;

    found[comp[A][B]] = true;

    while (!q.empty()) {

        int curC = q.front();
        pi curW = dist[curC];
        q.pop();
        //if (found[curC]) continue;
        //found[curC] = true;
        //dist[curC] = curW;



        int curY = compY[curC];
        FOR(i, compX[curC].f, compX[curC].s+1) {
            if (curY > 0 && comp[curY-1][i] != -1 && !found[comp[curY-1][i]]) {
                int nxt = comp[curY-1][i];
                q.push(nxt);
                dist[nxt] = mp(curW.f+1, curW.s);
                found[nxt] = true;
                //used.insert(comp[curY-1][i]);
                //q.push(mp(mp(curW.f+1, curW.s), comp[curY-1][i]));
            }
            if (curY < N-1 && comp[curY+1][i] != -1 && !found[comp[curY+1][i]]) {

                int nxt = comp[curY+1][i];
                q.push(nxt);
                dist[nxt] = mp(curW.f, curW.s+1);
                found[nxt] = true;
                //used.insert(comp[curY+1][i]);
                //q.push(mp(mp(curW.f, curW.s+1), comp[curY+1][i]));

            }
        }

    }

    int ans = 0;
    F0R(i, nxtComp) {
        if (dist[i].f <= X && dist[i].s <= Y) {
            ans += compX[i].s - compX[i].f + 1;
        }
    }

    cout << ans << endl;

    /*F0R(i, nxtComp) {
        cout << "comp " << i << " has y " << compY[i] << " and X's " << compX[i].f << " " << compX[i].s << endl;
        cout << "distance is " << dist[i].f << " " << dist[i].s << endl;
    }*/



    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343
// license: https://github.com/bqi343/USACO/blob/master/LICENSE