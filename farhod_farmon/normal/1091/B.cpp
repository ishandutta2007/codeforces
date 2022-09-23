#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 5050;
const long long mod = 998244353;

using namespace std;

int n;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n;
        long long a = 0, b = 0;
        for(int i = 1; i <= n + n; i++){
                int x, y;
                cin >> x >> y;
                a += x;
                b += y;
        }
        cout << a / n << " " << b / n << "\n";
}