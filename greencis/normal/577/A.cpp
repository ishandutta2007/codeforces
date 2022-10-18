#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

int n,x,ans;

int main()
{
    cin >> n >> x;
    for (int i = 1; i * i <= x; ++i) {
        if (x % i == 0) {
            if (i <= n && x / i <= n) {
                ++ans;
                if (i * i != x) ++ans;
            }
        }
    }
    cout << ans;

    return 0;
}