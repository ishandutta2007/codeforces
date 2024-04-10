#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;
const int mod = 1e9 + 7;

using namespace std;

int n;
int m;
int c[N];
int res;

void upd(int x, int y, int g)
{
        if(x > y){
                swap(x, y);
        }
        res += (c[x] == 0);
        c[x] += g;
        res -= (c[x] == 0);
}

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
                cin >> x >> y;
                upd(x, y, 1);
        }

        int q;
        cin >> q;
        for(int i = 1; i <= q; i++){
                int t, x, y;
                cin >> t;
                if(t == 1){
                        cin >> x >> y;
                        upd(x, y, 1);
                } else if(t == 2){
                        cin >> x >> y;
                        upd(x, y, -1);
                } else{
                        cout << n - res << "\n";
                }
        }
}