#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

int n,x,a[1005],ans;

int main()
{
    cin >> n;
    while (n--)
        cin >> x, ++a[x];
    int prev = 0;
    for (int i = 0; i < 1005; ++i) {
        ans += min(prev, a[i]);
        prev = max(prev, a[i]);
    }
    cout << ans;

    return 0;
}