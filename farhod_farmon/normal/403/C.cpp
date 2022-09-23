#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 2020;

using namespace std;

int n, a[N][N];
bool us1[N], us2[N];

void dfs1(int x)
{
    if(us1[x])
        return;
    us1[x] = true;
    for(int i = 1; i <= n; i++)
        if(a[x][i] > 0)
            dfs1(i);
}

void dfs2(int x)
{
    if(us2[x])
        return;
    us2[x] = true;
    for(int i = 1; i <= n; i++)
        if(a[i][x] > 0)
            dfs2(i);
}

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> a[i][j];
    dfs1(1);
    dfs2(1);
    bool can = true;
    for(int i = 1; i <= n; i++)
        if(us1[i] == false || us2[i] == false)
            can = false;
    if(can)
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}