#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#define N 500010
#define mod 1000000007
using namespace std;
int f[N];
int find(int x){return x==f[x]?f[x]:(f[x]=find(f[x]));}
int c[N],x[N],y[N];
bool v[N];
vector<int>ans;
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&c[i],&x[i]);
        if(c[i]==2) scanf("%d",&y[i]);
        else y[i]=m+1;
    }
    m++;
    for(int i=1;i<=m;i++) f[i]=i;
    for(int i=1;i<=n;i++)
    {
        if(find(x[i])!=find(y[i]))
        {
            f[find(x[i])]=find(y[i]);
            ans.push_back(i);
        }
    }
    // for(int i=1;i<=n;i++)
    // if(c[i]==1 && !v[find(x[i])]) v[find(x[i])]=true,ans.push_back(i);
    sort(ans.begin(),ans.end());
    int r=1;
    for(int i=1;i<=(int)ans.size();i++) r=2ll*r%mod;
    printf("%d %d\n",r,(int)ans.size());
    for(int i=0;i<(int)ans.size();i++) printf("%d ",ans[i]);
    return 0;
}