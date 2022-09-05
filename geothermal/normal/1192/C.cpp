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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MOD = 998244353;
const ll INF = 1e18;
const int MX = 100001; //check the limits, dummy

vector<string> data;

int getMul(int A, int B, int C, int D) {
    if (A == B && C == D && B != C) return 6;
    if (A == B && B == C && C == D) return 1;
    if (A == B && B == C && C != D) return 4;
    if (A != B && B == C && C == D) return 4;
    if (A != B && B != C && C != D) return 24;
    return 12;
}

int getMap(char C) {
    if (C >= 'a' && C <= 'z') {
        return C-'a';
    } else if (C >= 'A' && C <= 'Z') {
        return 26+C-'A';
    } else {
        return 52+C-'0';
    }
}

ll solve(int L) {
    int N = sz(data);
    ll count[64][64];
    F0R(i, 64) {
        F0R(j, 64) {
            count[i][j] = 0;
        }
    }

    F0R(i, N) {
        if (sz(data[i]) != L) continue;
        int A = getMap(data[i][0]);
        int B = getMap(data[i][L-1]);
        count[A][B]++;
        string S = data[i];
        reverse(all(S));
        if (S != data[i]) count[B][A]++;
    }

    ll ways[64][64][64];
    F0R(i, 64) {
        FOR(j, i, 64) {
            FOR(k, j, 64) {
                ways[i][j][k] = 0;
                F0R(l, 64) {
                    ll cur = 1;
                    cur *= count[l][i]; cur %= MOD;
                    cur *= count[l][j]; cur %= MOD;
                    cur *= count[l][k]; cur %= MOD;
                    ways[i][j][k] += cur; ways[i][j][k] %= MOD;
                }
            }
        }
    }

    ll ans = 0;

    F0R(i, 64) {
        FOR(j, i, 64) {
            FOR(k, j, 64) {
                FOR(l, k, 64) {
                    ll cur = 1;
                    cur *= ways[i][j][k]; cur %= MOD;
                    cur *= ways[i][j][l]; cur %= MOD;
                    cur *= ways[i][k][l]; cur %= MOD;
                    cur *= ways[j][k][l]; cur %= MOD;
                    cur *= getMul(i, j, k, l); cur %= MOD;
                    ans += cur; ans %= MOD;
                }
            }
        }
    }
    return ans;
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll ans = 0;
    int N; cin >> N;
    set<string> used;
    F0R(i, N) {
        string S; cin >> S;
        if (used.count(S)) continue;
        reverse(all(S));
        if (used.count(S)) continue;
        data.pb(S);
        used.insert(S);
    }

    FOR(i, 3, 11) {
        ans += solve(i);
        ans %= MOD;
    }

    cout << ans << endl;

    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343