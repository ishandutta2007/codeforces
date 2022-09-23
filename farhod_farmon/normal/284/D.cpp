#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 200200;

using namespace std;

int n;
int a[N];
long long d[N][2];
bool used[N][2];

long long dfs(int x, int g)
{
    if(x < 1 || x > n)
        return 0;
    if(d[x][g] > 0)
        return d[x][g];
    if(x == 1 || used[x][g])
        return -1;
    used[x][g] = true;
    int nx = x + a[x];
    if(g == 1)
        nx -= a[x] + a[x];
    long long G = dfs(nx, 1 - g);
    if(G == -1)
        d[x][g] = -1;
    else
        d[x][g] = G + a[x];
    return d[x][g];
}

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 2; i <= n; i++)
        cin >> a[i];
    for(int i = 2; i <= n; i++){
        if(!d[i][0])
            dfs(i, 0);
        if(!used[i][1])
            dfs(i, 1);
    }
    for(int i = 2; i <= n; i++){
        if(d[i][1] == -1)
            cout << -1 << endl;
        else
            cout << d[i][1] + i - 1 << endl;
    }
}