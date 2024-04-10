#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#define fi first
#define se second

using namespace std;

const int N = 200200;

int n, m, p;
int c[66];
string s[N];
map < long long, int > C;
map < long long, int > D;

int main()
{
        #ifdef zxc
                freopen("input.txt", "r", stdin);
                freopen("output.txt", "w", stdout);
        #endif
        ios_base::sync_with_stdio(0);

        cin >> n >> m >> p;
        for(int i = 0; i < n; i++){
                cin >> s[i];
                for(int j = 0; j < m; j++){
                        s[i][j] -= '0';
                        c[j] += s[i][j];
                }
        }
        int need = (n + 1) / 2;
        for(int i = 0; i < n; i++){
                long long x = 0;
                for(int j = 0; j < m; j++){
                        if(c[j] < need){
                        } else if(s[i][j]){
                                x |= (1ll << j);
                        }
                }
                if(x > 0){
                        D[x] += 1;
                }
        }

        for(auto p: D){
                long long x = p.fi;
                while(x > 0){
                        C[x] += p.se;
                        x = (x - 1) & p.fi;
                }
        }

        long long res = 0;
        for(auto p: C){
                if(p.se >= need && __builtin_popcountll(p.fi) > __builtin_popcountll(res)){
                        res = p.fi;
                }
        }
        for(int i = 0; i < m; i++){
                cout << ((res >> i) & 1);
        }
}