// read the question correctly (ll vs int)
// template by bqi343

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

int N, M;
vector<bool> all[2];
map<string, int> numbering;
vector<bool> data[5001][2];
vector<bool> parse(string S, bool one) {
    if (S == "?") {
        if (one) {
            return all[1];
        } else return all[0];
    } else if (numbering.count(S)) {
        if (one) {
            return data[numbering[S]][1];
        } else {
            return data[numbering[S]][0];
        }
    }
    vector<bool> res;
    F0R(i, M) res.pb(S[i] == '1');
    return res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> N >> M;


    F0R(i, M) { all[0].pb(false); all[1].pb(true); }
    string ignore; getline(cin, ignore);
    F0R(i, N) {
        string line;
        getline(cin, line);
        stringstream input(line);
        string name; input >> name;
        input >> ignore;
        string numOne; input >> numOne;
        string op = ""; input >> op;
        vector<bool> res[2];
        if (op == "AND") {
            string numTwo; input >> numTwo;
            vector<bool> words[2];
            words[0] = parse(numOne, false);
            words[1] = parse(numTwo, false);
            F0R(j, M) {
                res[0].pb(words[0][j] && words[1][j]);
            }

            words[0] = parse(numOne, true);
            words[1] = parse(numTwo, true);
            F0R(j, M) {
                res[1].pb(words[0][j] && words[1][j]);
            }
        } else if (op == "XOR") {
            string numTwo; input >> numTwo;
            vector<bool> words[2];
            words[0] = parse(numOne, false);
            words[1] = parse(numTwo, false);
            F0R(j, M) {
                res[0].pb(words[0][j] ^ words[1][j]);
            }

            words[0] = parse(numOne, true);
            words[1] = parse(numTwo, true);
            F0R(j, M) {
                res[1].pb(words[0][j] ^ words[1][j]);
            }
        } else if (op == "OR") {
            string numTwo; input >> numTwo;
            vector<bool> words[2];
            words[0] = parse(numOne, false);
            words[1] = parse(numTwo, false);
            F0R(j, M) {
                res[0].pb(words[0][j] || words[1][j]);
            }

            words[0] = parse(numOne, true);
            words[1] = parse(numTwo, true);
            F0R(j, M) {
                res[1].pb(words[0][j] || words[1][j]);
            }
        } else {
            res[0] = parse(numOne, false);
            res[1] = parse(numOne, true);
        }

        numbering.insert(mp(name, i));
        data[i][0] = res[0]; data[i][1] = res[1];

    }

    vector<bool> ans[2];
    F0R(i, M) {
        int count[2]; count[0] = 0; count[1] = 0;
        F0R(j, N) {
            if (data[j][0][i]) count[0]++;
            if (data[j][1][i]) count[1]++;
        }
        if (count[0] < count[1]) {
            ans[0].pb(false);
            ans[1].pb(true);
        } else if (count[1] < count[0]) {
            ans[1].pb(false);
            ans[0].pb(true);
        } else {
            ans[0].pb(false);
            ans[1].pb(false);
        }
    }

    F0R(i, M) {
        if (ans[0][i]) {
            cout << 1;
        } else cout << 0;
    }
    cout << endl;
    F0R(i, M) {
        if (ans[1][i]) {
            cout << 1;
        } else cout << 0;
    }
    cout << endl;

    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343