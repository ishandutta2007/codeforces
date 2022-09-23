#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;

using namespace std;

long long get(long long k, long long n)
{
        if(k == 1){
                return 0;
        }
        long long shit = k / 4;
        long long res = get(k / 4, (n - 1) % shit + 1);

        if(n <= shit){
                res += 0;
        } else if(n <= shit * 2){
                res += shit * 2;
        } else if(n <= shit * 3){
                res += shit * 2 + shit;
        } else{
                res += shit;
        }

        return res;
}

vector < long long > solve(long long n)
{
        if(n == 1){
                return {1, 2, 3};
        }
        n -= 1;
        long long k = 4;
        while(n > k){
                n -= k;
                k = k * 4;
        }
        vector < long long > res(3);

        res[0] = k + n - 1;
        res[1] = get(k, n) + k * 2;
        res[2] = res[0] ^ res[1];

        return res;
}

int main()
{
        ios_base::sync_with_stdio(false);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        int t;
        cin >> t;
        while(t--){
                long long n;
                cin >> n;
                n -= 1;
                auto res = solve(n / 3 + 1);

                cout << res[n % 3] << "\n";
        }
}