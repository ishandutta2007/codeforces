#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;

int n,x,y;
ll diag1[3005],diag2[3005];
ll ans;

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n;
    while (n--) {
        cin >> x >> y;
        ++diag1[1000 + x - y];
        ++diag2[1000 + y + x];
    }
    for (int i = 0; i < 3005; ++i) {
        ans += diag1[i] * (diag1[i] - 1) / 2;
        ans += diag2[i] * (diag2[i] - 1) / 2;
    }
    cout << ans;

    return 0;
}