#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long long ll;
typedef long double ld;

int n,a[105],b[105],c[105],d[105],u[105];

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i] >> b[i] >> c[i] >> d[i];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (a[i] < a[j] && b[i] < b[j] && c[i] < c[j]) u[i] = 1;
    int mn=2e9,mni;
    for (int i = 0; i < n; ++i) {
        if (!u[i]) {
            if (d[i] < mn) mn = d[i], mni = i+1;
        }
    }
    cout << mni;

    return 0;
}