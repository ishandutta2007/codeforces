#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

int n,a[1005],ans;

bool good() {
    for (int i = 1; i < n; ++i)
        if (a[i] >= a[0]) return false;
    return true;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    while (!good()) {
        int mx = -1, mxi = -1;
        for (int i = 1; i < n; ++i) {
            if (a[i] > mx) mx = a[i], mxi = i;
        }
        --a[mxi];
        ++a[0];
        ++ans;
    }
    cout << ans;

    return 0;
}