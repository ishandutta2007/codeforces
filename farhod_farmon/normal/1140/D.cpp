#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 300300;
const long long mod = 1e9 + 7;

using namespace std;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        long long res = 0, n;
        cin >> n;
        for(long long i = 2; i + 1 <= n; i++){
                res += i * (i + 1);
        }
        cout << res << "\n";
}