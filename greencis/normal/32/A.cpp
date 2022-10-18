#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long long ll;
typedef long double ld;

int n,a[2005],d,ans;

int main()
{
    cin >> n >> d;
    for (int i = 0 ; i< n;++i) cin >> a[i];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (abs(a[j] - a[i]) <= d) ++ans;
        }
    }cout << ans + ans;

    return 0;
}