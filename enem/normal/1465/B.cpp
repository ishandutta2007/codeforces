// --------------------------------------------------<TEMPLATE>--------------------------------------------------
// ---------------<Headers and namespaces>----------------
#include <bits/stdc++.h>
using namespace std;

/*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
*/

// ---------------</Headers and namespaces>---------------
typedef long double LD;
typedef long long ll;

#define int ll
#define pb push_back
#define mp make_pair

#define all(v) v.begin(),v.end()

typedef map<int, int> mii;
typedef vector<int> vi;
typedef pair<int, int> pii;

// ------------------------<Consts>-----------------------
const int MAXN = 1000005;
const int SQRTN = 1003;
const int LOGN = 22;
const double PI = acos(-1);

#ifdef int
const int INF = 1e18;
#else
const int INF = 1e9;
#endif

const int MOD = 1e9 + 7;
const int FMOD = 998244353;
const double eps = 1e-9;
// -----------------------</Consts>-----------------------
//*//

//*//
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

void digits(int n, vi &v) {
    while (n > 1) {
        if (n % 10)
            v.pb(n % 10);
        n /= 10;
    }
    return;
}
void solvethetestcase() {
    int n;
    cin >> n;
    bool check = false ;

    while (!check) {
        vi v;
        digits(n, v);
        int j = 0;
        for (int i = 0; i < v.size(); i++) {
            if (n % v[i]) {
                n++;
                j++;
                break;
            }
        }
        if (j == 0)
            check = true;

    }
    cout << n << "\n";

}


signed main() {
#ifndef ONLINE_JUDGE
    freopen("input1.txt", "r", stdin);
// for getting input frm input1.txt
    freopen("output1.txt", "w", stdout);
// for getting output frm output1.txt
#else
#endif

    // comment when using scanf,printf
    FAST_IO
    int t = 1;
    // (UNCOMMENT FOR MULTIPLE TEST CASES)
    cin >> t;

    for (int i = 0; i < t; i++) {
        solvethetestcase();
    }
}