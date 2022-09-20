#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;

const int N = 400400;
const int mod = 998244353;

int n;
int a[N], c[N];

int main()
{
        #ifdef zxc
                freopen("input.txt", "r", stdin);
                freopen("output.txt", "w", stdout);
        #endif
        ios_base::sync_with_stdio(0);

        cin >> n;
        for(int i = 1; i <= n; i++){
                int x, y;
                cin >> x >> y;
                if(min(x, y) > n){
                        cout << -1 << "\n";
                        return 0;
                }
                if(x > y){
                        swap(x, y);
                        c[x] = 1;
                }

                a[x] = y;
        }

        int res = 0;
        set < int > S;
        for(int i = 1; i <= n; i++){
                int X = 0, Y = 0;
                int last = 2 * n + 1, need = 2 * n - i + 1, mn = 2 * n - i + 1;
                S.insert(need);
                while(true){
                        S.erase(a[i]);
                        if(a[i] == need){
                                X += (c[i] ^ 1);
                                Y += c[i];

                                if(S.empty()){
                                        break;
                                }
                                need = *(--S.end());
                                i += 1;
                        } else{
                                if(a[i] > last){
                                        cout << -1 << "\n";
                                        return 0;
                                }
                                last = a[i];
                                while(mn > a[i]){
                                        mn -= 1;
                                        S.insert(mn);
                                }
                                S.erase(a[i]);
                                X += c[i];
                                Y += (1 ^ c[i]);
                                i += 1;
                        }
                }

                res += min(X, Y);
        }

        cout << res << "\n";
}