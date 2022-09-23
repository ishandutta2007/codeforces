#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 1000100;
const int Q = 1000100;
const long long mod = 1e9 + 7;

using namespace std;

int n;
int d[N];

int main()
{
        //freopen("input.txt","r",stdin);
        //freopen("output.txt","w",stdout);
        ios_base::sync_with_stdio(0);

        cin >> n;
        d[0] = 1;
        for(int i = 1; i <= n; i++){
                int x;
                cin >> x;
                vector < int > a, b;
                for(int j = 1; j * j <= x; j++){
                        if(x % j == 0){
                                a.push_back(j);
                                if(j * j != x){
                                        b.push_back(x / j);
                                }
                        }
                }
                reverse(a.begin(), a.end());
                for(int x: b){
                        d[x] += d[x - 1];
                        if(d[x] >= mod){
                                d[x] -= mod;
                        }
                }
                for(int x: a){
                        d[x] += d[x - 1];
                        if(d[x] >= mod){
                                d[x] -= mod;
                        }
                }
        }
        int ans = 0;
        for(int i = 1; i < N; i++){
                ans += d[i];
                if(ans >= mod){
                        ans -= mod;
                }
        }
        cout << ans << "\n";
}