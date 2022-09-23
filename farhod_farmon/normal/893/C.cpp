#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 100100;
const long long Q = 10010;
const long long mod = 1000000007;
const long long block = 500;

using namespace std;

int n;
int m;
int C;
int c[N];
bool used[N];
vector < int > v[N];

void dfs(int x)
{
        if(used[x]){
                return;
        }
        used[x] = 1;
        C = min(C, c[x]);
        for(int y: v[x]){
                dfs(y);
        }
}

void solve()
{
        cin >> n >> m;
        for(int i = 1; i <= n; i++){
                cin >> c[i];
        }
        for(int i = 1; i <= m; i++){
                int x, y;
                cin >> x >> y;
                v[x].push_back(y);
                v[y].push_back(x);
        }
        long long ans = 0;
        for(int i = 1; i <= n; i++){
                if(!used[i]){
                        C = 1e9;
                        dfs(i);
                        ans += C;
                }
        }
        cout << ans << "\n";
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("mine.in");
        //fout("mine.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}