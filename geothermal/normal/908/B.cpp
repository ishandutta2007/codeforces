#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
//template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

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

//READ THE PROBLEM!
//ll or int?

//Template contributed by GitHub user bqi343


int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);

    int n, m;
    cin >> n >> m;
    bool wall[n][m];
    int sX, sY, eX, eY;
    F0R(i, n) {
        string s;
        cin >> s;
        F0R(j, m) {
            wall[i][j] = false;
            char c = s.at(j);
            if (c == '#') {
                wall[i][j] = true;
            } else if (c == 'S') {
                sX = i;
                sY = j;
            } else if (c == 'E') {
                eX = i;
                eY = j;
            }
        }
    }

    vector<int> perm;
    perm.pb(0);
    perm.pb(1);
    perm.pb(2);
    perm.pb(3);

    string coms; cin >> coms;
    int num = 0;
    F0R(cur, 24) {
        //cout << "Trying " << perm.at(0) << perm.at(1) << perm.at(2) << perm.at(3) << endl;
        int robX = sX, robY = sY;
        F0R(i, coms.length()) {
            int command = perm.at(coms.at(i) - '0');
            if (command == 0) {
                robX++;
            } else if (command == 1) {
                robX--;
            } else if (command == 2) {
                robY++;
            } else {
                robY--;
            }
            //cout << "At " << robX << " " << robY << " after " << i << endl;

            if (robX < 0 || robY < 0 || robX >= n || robY >= m || wall[robX][robY]) {
                //cout << "BAD" << endl;
                break;
            } else if (robX == eX && robY == eY) {
                //cout << "GOOD" << endl;
                num++;
                break;
            }
        }
        next_permutation(perm.begin(), perm.end());
    }

    cout << num << endl;

	return 0;
}