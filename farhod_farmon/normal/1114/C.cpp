#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;
const int Q = 250200;
const long long mod = 1e9 + 7;

using namespace std;

long long get(long long n, long long k)
{
        long long res = 0;
        while(n){
                res += n / k;
                n /= k;
        }
        return res;
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        long long n, k;
        cin >> n >> k;
        long long res = 1e18;
        for(long long i = 2; i * i <= k; i++){
                int cnt = 0;
                if(k % i == 0){
                        while(k % i == 0){
                                k /= i;
                                cnt += 1;
                        }
                        res = min(res, get(n, i) / cnt);
                }
        }
        if(k > 1){
                res = min(res, get(n, k));
        }
        cout << res << "\n";
}