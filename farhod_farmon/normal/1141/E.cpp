#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 400400;
const long long mod = 1e9 + 7;

using namespace std;

int n;
long long H;
long long d[N];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> H >> n;
        long long W = 1e18;
        for(int i = 1; i <= n; i++){
                cin >> d[i];
                d[i] += d[i - 1];
                W = min(W, d[i]);
                if(H + d[i] <= 0){
                        cout << i << "\n";
                        return 0;
                }
        }
        if(d[n] >= 0){
                cout << -1 << "\n";
                return 0;
        }
        long long k = (- W - H) / d[n] - 1;
        long long res = k * n;
        H += k * d[n];
        while(true){
                for(int i = 1; i <= n; i++){
                        if(H + d[i] <= 0){
                                cout << res + i << "\n";
                                return 0;
                        }
                }
                H += d[n];
                res += n;
        }
}