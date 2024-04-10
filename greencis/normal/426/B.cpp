#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long long ll;
typedef long double ld;

int n,m,x;
char z[9];
string s[105];

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> x;
            *z = 48 + x;
            s[i] += z;
        }
    }
    int l = 0, r = n-1;
    while (1) {
        if ((r-l+1)%2) break;
        bool good = true;
        for (int i = 0; i <= r-l; ++i) {
            if (s[l+i] != s[r-i]) { good = false; break; }
        }
        if (!good) break;
        r = (r + 1) / 2 - 1;
    }
    cout << r-l+1;
    return 0;
}