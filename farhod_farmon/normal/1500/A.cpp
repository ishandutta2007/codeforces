#include <bits/stdc++.h>

using namespace std;

#ifdef zxc
#include "debug.h"
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#define debug_arr(...) 42
#endif

#define fi first
#define se second

const int N = 200200;
const int mod = 998244353;

pair < int, int > a[N];
pair < int, int > us[5000005];

int main()
{
        #ifdef zxc
                freopen("input.txt", "r", stdin);
                freopen("output.txt", "w", stdout);
        #endif
        ios_base::sync_with_stdio(0);

        int n;
        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> a[i].fi;
                a[i].se = i;
        }
        sort(a + 1, a + n + 1);
        
        n = min(n, 20000);

        for(int i = 1; i <= n; i++){
                for(int j = 1, s; j < i; j++){
                        s = a[i].fi + a[j].fi;
                        if(us[s].fi > 0 && - us[s].se < i && us[s].fi > j){
                                cout << "YES\n";
                                cout << a[i].se << " " << a[j].se << " " << a[us[s].fi].se << " " << a[- us[s].se].se << "\n";
                                return 0;
                        }
                        us[s] = max(us[s], make_pair(j, - i));
                }
        }

        cout << "NO\n";
}