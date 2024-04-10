#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 200200;
const long long Q = 2e18;
const long long mod = 1e9 + 7;
const long long MAGIC = 30;

using namespace std;

int n;
int m;
int s;
bool good[N];
bool used[N];
vector < int > v[N];
vector < int > order;

void dfs(int x)
{
        if(used[x]){
                return;
        }
        used[x] = 1;
        for(int y: v[x]){
                dfs(y);
        }
        order.push_back(x);
}

void make(int x)
{
        if(good[x]){
                return;
        }
        good[x] = 1;
        for(int y: v[x]){
                make(y);
        }
}

void solve()
{
        cin >> n >> m >> s;
        for(int i = 1; i <= m; i++){
                int x, y;
                cin >> x >> y;
                v[x].push_back(y);
        }
        for(int i = 1; i <= n; i++){
                if(!used[i]){
                        dfs(i);
                }
        }
        reverse(order.begin(), order.end());
        make(s);
        int ans = 0;
        for(int x: order){
                if(!good[x]){
                        make(x);
                        ans++;
                }
        }
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