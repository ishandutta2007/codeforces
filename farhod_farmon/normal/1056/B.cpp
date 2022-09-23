#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4")

#define fi first
#define se second
#define ll long long

const int N = 1010;

using namespace std;

long long n, m;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n >> m;
        long long ans = 0;
        for(long long i = 1; i <= m; i++){
                for(long long j = 1; j <= m; j++){
                        if(i > n || j > n){
                                continue;
                        }
                        long long x = i * i + j * j;
                        x %= m;
                        if(x == 0){
                                ans += 1ll * ((n - i) / m + 1) * ((n - j) / m + 1);
                        }
                }
        }
        cout << ans << "\n";
}