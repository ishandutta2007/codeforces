#include<cstdio>
#include<cstring>
using namespace std;
typedef long long LL;
const LL P=1000000007ll;
int a[10],f[10],i;
LL num,ans,n,k;
int work(int k,int flag)
{
  f[k]=flag;if (k==1) return 1;
  if (f[a[k]]!=flag) return work(a[k],flag);
  return 0;
}
inline void check()
{
  int ok=1;memset(f,0,sizeof(f));
  for (int i=2;i<=k&&ok;i++)
    ok&=work(i,i);
  if (ok) num++;
}
void dfs(int now)
{
  if (now==k+1) {check();return;}
  for (int i=1;i<=k;i++)
    a[now]=i,dfs(now+1);
}
int main()
{
  scanf("%I64d%I64d",&n,&k);ans=k;
  for (i=1;i<=n-k;i++) 
    (ans*=(n-k))%=P;
  dfs(2);
  if (num) (ans*=num)%=P;
  printf("%I64d",ans);
  return 0;
}