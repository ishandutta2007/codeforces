#include<cstdio>
#include<algorithm>
#include<cstring>
#include<bitset>

#define N 505
#define M 600005

using namespace std;
int i,j,m,n,p,k,id[M],q,Ans[M],Now[M];
char c[N][N];
struct Node{int sx,sy,ex,ey;}Q[M];
bitset<N>f[N][N],g[N][N],B;
void work(int l,int r,int ql,int qr)
{
   if (ql>qr) return;
   if (l>r) return;
   int mid=(l+r)>>1;
   int L=ql,R=qr,i,j,k;
   for (i=l;i<=mid;++i) for (j=1;j<=m;++j) f[i][j]=B;
   for (i=mid;i<=r;++i) for (j=1;j<=m;++j) g[i][j]=B;
   for (i=m;i;--i) 
     if (c[mid][i]=='.')
         f[mid][i]=f[mid][i+1],f[mid][i][i]=1;
   for (i=1;i<=m;++i)
     if (c[mid][i]=='.')
         g[mid][i]=g[mid][i-1],g[mid][i][i]=1;
   for (i=mid-1;i>=l;--i)
       for (j=m;j;--j)
            if (c[i][j]=='.')
              f[i][j]=f[i+1][j]|f[i][j+1];
   for (i=mid+1;i<=r;++i)
       for (j=1;j<=m;++j)
            if (c[i][j]=='.')
              g[i][j]=g[i-1][j]|g[i][j-1];
   for (i=ql;i<=qr;++i) if (Q[id[i]].ex<mid) Now[L++]=id[i];
   else if (Q[id[i]].sx>mid) Now[R--]=id[i];
   else 
   {
           if ((f[Q[id[i]].sx][Q[id[i]].sy]&g[Q[id[i]].ex][Q[id[i]].ey]).count())
              Ans[id[i]]=1;
              else Ans[id[i]]=0;
   }
   for (i=ql;i<=qr;++i) id[i]=Now[i];
   work(l,mid-1,ql,L-1);
   work(mid+1,r,R+1,qr);
	}
int main()
{
   scanf("%d%d",&n,&m);
   for (i=1;i<=n;++i)
   {
          scanf("%s",c[i]);
          for(j=m;j;--j) c[i][j]=c[i][j-1];
   }
   scanf("%d",&q);
   for (i=1;i<=q;++i) scanf("%d%d%d%d",&Q[i].sx,&Q[i].sy,&Q[i].ex,&Q[i].ey);
   for (i=1;i<=q;++i) id[i]=i;
   work(1,n,1,q);
   for (i=1;i<=q;++i) printf(Ans[i]?"Yes\n":"No\n");
 }