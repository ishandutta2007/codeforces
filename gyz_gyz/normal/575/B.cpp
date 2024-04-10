#include<bits/stdc++.h>
#define pb push_back
#define N 100005
using namespace std;
vector<int>a[N],b[N];
const int P=1e9+7;
int f[N][18],value[N],Pow[N*10],deep[N],A[N],B[N];
int n,i,m,x,y,ans,z;
void dfs(int k)
{
    for (int i=1;i<=17;i++)
        f[k][i]=f[f[k][i-1]][i-1];
    for (int i=0,x;i<a[k].size();i++)
        if ((x=a[k][i])!=f[k][0])
            value[x]=b[k][i],deep[x]=deep[k]+1,f[x][0]=k,dfs(x);
}
int LCA(int x,int y){
    if (deep[x]<deep[y]) swap(x,y);
    int d=deep[x]-deep[y];
    for (int i=0;i<=17;i++)
        if ((d>>i)&1) x=f[x][i];
    if (x==y) return x;
    for (int i=17;i>=0;i--)
        if (f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
    return f[x][0];
}
void add(int x,int y){
    int z=LCA(x,y);
    if (z==x) {A[y]++;A[x]--;return;}
    if (z==y) {B[x]++;B[y]--;return;}
    B[x]++;B[z]--;A[y]++;A[z]--;
}
void get(int k)
{
    for (int i=0,x;i<a[k].size();i++)
        if ((x=a[k][i])!=f[k][0])
        {
            get(x);
            A[k]+=A[x];
            B[k]+=B[x];
      }
    if (k==1||!value[k]) return;
    if (value[k]==1) (ans+=Pow[B[k]])%=P;
    else (ans+=Pow[A[k]])%=P;
}
int main()
{
    scanf("%d",&n);
    for (i=1;i<n;i++)
    {
        scanf("%d%d%d",&x,&y,&z);
        a[x].pb(y),a[y].pb(x);
        if (z==1) b[x].pb(1),b[y].pb(2);
        else b[x].pb(0),b[y].pb(0);
  }
    deep[1]=1;dfs(1);
    scanf("%d",&m);
    for (Pow[1]=1,i=2;i<=m;i++) Pow[i]=(Pow[i-1]<<1)%P;
    for (i=1;i<=m;i++) (Pow[i]+=Pow[i-1])%=P;
    for (x=1,i=1;i<=m;i++){
        scanf("%d",&y);
        if (x!=y) add(x,y);x=y;
  }
    get(1);
    printf("%d\n",ans);
}