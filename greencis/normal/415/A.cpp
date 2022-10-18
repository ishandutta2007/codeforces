#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long long ll;
typedef long double ld;

int n,m,x,u[105];

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        cin >> x; --x;
        for (int j = x; j < n; ++j)
            if (!u[j]) u[j] = x+1;
    }
    for (int i = 0; i < n; ++i) cout << u[i] << " ";

    return 0;
}