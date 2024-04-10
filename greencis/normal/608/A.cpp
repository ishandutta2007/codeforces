#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

int n,s,x,y,a[100005],dp[100005];

int main()
{
    cin >> n >> s;
    while (n--) {
        cin >> x >> y;
        a[x] = max(a[x], y);
    }
    dp[s+1] = -1;
    for (int i = s; i >= 0; --i) {
        dp[i] = max(dp[i+1] + 1, a[i]);
    }
    cout << dp[0];

    return 0;
}