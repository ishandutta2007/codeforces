#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#define mid ((l+r)>>1)
#define ls (t<<1)
#define rs ((t<<1)+1)
using namespace std;
int ans[200005];
vector<int>v[200005];
struct Node{int suml,sumr,sum;}Tree[1000005];
int i,j,m,n,p,k,b[200005],a[200005],Last;
void up(Node &a,Node b,Node c,int len)
{
      a.suml=b.suml;
      if (b.suml==(len-(len>>1))) a.suml+=c.suml;
      a.sumr=c.sumr;
      if (c.sumr==(len>>1)) a.sumr+=b.sumr;
      a.sum=max(b.sum,max(c.sum,b.sumr+c.suml));
}
void ins(int ll,int l,int r,int t)
{
      if (l==r) Tree[t].sum=Tree[t].suml=Tree[t].sumr=1;
      else 
      {
            if (ll<=mid) ins(ll,l,mid,ls);
            else ins(ll,mid+1,r,rs);
            up(Tree[t],Tree[ls],Tree[rs],r-l+1);
      }
}
int main()
{
    scanf("%d",&n); 
    for (i=1;i<=n;++i) scanf("%d",&a[i]),b[i]=a[i];
    sort(b+1,b+n+1);
    b[0]=unique(b+1,b+n+1)-(b+1);
    for (i=1;i<=n;++i)a[i]=lower_bound(b+1,b+b[0]+1,a[i])-b,v[a[i]].push_back(i);
    for (i=b[0];i;--i)
    {
         for (j=0;j<v[i].size();++j) ins(v[i][j],1,n,1);
         int Limit=Tree[1].sum;
         for (j=Last+1;j<=Limit;++j) ans[j]=b[i];
         Last=Limit;
    }
    for (i=1;i<=n;++i) printf("%d ",ans[i]);
}