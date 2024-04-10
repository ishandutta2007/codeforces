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

    int N, M; cin >> N >> M; int A, B; cin >> A >> B;
    ll G, X, Y, Z; cin >> G >> X >> Y >> Z;
    ll data[N][M];
    F0R(i, N) {
        F0R(j, M) {
            data[i][j] = G;
            G = (G*X+Y)%Z;
        }
    }

    ll slideRow[N][M-B+1];
    F0R(i, N) {
        priority_queue<pi> pq;
        F0R(j, B-1) {
            pq.push(mp(data[i][j] * -1, j));
        }
        FOR(j, B-1, M) {
            pq.push(mp(data[i][j] * -1, j));
            while (pq.top().s <= j-B) pq.pop();
            slideRow[i][j-B+1] = pq.top().f * -1;
        }
    }

    ll sum = 0;
    F0R(j, M-B+1) {
        priority_queue<pi> pq;
        F0R(i, A-1) {
            pq.push(mp(slideRow[i][j] * -1, i));
        }
        FOR(i, A-1, N) {
            pq.push(mp(slideRow[i][j] * -1, i));
            while (pq.top().s <= i-A) pq.pop();
            sum += pq.top().f * -1;
            //cout << pq.top().f * -1 << " ";
        }
        //cout << endl;
    }

    cout << sum << endl;

    /*ll table[N][M][14][14];
    F0R(i, N) {
        F0R(j, M) {
            F0R(k, 14) {
                F0R(l, 14) {
                    table[i][j][k][l] = 1000000000;
                }
            }
        }
    }
    F0R(X, N) {
        F0R(Y, M) {
            table[X][Y][0][0] = data[X][Y];
        }
        FOR(K, 1, 14) {
            for (int Y = 0; Y + (1 << K) < M; Y++) {
                table[X][Y][0][K] = min(table[X][Y][0][K-1], table[X][Y+(1<<K)][0][K-1]);
            }
        }
    }

    FOR(Kx, 1, 14) {
        for (int X = 0; X + (1 << Kx) < N; X++) {
            F0R(Ky, 14) {
                F0R(Y, M) {
                    table[X][Y][Kx][Ky] = min(table[X][Y][Kx-1][Y], table[X+(1<<Kx)][Y][Kx][Ky]);
                }
            }
        }
    }

    ll kA = log2(A);
    ll kB = log2(B);
    ll sum = 0;
    F0R(i, N-A+1) {
        F0R(j, M-B+1) {
            sum += min(table[X][Y][kA][kB], min(table[i+A-1-(1 << kA)][j][kA][kB], min(table[i][j+B-1-(1 << kB)][kA][kB], table[i+A-1-(1 << kA)][j+B-1-(1 << kB)][kA][kB])));
        }
    }

    cout << sum << endl;*/

    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343