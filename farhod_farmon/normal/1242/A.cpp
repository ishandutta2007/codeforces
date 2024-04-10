#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 500200;
const int mod = 1e9 + 7;

using namespace std;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        long long n;
        cin >> n;
        long long res = n;
        for(long long i = 2; i <= 1000000; i++){
                if(i >= n){
                        break;
                } else if(n % i == 0){
                        res = __gcd(res, i);
                        res = __gcd(res, n / i);
                }
        }
        cout << res << "\n";
}