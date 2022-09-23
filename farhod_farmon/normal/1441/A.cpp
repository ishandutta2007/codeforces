#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;
const int mod = 998244353;

using namespace std;


int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        int t;
        cin >> t;
        while(t--){
                int n, m;
                cin >> n >> m;
                vector < int > a(n), b(m), us(n, 1);
                for(int i = 0; i < n; i++){
                        int x;
                        cin >> x;
                        a[x - 1] = i;
                }
                int res = 1;
                for(int i = 0; i < m; i++){
                        cin >> b[i];
                        b[i] = a[b[i] - 1];
                        us[b[i]] = 0;
                }
                for(int i: b){
                        int cnt = 0;
                        if(i > 0 && us[i - 1]){
                                cnt += 1;
                        }
                        if(i < n - 1 && us[i + 1]){
                                cnt += 1;
                        }
                        res = 1ll * res * cnt % mod;
                        us[i] = 1;
                }
                cout << res << "\n";
        }
}