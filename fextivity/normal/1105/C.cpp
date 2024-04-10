#include<bits/stdc++.h>
using namespace std;

// Shortcut

#define int long long
#define ld long double
#define endl '\n'
#define pb push_back
#define pob pop_back
#define mp make_pair
#define upb upper_bound
#define lwb lower_bound
#define fi first
#define se second
#define For(i, l, r) for (int i = l; i < r; i++)
#define ForE(i, l, r) for (int i = l; i <= r; i++)
#define Ford(i, r, l) for (int i = r; i > l; i--)
#define FordE(i, r, l) for (int i = r; i >= l; i--)
#define Fora(i, a) for (auto i : a)

// I/O & Debug

#define PrintV(a) for (int i = 0; i < a.size(); i++) cout << a[i] << ' ';
#define PrintVl(a) for (int i = 0; i < a.size(); i++) cout << a[i] << endl;
#define PrintA(a, n) for (int i = 0; i < n; i++) cout << a[i] << ' ';
#define PrintAl(a, n) for (int i = 0; i < n; i++) cout << a[i] << endl;
#define Ptest(x) return cout << x, 0;
#define gl(s) getline(cin, s);
#define setpre(x) fixed << setprecision(x)
#define debug(args...){ string _sDEB = #args; replace(_sDEB.begin(), _sDEB.end(), ',', ' '); stringstream _ssDEB(_sDEB); istream_iterator<string> _itDEB(_ssDEB); DEB(_itDEB, args); }
void DEB(istream_iterator<string> it) {}
template<typename T, typename... Args>
void DEB(istream_iterator<string> it, T a, Args... args){
	cout << *it << " = " << a << endl;
	DEB(++it, args...);
}

// Functions

#define bend(a) a.begin(),a.end()
#define mset(a) memset(a, 0, sizeof(a));
#define sortV(a) sort(bend(a));
#define sortA(a, n) sort(a, a + n);
#define rev(s) reverse(bend(a));

// Data Structure

#define pque priority_queue
#define mts multiset
typedef vector <int> vi;
typedef pair <int, int> ii;
typedef vector <vi > vvi;
typedef vector <ii > vii;

const int N = 2e5 + 5, mod = 1e9 + 7, inf = 1e18 + 7;

int dp[N][3];

int cm0(int l, int r){
    while (l % 3 != 0) l++;
    while (r % 3 != 0 && r >= l) r--;
    if (r < l) return 0;
    return (r - l) / 3 + 1;
}

int cm1(int l, int r){
    while (l % 3 != 1) l++;
    while (r % 3 != 1 && r >= l) r--;
    if (r < l) return 0;
    return (r - l) / 3 + 1;
}

int cm2(int l, int r){
    while (l % 3 != 2) l++;
    while (r % 3 != 2 && r >= l) r--;
    if (r < l) return 0;
    return (r - l) / 3 + 1;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, l, r;
    cin >> n >> l >> r;
    int m0 = max(cm0(l, r), 0ll), m1 = max(cm1(l, r), 0ll), m2 = max(cm2(l, r), 0ll);
    if (n == 1) Ptest(m0);
    dp[1][0] = m0;
    dp[1][1] = m1;
    dp[1][2] = m2;
    ForE(i, 2, n){
        dp[i][0] = ((dp[i - 1][0] * m0) % mod + (dp[i - 1][1] * m2) % mod + (dp[i - 1][2] * m1) % mod) % mod;
        dp[i][1] = ((dp[i - 1][0] * m1) % mod + (dp[i - 1][1] * m0) % mod + (dp[i - 1][2] * m2) % mod) % mod;
        dp[i][2] = ((dp[i - 1][0] * m2) % mod + (dp[i - 1][1] * m1) % mod + (dp[i - 1][2] * m0) % mod) % mod;
    }
    if (dp[n][0] < 0) dp[n][0] += mod;
    cout << dp[n][0];
}

/*
----------------------------------+
INPUT:                            |
==============================    |

==============================    |
----------------------------------+
OUTPUT:                           |
==============================    |

==============================    |
----------------------------------+
*/