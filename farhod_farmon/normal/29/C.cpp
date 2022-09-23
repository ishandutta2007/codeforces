#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 100100;

using namespace std;

int n;
vector < int > v[N], ans;
map < int, int > rv, us;

void dfs(int x, int p)
{
    ans.pb(x);
    for(int i = 0; i < v[x].size(); i++)
        if(v[x][i] != p)
            dfs(v[x][i], x);
}

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n;
    int g = 0;
    for(int i = 1; i <= n; i++){
        int x, y;
        cin >> x >> y;
        if(us.find(x) == us.end()){
            us[x] = ++g;
            rv[g] = x;
        }
        if(us.find(y) == us.end()){
            us[y] = ++g;
            rv[g] = y;
        }
        x = us[x];
        y = us[y];
        v[x].pb(y);
        v[y].pb(x);
    }
    int root = 1;
    for(int i = 1; i <= g; i++)
        if(v[i].size() == 1)
            root = i;
    dfs(root, -1);
    for(int i = 0; i < ans.size(); i++)
        cout << rv[ans[i]] << " ";
}