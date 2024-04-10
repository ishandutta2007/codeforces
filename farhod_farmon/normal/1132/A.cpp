#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 500500;
const long long mod = 1000000007;

using namespace std;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        int a, b, c, d;
        cin >> a >> b >> c >> d;
        cout << (a == d && min(c, 1) <= a * 2) << "\n";
}