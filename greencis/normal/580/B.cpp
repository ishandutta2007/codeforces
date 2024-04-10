#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long double ld;
typedef long long ll;

int n,d;
pii a[100005];

int main()
{
    cin >> n >> d;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a,a+n);

    ll ans = 0, cur = 0;
    int L = 0, R = -1;
    while (L < n) {
        if (R+1 < n && (L > R || a[L].first + d > a[R+1].first)) ++R, cur += a[R].second, ans = max(ans, cur);
        else cur -= a[L].second, ++L;
    }
    cout << max(ans, cur);

    return 0;
}