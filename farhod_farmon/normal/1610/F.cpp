#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 300300;
const int Q = 600600;

using namespace std;

int n;
int m;
int A[N], B[N];
int f[N];
int a[N];
int g[N];
int val[N];
set<int> s[N];

int main()
{
        #ifdef zxc
                freopen("input.txt", "r", stdin);
                freopen("output.txt", "w", stdout);
        #endif
        ios_base::sync_with_stdio(0);

        cin >> n >> m;
        for(int i = 1; i <= m; i++){
                int x, y;
                cin >> x >> y >> a[i];
                A[i] = x;
                B[i] = y;
                f[x] += a[i];
                f[y] += a[i];
                s[x].insert(i);
                s[y].insert(i);
        }
        set<pair<int, int>> S;
        int res = 0;
        for(int i = 1; i <= n; i++){
                f[i] %= 2;
                if(f[i]){
                        res += 1;
                        S.insert({0, i});
                }
        }
        cout << res << "\n";

        while(!S.empty()){
                int x = (--S.end())->se;
                S.erase(--S.end());
                if(s[x].empty()){
                        continue;
                }

                int i = *s[x].begin();
                int y = A[i] ^ B[i] ^ x;

                s[x].erase(i);
                s[y].erase(i);

                S.erase({abs(val[y]), y});

                if(val[x] < 0){
                        g[i] = (x == A[i]);
                        val[x] += a[i];
                        val[y] -= a[i];
                } else{
                        g[i] = (x == B[i]);
                        val[x] -= a[i];
                        val[y] += a[i];
                }

                if(f[y]){
                        S.insert({abs(val[y]), y});
                }
                if(f[x]){
                        S.insert({abs(val[x]), x});
                }
        }

        for(int i = 1; i <= m; i++){
                cout << 2 - g[i];
        }
}