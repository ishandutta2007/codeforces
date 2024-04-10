#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;
const long long mod = 998244353;

using namespace std;

int f(int x)
{
        int res = 0;
        while(x > 0){
                res += x % 10;
                x /= 10;
        }
        return res % 4 == 0;
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        int n;
        cin >> n;
        while(f(n) == false)n += 1;
        cout << n << "\n";
}