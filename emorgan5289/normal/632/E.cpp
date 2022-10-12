#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int inf = 1e9;
const ll inf_ll = 1e18;
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifdef ONLINE_JUDGE
#define debug(...)
#else
#include "../../debug.cpp"
#endif

const int maxn = 1005;
int a[maxn], dp[maxn*maxn];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k; cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    fill(dp+1, dp+maxn*maxn, inf);
    sort(a, a+n);
    for (int i = 1; i < n; i++)
        a[i] -= a[0];
    for (int i = 1; i < n; i++)
        for (int j = 0; j < a[i]*k; j++)
            dp[j+a[i]] = min(dp[j+a[i]], dp[j]+1);
    for (int i = 0; i < maxn*maxn; i++)
        if (dp[i] <= k)
            cout << i+k*a[0] << " ";
}