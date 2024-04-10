#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 55;
const long long Q = 100000001;
const long long mod = 1e9 + 7;
const long long MAGIC = 30;

using namespace std;

int n;
int k;
int d[N][N];
long long a[N];

void solve()
{
        cin >> n >> k;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }
        long long ans = 0;
        for(long long h = 60; h >= 0; h--){
                ans += (1ll << h);
                for(int i = 0; i < N; i++){
                        for(int j = 0; j < N; j++){
                                d[i][j] = 0;
                        }
                }
                d[0][0] = 1;
                for(int i = 1; i <= n; i++){
                        for(int j = 1; j <= k; j++){
                                long long s = 0;
                                for(int h = i; h >= 1; h--){
                                        s += a[h];
                                        if((s & ans) == ans){
                                                d[i][j] |= d[h - 1][j - 1];
                                        }
                                }
                        }
                }
                if(d[n][k] == 0){
                        ans -= (1ll << h);
                }
        }
        cout << ans << "\n";
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("maze.in");
        //fout("maze.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}