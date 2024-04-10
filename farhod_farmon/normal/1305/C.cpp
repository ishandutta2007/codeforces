#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")

#define fi first
#define se second

const int N = 200200;
const int Q = 400200;

using namespace std;

int n, m;
int a[N];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        ios_base::sync_with_stdio(0);

        cin >> n >> m;
        for(int i = 1; i <= n; i++) cin >> a[i];

        if(n > 2 * m){
                cout << 0 << "\n";
        } else{
                int res = 1;
                for(int i = 1; i <= n; i++){
                        for(int j = i + 1; j <= n; j++){
                                int x = abs(a[i] - a[j]);
                                res = res * (x % m) % m;
                        }
                }
                cout << res << "\n";
        }
}