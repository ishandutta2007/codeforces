#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

int n;
ll a[100105];

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; ++i) {
            cin >> a[i];
    }
    sort(a, a + n);
    ll cur = 0;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] >= cur) {
            cur += a[i];
            ++ans;
        }
    }
    cout << ans;
}