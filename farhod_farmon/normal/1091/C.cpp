#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 5050;
const long long mod = 998244353;

using namespace std;

long long n;

long long solve(long long k)
{
        long long g = n / k;
        return g + g * (g - 1) / 2 * k;
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n;
        vector < long long > res;
        for(long long i = 1; i * i <= n; i++){
                if(n % i){
                        continue;
                }
                res.push_back(solve(i));
                if(i * i != n){
                        res.push_back(solve(n / i));
                }
        }
        sort(res.begin(), res.end());
        for(auto x: res){
                cout << x << " ";
        }
}