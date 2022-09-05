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
const int MX = 1000001; //check the limits, dummy
vi type;
vector<vi> children;
vector<vector<bool> > childDefault;
bool startTrue[MX];
bool resInverted[MX];

bool startDFS(int v) {

    F0R(i, sz(children[v])) {
        childDefault[v].pb(startDFS(children[v][i]));
    }

    if (type[v] < 2) {
        return startTrue[v] = type[v];
    } else if (type[v] == 2) {
        return startTrue[v] = childDefault[v][0] & childDefault[v][1];
    } else if (type[v] == 3) {
        return startTrue[v] = childDefault[v][0] | childDefault[v][1];
    } else if (type[v] == 4) {
        return startTrue[v] = childDefault[v][0] ^ childDefault[v][1];
    } else {
        return startTrue[v] = !childDefault[v][0];
    }
}

void invDFS(int v) {
    if (type[v] < 2) {
        return;
    } else if (type[v] == 2) {
        if ((!childDefault[v][0] & childDefault[v][1]) != startTrue[v]) {
            resInverted[children[v][0]] = resInverted[v];
        } else {
            resInverted[children[v][0]] = startTrue[0];
        }

        if ((childDefault[v][0] & !childDefault[v][1]) != startTrue[v]) {
            resInverted[children[v][1]] = resInverted[v];
        } else {
            resInverted[children[v][1]] = startTrue[0];
        }
    } else if (type[v] == 3) {
        if ((!childDefault[v][0] | childDefault[v][1]) != startTrue[v]) {
            resInverted[children[v][0]] = resInverted[v];
        } else {
            resInverted[children[v][0]] = startTrue[0];
        }

        if ((childDefault[v][0] | !childDefault[v][1]) != startTrue[v]) {
            resInverted[children[v][1]] = resInverted[v];
        } else {
            resInverted[children[v][1]] = startTrue[0];
        }
    } else if (type[v] == 4) {
        if ((!childDefault[v][0] ^ childDefault[v][1]) != startTrue[v]) {
            resInverted[children[v][0]] = resInverted[v];
        } else {
            resInverted[children[v][0]] = startTrue[0];
        }

        if ((childDefault[v][0] ^ !childDefault[v][1]) != startTrue[v]) {
            resInverted[children[v][1]] = resInverted[v];
        } else {
            resInverted[children[v][1]] = startTrue[0];
        }
    } else {
        resInverted[children[v][0]] = resInverted[v];
    }

    F0R(i, sz(children[v])) {
        invDFS(children[v][i]);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int N; cin >> N;
    //0 = false, 1 = true, 2 = AND, 3 = OR, 4 = XOR, 5 = NOT
    children = vector<vi>(N);
    childDefault = vector<vector<bool> >(N);

    F0R(i, N) {
        string S; cin >> S;
        if (S == "IN") {
            int X; cin >> X;
            type.pb(X);
        } else if (S == "AND") {
            type.pb(2);
            int A, B; cin >> A >> B; A--; B--;
            children[i].pb(A); children[i].pb(B);
        } else if (S == "OR") {
            type.pb(3);
            int A, B; cin >> A >> B; A--; B--;
            children[i].pb(A); children[i].pb(B);
        } else if (S == "XOR") {
            type.pb(4);
            int A, B; cin >> A >> B; A--; B--;
            children[i].pb(A); children[i].pb(B);
        } else {
            type.pb(5);
            int A; cin >> A; A--;
            children[i].pb(A);
        }
    }

    startDFS(0);
    resInverted[0] = !startTrue[0];
    invDFS(0);
    F0R(i, N) {
        if (type[i] < 2) {
            int ans = resInverted[i] ? 1 : 0;
            cout << ans;
        }
    }

    cout << endl;

    F0R(i, N) {
        //cout << i << " " << resInverted[i] << endl;
    }

    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343