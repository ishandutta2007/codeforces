#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 2020;
const int mod = 998244353;

using namespace std;

int n;
long long a[N];
long long b[N];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        ios_base::sync_with_stdio(0);

        int q;
        cin >> n >> q;
        for(int i = 0; i < n; i++){
                cin >> a[i];
        }
        while(q--){
                int t, x;
                long long y;
                cin >> t >> x >> y;
                if(t == 1){
                        a[x] = y;
                } else{
                        long long can_have = 0;
                        for(int i = 0; i <= x; i++){
                                can_have += (a[i] << i);
                        }
                        long long need = 0;
                        if(y > can_have){
                                need = (y - can_have - 1) / (1ll << x) + 1;
                        }
                        for(int i = 0; i < n; i++){
                                b[i] = a[i];
                        }
                        long long res = 0;
                        for(int i = x + 1; i < n; i++){
                                need = (need + 1) / 2;
                                res += need;

                                long long g = min(need, b[i]);
                                b[i] -= need;
                                b[i - 1] += need * 2;
                                need -= g;
                        }

                        if(need > 0){
                                cout << -1 << "\n";
                                continue;
                        }

                        for(int i = 0; i <= x; i++){
                                y -= b[i];
                        }
                        if(y <= 0){
                                cout << res << "\n";
                                continue;
                        }
                        //cout << res << ' ' << y << "\n";

                        for(int i = x + 1; i < n; i++){
                                if(y < (1ll << i - x)){
                                        break;
                                }
                                long long g = y / (1ll << i - x);
                                g = min(g, b[i]);
                                y -= (g << i - x);
                                res += (g << i - x) - g;
                        }
                        cout << res + y << "\n";
                }
        }
}