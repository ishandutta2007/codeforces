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
	
    int N, M; cin >> N >> M;
    if (N == 1 && M == 1) {
       cout << "NO" << endl; return 0;
    } bool data[N][M]; F0R(i, N) F0R(j, M) {
        char C; cin >> C;
        data[i][j] = C == 'X';
    }

    int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

    queue<pi> q;

    int A, B; cin >> A >> B; A--; B--;
    bool found[N][M]; F0R(i, N) F0R(j, M) found[i][j] = false;
    found[A][B] = true;
    bool foundBad[N][M]; F0R(i, N) F0R(j, M) foundBad[i][j] = false;
    q.push({A, B});

    while (!q.empty()) {
        pi cur = q.front(); q.pop();
        int x = cur.f, y = cur.s;
        F0R(i, 4) {
            int X = x + dx[i], Y = y + dy[i];
            if (X < 0 || X >= N || Y < 0 || Y >= M) continue;
            if (data[X][Y]) {
                foundBad[X][Y] = true; continue;
            }
            if (found[X][Y]) continue;
            found[X][Y] = true;
            q.push({X, Y});
        }
    }

    int C, D; cin >> C >> D;
    C--;
    D--;
    int cnt = 0;
    F0R(i, 4) {
        int X = C + dx[i], Y = D + dy[i];
        if (X < 0 || X >= N || Y < 0 || Y >= M) continue;
        if (data[X][Y]) continue;
        cnt++;

    }
    if (abs(A-C) + abs(B-D) == 1) cnt++;
    if ((found[C][D] && cnt > 1) || foundBad[C][D]) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343