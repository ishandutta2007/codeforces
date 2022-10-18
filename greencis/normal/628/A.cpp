#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int,int> pii;

int n,b,p,x,y;

int main()
{
    cin >> n >> b >> p;
    y = p * n;
    while (n > 1) {
        int k = 1;
        while (k <= n) k <<= 1;
        k >>= 1;
        x += k / 2 * (b + b + 1);
        n = k / 2 + n - k;
    }
    cout << x << " " << y;

    return 0;
}