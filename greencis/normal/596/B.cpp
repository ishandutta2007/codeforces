#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long long ll;
typedef long double ld;

int n,a[500505];
ll ans;

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    int prev = 0;
    for (int i = 0; i < n; ++i) {
        ans += abs(prev - a[i]);
        prev = a[i];
    }
    cout << ans;

    return 0;
}