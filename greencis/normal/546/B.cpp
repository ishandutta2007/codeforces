#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long long ll;
typedef long double ld;

int n,a[3005],ans;

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a,a+n);
    for (int i = 1; i < n; ++i) {
        while (a[i] <= a[i-1]) ++a[i], ++ans;
    }
    cout << ans;

    return 0;
}