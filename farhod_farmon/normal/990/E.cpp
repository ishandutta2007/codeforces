#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 1000010;
const long long Q = 100000001;
const long long mod = 1e9 + 7;
const long long MAGIC = 30;

using namespace std;

int n;
int m;
int k;
int last[N];
bool used[N];

void solve()
{
        cin >> n >> m >> k;
        for(int i = 1; i <= m; i++){
                int x;
                cin >> x;
                used[x] = 1;
        }
        if(used[0]){
                cout << -1 << "\n";
                return;
        }
        for(int i = 0; i < n; i++){
                if(used[i]){
                        last[i] = last[i - 1];
                }
                else{
                        last[i] = i;
                }
        }
        long long ans = 1e18;
        for(int i = 1; i <= k; i++){
                int cnt = 0, x, j = 0, gg = 0;
                cin >> x;
                while(true){
                        cnt++;
                        int h = j + i;
                        if(h >= n){
                                break;
                        }
                        h = last[h];
                        if(h == j){
                                gg = 1;
                                break;
                        }
                        j = h;
                }
                if(!gg){
                        ans = min(ans, 1ll * x * cnt);
                }
        }
        if(ans == 1e18){
                ans = -1;
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