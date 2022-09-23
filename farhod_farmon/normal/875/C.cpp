#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 100100;
const long long Q = 100100;
const long long mod = 998244353;
const long long block = 500;

using namespace std;

int n;
int m;
bool need[N];
bool used[N];
vector < int > ans;
vector < int > v[N];
vector < int > g[N];

void dfs(int x)
{
        if(used[x]){
                return;
        }
        used[x] = 1;
        need[x] = 1;
        for(int y: g[x]){
                dfs(y);
        }
}

void solve()
{
        cin >> n >> m;
        for(int i = 1; i <= n; i++){
                int l, x;
                cin >> l;
                for(int j = 1; j <= l; j++){
                        cin >> x;
                        v[i].push_back(x);
                }
        }
        for(int i = 2; i <= n; i++){
                int f = -1, g = min(v[i - 1].size(), v[i].size());
                for(int j = 0; j < g; j++){
                        if(v[i - 1][j] != v[i][j]){
                                f = j;
                                break;
                        }
                }
                if(f == -1){
                        if(v[i - 1].size() > v[i].size()){
                                cout << "No" << "\n";
                                return;
                        }
                        continue;
                }
                int x = v[i - 1][f], y = v[i][f];
                if(x > y){
                        need[x] = 1;
                }
                else{
                        ::g[y].push_back(x);
                }
        }
        for(int i = m; i >= 1; i--){
                if(need[i]){
                        dfs(i);
                }
        }
        for(int i = 2; i <= n; i++){
                int f = -1, g = min(v[i - 1].size(), v[i].size());
                for(int j = 0; j < g; j++){
                        if(v[i - 1][j] != v[i][j]){
                                f = j;
                                break;
                        }
                }
                if(f == -1){
                        continue;
                }
                int x = v[i - 1][f], y = v[i][f];
                if(need[x] == need[y] && x > y){
                        cout << "No" << "\n";
                        return;
                }
        }
        for(int i = 1; i <= m; i++){
                if(need[i]){
                        ans.push_back(i);
                }
        }
        cout << "Yes" << "\n";
        cout << ans.size() << "\n";
        for(int x: ans){
                cout << x << " ";
        }
}


bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("landscape.in");
        //fout("landscape.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}