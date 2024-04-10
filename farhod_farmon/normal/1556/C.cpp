#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 10100;

using namespace std;

int n;
long long a[N];

int main()
{
        #ifdef zxc
                freopen("input.txt", "r", stdin);
                freopen("output.txt", "w", stdout);
        #endif
        ios_base::sync_with_stdio(0);

        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }
        long long res = 0;
        for(int i = 1; i <= n; i++){
                if(i % 2 == 0){
                        continue;
                }
                long long s = 0, min_bal = 0, l, r;
                for(int j = i + 1; j <= n; j++){
                        if(j % 2 == 0){
                                l = max(1 - s, 1ll);
                                l = max(l, - min_bal);
                                r = min(a[i], a[j] - s);
                                if(l <= r){
                                        res += r - l + 1;
                                }

                                s -= a[j];
                                min_bal = min(min_bal, s);
                        } else{
                                s += a[j];
                        }
                }
        }

        cout << res << "\n";
}