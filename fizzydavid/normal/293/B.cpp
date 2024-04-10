/*
    Author  : JZdavid
    From    : CF
    Problem : 293B
    Time    : 
    Verdict : Accepting
*/
#include<algorithm>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<map>
#include<queue>
#include<stack>
#include<string>
#include<set>
#include<utility>
#include<vector>
using namespace std;
#define ff first
#define ss second
#define pb push_back 
#define mp make_pair
typedef long long ll;
const int INF=1<<28;
const long long LINF=1ll<<61;
const int MOD=1e9+7;
int n,m,k,g[15][15],Log2[(1<<25)],area[15][15],used[15];
int dfs(int x,int y)
{
//  cout<<x<<" "<<y<<endl;
    if(y==m+1)x++,y=1;
    if(x==n+1)return 1;
    int cc=(area[x-1][y]|area[x][y-1]);
    int p=0;
    int w=-1;
    for(int i=(~cc)&((1<<k)-1);i;i-=(i&(-i)))
    {
        int t=Log2[i&(-i)]+1;
        if(!g[x][y]||g[x][y]==t)
        {
            used[t]++;
            area[x][y]=cc|(1<<(t-1));
            if(used[t]==1)
            {
                if(w==-1)w=dfs(x,y+1);
                p+=w;
            }
            else if(used[t])
            {
                p+=dfs(x,y+1);
            }
            if(p>=MOD)p-=MOD;
            used[t]--;
        }
    }
    return p;
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>m>>k;
    if(n+m-1>k)
    {
        puts("0");
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>g[i][j];
            used[g[i][j]]++;
        }
    }
    for(int i=1;i<=25;i++)Log2[1<<i]=i;
    cout<<dfs(1,1)<<endl;
//  system("pause");
    return 0;
}