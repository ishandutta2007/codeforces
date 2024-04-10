#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 5050;
const long long mod = 998244353;

using namespace std;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        int a, b, c;
        cin >> a >> b >> c;
        a = min(a, b - 1);
        a = min(a, c - 2);
        cout << a * 3 + 3 << "\n";
}