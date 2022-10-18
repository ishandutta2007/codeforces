#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long long ll;
typedef long double ld;

int n,s,a[1005];

int main()
{
    cin >> n >> s;
    int sum = 0;
    for (int i = 0; i < n; ++i) cin >> a[i], sum += a[i];
    sort(a,a+n);
    sum -= a[n-1];
    if (sum <= s) cout << "YES";
    else cout << "NO";
    return 0;
}