#include<cstdio>
#include<vector>
#include<algorithm>
#define long long long
#define N 200005
using namespace std;vector<int>a[N];
long f[N][2];int get[N],x,n,i,root;
void dfs(int k)
{
    if (k==5)
        k=5;
    for (int i=0;i<a[k].size();i++)
        dfs(a[k][i]);
    long sum=0,small=1e18;int cnt=0;
    for (int i=0,x;i<a[k].size();i++) {
        x=a[k][i];
        if (f[x][0]>f[x][1]) sum+=f[x][0];else sum+=f[x][1],cnt^=1;
        small=min(small,abs(f[x][0]-f[x][1]));
  }
    f[k][0]=(cnt&1)?sum-small:sum;
    small=min(small,(long)get[k]);sum+=get[k];cnt^=1;
    f[k][1]=(cnt&1)?sum:sum-small;
}
int main()
{
    scanf("%d",&n);
    for (i=1;i<=n;i++) {
        scanf("%d%d",&x,&get[i]);
        if (x!=-1) a[x].push_back(i);else root=i;
  }dfs(root);printf("%I64d\n",max(f[root][0],f[root][1]));
}