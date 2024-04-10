#include<bits/stdc++.h>
#define L long long
#define vi vector<int>
#define pb push_back
using namespace std;
int n,m,fa[300010],x[300010],f[300010][2],y[300010],a[300010][3],b[300010],p;
char s[300010];
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i,j,k,l,u;
	scanf("%d%d%s",&n,&m,&s);
	for(i=1;i<=m;i++)
	  {
       scanf("%d",&k);
       while(k--)
         {
          scanf("%d",&j);
          a[j][++b[j]]=i;
         }
       fa[i]=i;
       f[i][0]=1;
       y[i]=-1;
      }
    for(i=1;i<=n;i++)
      {
       if(b[i]==0)
         {}
       else if(b[i]==1)
         {
          j=a[i][1];
          for(l=j,k=0;fa[l]!=l;l=fa[l])
            k^=x[l];
          k^=(s[i-1]=='1');
          if(y[l]==-1)
            {
             y[l]=k;
             p-=min(f[l][0],f[l][1]);
             p+=f[l][k];
            }
         }
       else
         {
          j=a[i][1];
          k=a[i][2];
          l=x[j];
          u=x[k];
          while(j!=fa[j])
            {
             j=fa[j];
             l^=x[j];
            }
          while(k!=fa[k])
            {
             k=fa[k];
             u^=x[k];
            }
          if(j!=k)
          {
          if(f[j][0]+f[j][1]<f[k][0]+f[k][1])
            swap(j,k);
          if(y[j]==-1)
            p-=min(f[j][0],f[j][1]);
          else
            p-=f[j][y[j]];
          if(y[k]==-1)
            p-=min(f[k][0],f[k][1]);
          else
            p-=f[k][y[k]];
          fa[k]=j;
          if(l^u^(s[i-1]=='0'))
            {
             x[k]=1;
             swap(f[k][0],f[k][1]);
             if(y[k]!=-1)
               y[k]^=1;
            }
          f[j][0]+=f[k][0];
          f[j][1]+=f[k][1];
          if(y[k]!=-1)
            y[j]=y[k];
          if(y[j]==-1)
            p+=min(f[j][0],f[j][1]);
          else
            p+=f[j][y[j]];
        }
         }
       printf("%d\n",p);
      }
	return 0;
}