#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

int n,m,a[100005];

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a,a+n);
    for (int i = n-1; i >= 0; --i) {
        m -= a[i];
        if (m <= 0) {
            cout << n - i;
            return 0;
        }
    }
    return 0;
}