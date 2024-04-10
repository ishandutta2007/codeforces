#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef pair<int, int> pii;
typedef long long ll;

map<int, int> mp;
int n, x;
ll ans;

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n;
    while (n--) {
        cin >> x;
        for (int i = 1; i <= 30; ++i) {
            ans += mp[(1 << i) - x];
        }
        ++mp[x];
    }
    cout << ans;
    return 0;
}