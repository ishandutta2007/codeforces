#include <bits/stdc++.h>
// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/pb_ds/assoc_container.hpp>

using namespace std;
// using namespace __gnu_pbds;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
// template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

#define FOR(i, a, b) for (int i = a; i < int(b); i++)
#define F0R(i, a) for (int i = 0; i < int(a); i++)
#define F0Rd(i,a) for (int i = int(a)-1; i >= 0; i--)

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

const int MOD = 1000000007;
const double PI = 4*atan(1);

//C++ Template by GitHub user bqi343
//REMEMBER: REREAD THE PROBLEM, CHOOSE LL VS INT CAREFULLY

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin >> n;
    ll cap = 0;
    F0R(i, n) {
        ll j;
        cin >> j;
        cap += j;
    }

    ll a, b;
    a = 0; b = 0;
    F0R(i, n) {
        ll c;
        cin >> c;
        if (c > a) {
            ll d = c;
            c = a;
            a = d;
        }
        if (c > b) {
            b = c;
        }
    }
    if (a + b >= cap) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}