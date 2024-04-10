#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 200200;
const long long Q = 200200;
const long long mod = 998244353;
const long long MAGIC = sqrt(N);

using namespace std;

int n;
int ans;
bool good[N];
vector < int > v[N];

void dfs(int x, int p, int g = 0)
{
        for(int y: v[x]){
                if(y == p){
                        continue;
                }
                dfs(y, x, g + 1);
                if(good[y] == 0 && g > 1){
                        ans++;
                        good[x] = 1;
                        for(int y: v[x]){
                                good[y] = 1;
                        }
                }
        }
}

void solve()
{
        cin >> n;
        for(int i = 1; i < n; i++){
                int x, y;
                cin >> x >> y;
                v[x].push_back(y);
                v[y].push_back(x);
        }
        dfs(1, 1);
        cout << ans << "\n";
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