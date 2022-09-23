#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 1010;
const long long mod = 1000000007;
const int MAGIC = 2000;

using namespace std;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        int n, k;
        cin >> n >> k;
        cout << 3 * n + min(k - 1, n - k) << "\n";
}