#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 300300;

using namespace std;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        int t;
        cin >> t;
        while(t--){
                int n;
                cin >> n;
                long long inf = 1e10;
                vector < long long > t(n + 1, 0);
                vector < long long > x(n + 1, 0);
                for(int i = 0; i < n; i++){
                        cin >> t[i] >> x[i];
                }
                t[n] = inf;
                int res = 0;
                long long cur = 0, g = 0;
                for(int i = 0; i < n; i++){
                        if(!g){
                                g = x[i] - cur;
                        }
                        if(g < 0){
                                long long gg = min(-g, t[i + 1] - t[i]);
                                res += (cur - gg <= x[i] && x[i] <= cur);
                                cur -= gg;
                                g += gg;
                        } else{
                                long long gg = min(g, t[i + 1] - t[i]);
                                res += (cur <= x[i] && x[i] <= cur + gg);
                                cur += gg;
                                g -= gg;
                        }
                }
                cout << res << "\n";
        }
}