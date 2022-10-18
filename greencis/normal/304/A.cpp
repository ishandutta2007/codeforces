#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long long ll;
typedef long double ld;

int n,ans;

int main()
{
    cin >> n;
    for (int a = 2; a <= n; ++a) {
        for (int b = a + 1; b <= n; ++b) {
            int c = int(sqrt(a*a+b*b+0.) + 1e-9);
            if (c*c == a*a + b*b && c >= b && c <= n) ++ans;
        }
    }
    cout << ans;
    return 0;
}