#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 55;
const long long mod = 998244353;

using namespace std;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        int n, m, before;
        cin >> n >> m >> before;
        int a = 1e9, b = 0;
        for(int i = 1; i <= n; i++){
                int x;
                cin >> x;
                a = min(a, x);
        }
        for(int i = 1; i <= m; i++){
                int x;
                cin >> x;
                b = max(b, x);
        }
        int after = (before / a) * b + before % a;
        cout << max(before, after) << "\n";
}