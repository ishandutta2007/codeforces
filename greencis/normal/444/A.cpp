#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long long ll;
typedef long double ld;

int n,m,x[505],a,b,c;

int main()
{
    ld ans = 0;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> x[i];
    while (m--) {
        cin >> a >> b >> c;
        ans = max(ans, ld(x[a-1] + x[b-1]) / ld(c));
    }
    cout.precision(17);
    cout << fixed << ans;

    return 0;
}