#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 300300;

using namespace std;

int n;
long long a[N];
long long b[N];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n;
        long long sum = 0;
        for(int i = 1; i <= n; i++){
                cin >> a[i] >> b[i];
                sum += a[i];
        }
        if(sum < 0){
                for(int i = 1; i <= n; i++){
                        a[i] *= -1;
                }
        }
        long long res = 0;
        for(long long i = 0; i < 62; i++){
                sum = 0;
                for(int j = 1; j <= n; j++){
                        if(b[j] == (1ll << i)){
                                sum += a[j];
                        }
                }
                if(sum > 0){
                        res += 1ll << i;
                        for(int j = 1; j <= n; j++){
                                if(b[j] & (1ll << i)){
                                        a[j] *= -1;
                                        b[j] ^= (1ll << i);
                                }
                        }
                } else{
                        for(int j = 1; j <= n; j++){
                                if(b[j] & (1ll << i)){
                                        b[j] ^= (1ll << i);
                                }
                        }
                }
        }
        cout << res << "\n";
}