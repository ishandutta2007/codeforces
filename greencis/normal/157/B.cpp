#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long long ll;
typedef long double ld;

int n,a[10005];

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a,a+n,greater<int>());
    int sum = 0;
    for (int i = 0; i < n; ++i)
        if (i & 1) sum -= a[i] * a[i];
        else sum += a[i] * a[i];
    printf("%.17lf",sum * 3.1415926535898);

    return 0;
}