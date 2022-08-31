// Awwawa! Dis cold yis ratten buy Pikachu!
#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
#define pi pair<int, int>
#define mod 1000000007
template<typename T> bool chkmin(T &a, T b){return (b < a) ? a = b, 1 : 0;}
template<typename T> bool chkmax(T &a, T b){return (b > a) ? a = b, 1 : 0;}
ll ksm(ll a, ll b) {if (b == 0) return 1; ll ns = ksm(a, b >> 1); ns = ns * ns % mod; if (b & 1) ns = ns * a % mod; return ns;}
using namespace std;
const int maxn = 100005;
int a[maxn];
int dp[maxn];
int sum[maxn];
int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        map<int, int> pref;
        pref[0] = 0;
        dp[0] = 0;
        sum[0] = 0;
        for (int i = 1; i <= n; i++) {
            sum[i] = sum[i - 1] ^ a[i];
            dp[i] = dp[i - 1];
            if (pref.count(sum[i])) {
                //cout << "!!!" << pref[sum[i]] << " " << i << endl;
                dp[i] = max(dp[i], dp[pref[sum[i]]] + 1);
            }
            pref[sum[i]] = i;
        }
        int ans = n - dp[n];
        cout << ans << endl;
    }
    return (0-0); //<3
}