#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;

const int N = 100100;
const int mod = 998244353;

map < int, int > A;
map < int, int > C;
map < pair < int, int >, int > B;

int main()
{
        #ifdef zxc
                freopen("input.txt", "r", stdin);
                freopen("output.txt", "w", stdout);
        #endif
        ios_base::sync_with_stdio(0);

        int n;
        cin >> n;
        for(int i = 0; i < n; i++){
                int x, y;
                cin >> x >> y;
                if(x == y){
                        C[x] += 1;
                } else{
                        A[x] += 1;
                        A[y] += 1;
                        if(x > y){
                                swap(x, y);
                        }
                        B[{x, y}] += 1;
                }
        }
        long long res = 0;
        for(auto x: C){
                res += 1ll * x.se * (x.se - 1) / 2;
                res += 1ll * x.se * A[x.fi];
        }
        for(auto x: A){
                res += 1ll * x.se * (x.se - 1) / 2;
        }
        for(auto x: B){
                res -= 1ll * x.se * (x.se - 1) / 2;
        }
        cout << res << "\n";
}