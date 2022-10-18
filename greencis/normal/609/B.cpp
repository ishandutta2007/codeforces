#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

ll n,m,x,ans,cnt,a[15];

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    while (n--) {
        cin >> x;
        ++a[x];
        ++cnt;
    }
    ans = cnt * (cnt - 1) / 2;
    for (int i = 1; i <= m; ++i) {
        ans -= a[i] * (a[i] - 1) / 2;
    }
    cout << ans;
    return 0;
}