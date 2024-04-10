#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 300300;
const long long mod = 998244353;

using namespace std;

int n;
long long a[N];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        int m;
        cin >> n >> m;

        long long g = 0;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
                if(i == 2){
                        g = a[i] - a[i - 1];
                } else{
                        g = __gcd(g, a[i] - a[i - 1]);
                }
        }

        for(int i = 1; i <= m; i++){
                long long x;
                cin >> x;

                if(g % x == 0){
                        cout << "YES" << "\n";
                        cout << a[1] << " " << i << "\n";
                        return 0;
                }
        }

        cout << "NO" << "\n";
}