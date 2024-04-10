#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long long ll;
typedef long double ld;

int n,m,a[105];

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a,a+n);
    int idx = 0, sum = 0;
    while (idx < n && a[idx] < 0 && idx < m) sum -= a[idx++];
    cout << sum;
    return 0;
}