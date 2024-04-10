#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 50500;

using namespace std;

int n, k;
int ans;
int up[N][N / 100];
int down[N][N / 100];
vector < int > v[N];

void dfs(int x, int p)
{
    for(int i = 0; i < v[x].size(); i++){
        int y = v[x][i];
        if(y == p)
            continue;
        up[y][1] = 1;
        for(int j = 2; j <= k; j++)
            up[y][j] += up[x][j - 1] + down[x][j - 1];
        dfs(y, x);
        down[x][1]++;
        for(int j = 2; j <= k; j++)
            down[x][j] += down[y][j - 1];
    }
    ans += up[x][k];
}

int main()
{
	//fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n >> k;
    for(int i = 1; i < n; i++){
        int x, y;
        cin >> x >> y;
        v[x].pb(y);
        v[y].pb(x);
    }
    dfs(1, -1);
    cout << ans << endl;
}