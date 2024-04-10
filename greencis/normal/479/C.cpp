#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long long ll;
typedef long double ld;

int n;
pii a[5005];

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a,a+n);
    int ans = -2e9;
    for (int i = 0; i < n; ++i) {
        if (ans <= a[i].second) ans = a[i].second;
        else ans = a[i].first;
    }
    cout << ans;

    return 0;
}