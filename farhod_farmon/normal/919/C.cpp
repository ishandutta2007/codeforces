#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 2020;
const long long Q = 6000100;
const long long mod = 1e9 + 7;
const long long block = 500;

using namespace std;

int n;
int m;
int k;
char c[N][N];

void solve()
{
        int ans = 0;
        cin >> n >> m >> k;
        for(int i = 1; i <= n; i++){
                int l = 0;
                for(int j = 1; j <= m; j++){
                        cin >> c[i][j];
                        if(c[i][j] == '.'){
                                l++;
                        }
                        else{
                                l = 0;
                        }
                        if(l >= k){
                                ans++;
                        }
                }
        }
        if(k > 1){
                for(int j = 1; j <= m; j++){
                        int l = 0;
                        for(int i = 1; i <= n; i++){
                                if(c[i][j] == '.'){
                                        l++;
                                }
                                else{
                                        l = 0;
                                }
                                if(l >= k){
                                        ans++;
                                }
                        }
                }
        }
        cout << ans << "\n";
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("bootfall.in");
        //fout("bootfall.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}