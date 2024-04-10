#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 111100;
const int MAGIC = 1000;
const long long mod = 998244353;

using namespace std;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        long long a, b, c;
        cin >> a >> b >> c;
        long long d = 2 + c * 2, f = 1 + c * 2;
        d += min(a - 1, b - 1) * 2 + (a > b);
        f += min(a, b - 1) * 2 + (a > b - 1);
        cout << max(d, f) << "\n";
}