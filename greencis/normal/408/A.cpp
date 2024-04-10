#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long long ll;
typedef long double ld;

int n,x,k[105],u[105];

int main()
{
    cin >> n;
    int ans = 2e9;
    for (int i = 0; i < n; ++i) cin >> k[i];
    for (int i = 0; i < n; ++i) {
        u[i] += k[i] * 15;
        while (k[i]--) {
            cin >> x;
            u[i] += x * 5;
        }
        ans = min(ans, u[i]);
    }
    cout << ans;
    return 0;
}