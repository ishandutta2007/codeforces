#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long long ll;
typedef long double ld;

int n,l,a[100005];

int main()
{
    cin >> n >> l;
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a, a + n);
    int ans = 2*max(l - a[n-1], a[0]);
    for (int i = 0; i < n-1; ++i) {
        ans = max(ans, a[i+1] - a[i]);
    }
    cout << ans / 2 << "." << ans % 2 * 5;

    return 0;
}