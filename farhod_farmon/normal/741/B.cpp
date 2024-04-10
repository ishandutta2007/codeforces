#include <bits/stdc++.h>

#define lli long long int
#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin freopen( "input.txt", "r", stdin );
#define fout freopen( "output.txt", "w", stdout );

const int N = 1010;

using namespace std;

int n;
int m;
int W;
int w[N];
int b[N];
int d[N];
bool used[N];
vector < int > v[N];
vector < int > nodes;

void dfs(int x)
{
    nodes.pb(x);
    used[x] = true;
    for(auto y: v[x]){
        if(!used[y])
            dfs(y);
    }
}

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n >> m >> W;
    for(int i = 1; i <= n; i++)
        cin >> w[i];
    for(int i = 1; i <= n; i++)
        cin >> b[i];
    for(int i = 1; i <= m; i++){
        int x, y;
        cin >> x >> y;
        v[x].pb(y);
        v[y].pb(x);
    }
    for(int i = 1; i <= n; i++){
        if(used[i])
            continue;
        nodes.clear();
        dfs(i);
        int sw = 0, sb = 0;
        for(auto x: nodes){
            sw += w[x];
            sb += b[x];
        }
        for(int j = W; j >= 1; j--){
            if(j >= sw)
                d[j] = max(d[j], d[j - sw] + sb);
            for(auto x: nodes)
                if(j >= w[x])
                    d[j] = max(d[j], d[j - w[x]] + b[x]);
        }
    }
    int ans = 0;
    for(int i = 1; i <= W; i++)
        ans = max(ans, d[i]);
    cout << ans << endl;
}