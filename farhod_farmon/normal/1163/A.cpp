#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;
const int Q = 200200;
const long long mod = 1e9 + 7;

using namespace std;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        int n, m;
        cin >> n >> m;
        int res = max(1, m);
        res = min(res, n - m);
        cout << res << "\n";
}