#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

int n,f[999],m[999];
char z[2];
int x,y;

int main()
{
    cin >> n;
    while (n--) {
        cin >> z >> x >> y;
        for (int i = x; i <= y; ++i) {
            if (*z == 'F') ++f[i];
            else ++m[i];
        }
    }
    int ans = 0;
    for (int i = 0; i < 999; ++i)
        ans = max(ans, min(f[i], m[i]));
    cout << ans * 2;

    return 0;
}