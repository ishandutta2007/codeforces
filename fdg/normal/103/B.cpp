#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <ctime>
#include <memory.h>
//#include <complex>
#include <set>

#define ll long long

using namespace std;

int g[102][102];
bool used[102];
int n,m,a,b;
bool cycle;

int dfs(int cur,int par = -1)
{
    used[cur]=true;
    int ret=1;
    for(int i=0;i<n;i++)
        if (g[cur][i]&&i!=par)
        {
            if (!used[i]) ret+=dfs(i,cur);
            else
            {
                a=cur; b=i;
                cycle=true;
            }
        }
    return ret;
}

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    cin >> n >> m;
    for(int i=0;i<m;i++)
    {
        cin >> a >> b;
        a--; b--;
        g[a][b]=g[b][a]=1;
    }
    int cnt=dfs(0);
    if (cnt!=n||!cycle) cout << "NO\n";
    else
    {
        memset(used,false,sizeof(used));
        cycle=false;
        g[a][b]=g[b][a]=0;
        dfs(0);
        if (cycle) cout << "NO\n";
        else cout << "FHTAGN!\n";
    }
    return 0;
}