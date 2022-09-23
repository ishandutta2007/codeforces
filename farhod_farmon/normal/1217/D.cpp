#include <bits/stdc++.h>
 
#define fi first
#define se second
 
const int N = 5050;
 
using namespace std;
 
int n;
int m;
int used[N];
bool cycle;
vector < int > v[N];
 
void dfs(int x, int p)
{
        if(used[x]){
                if(used[x] == 1){
                        cycle = true;
                }
                return;
        }
        used[x] = 1;
        for(int y: v[x]){
                dfs(y, x);
        }
        used[x] = 2;
}
 
int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
 
        ios_base::sync_with_stdio(0);
 
        cin >> n >> m;
        vector < pair < int, int > > e;
        for(int i = 1, x, y; i <= m; i++){
                cin >> x >> y;
                v[x].push_back(y);
                e.push_back({x, y});
        }
        for(int i = 1; i <= n; i++){
                dfs(i, i);
        }
        if(cycle){
                cout << 2 << "\n";
        } else{
                cout << 1 << "\n";
        }
        for(auto p: e){
                if(cycle && p.fi > p.se){
                        cout << 2 << " ";
                } else{
                        cout << 1 << " ";
                }
        }
}