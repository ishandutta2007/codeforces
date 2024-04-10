#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 300300;
const long long Q = N * 30;
const long long mod = 998244353;
const long long MAGIC = 30;

using namespace std;

int n;
int q;
int G;
int t[Q][2];
int s[Q];
int d[Q];

void dfs(int x)
{
        for(int i = 0; i < 2; i++){
                int y = t[x][i];
                if(!y){
                        continue;
                }
                dfs(y);
                s[x] += s[y];
                d[x] = d[y] + 1;
        }
}

int get(int x)
{
        int h = 0, ans = 0;
        for(int i = 20; i >= 0; i--){
                int g = (x >> i) & 1;
                int y = t[h][g];
                if((1 << d[y]) != s[y]){
                        h = t[h][g];
                }
                else{
                        h = t[h][1 ^ g];
                        ans += (1 << i);
                }
                if(!h){
                        break;
                }
        }
        return ans;
}

void solve()
{
        cin >> n >> q;
        for(int i = 1; i <= n; i++){
                int x, h = 0;
                cin >> x;
                for(int j = 20; j >= 0; j--){
                        int g = (x >> j) & 1;
                        if(!t[h][g]){
                                G++;
                                t[h][g] = G;
                        }
                        h = t[h][g];
                }
                s[h] = 1;
        }
        dfs(0);
        int u = 0;
        for(int i = 1; i <= q; i++){
                int x;
                cin >> x;
                u ^= x;
                cout << get(u) << "\n";
        }
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("island.in");
        //fout("island.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}