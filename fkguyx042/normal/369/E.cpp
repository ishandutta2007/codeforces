#include<cstdio>
#include<algorithm>
#include<vector>
#define N 1000005
using namespace std;
vector<int>a[N];
struct arr{int l,r,id;}Q[N];
int n,m,i,k,tmp[N],x,y,ans[N],j,P,r;
inline int cmp(const arr &a,const arr &b){return a.r<b.r;}
struct bit_array
{
  int f[N];
  inline void add(int x){for (;x;x-=x&-x) f[x]++;}
  inline int ask(int x){int s=0;for (;x<=1000000;x+=x&-x) s+=f[x];return s;}
}A;
int main()
{
  scanf("%d%d",&n,&m);
  for (i=1;i<=n;i++)
    scanf("%d%d",&x,&y),a[y].push_back(x);
  for (i=1;i<=m;i++)
  {
    scanf("%d",&k);ans[i]=n;
    for (j=1;j<=k;j++)
      scanf("%d",&tmp[j]);
    tmp[0]=0;tmp[++k]=1000001;
    for (j=0;j<k;j++)
      if (tmp[j]+1<=tmp[j+1]-1) P++,Q[P].l=tmp[j]+1,Q[P].r=tmp[j+1]-1,Q[P].id=i;
  }
  sort(Q+1,Q+P+1,cmp);r=0;
  for (i=1;i<=P;i++)
  {
    for (;r<Q[i].r;r++) 
      for (j=0;j<a[r+1].size();j++)
        A.add(a[r+1][j]);
    ans[Q[i].id]-=A.ask(Q[i].l);
  }
  for (i=1;i<=m;i++) 
    printf("%d\n",ans[i]);
  return 0;
}