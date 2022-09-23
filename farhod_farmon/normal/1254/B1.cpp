#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 1000031;
const long long mod = 1e9 + 7;

using namespace std;

int n;
int a[N];
int b[N];

long long solve(int k)
{
        long long res = 0;
        for(int i = 1; i <= n; i++){
                b[i] = a[i] % k;
        }
        for(int i = 1; i <= n; i++){
                b[i] %= k;
                if(b[i] < 0){
                        b[i] += k;
                }
                if(b[i] < k - b[i]){
                        b[i + 1] += b[i];
                        res += b[i];
                } else{
                        res += k - b[i];
                        b[i + 1] -= k - b[i];
                }
        }
        return res;
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n;
        long long S = 0;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
                S += a[i];
        }
        long long res = 1e18;
        for(int i = 2; i <= 1000000; i++){
                if(S % i == 0){
                        res = min(res, solve(i));
                }
        }
        if(res == 1e18){
                res = -1;
        }
        cout << res << "\n";
}