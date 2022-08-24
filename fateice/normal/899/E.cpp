#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010],b[200010],l[200010],r[200010],f[200010],g[200010],p,q;
inline bool cmp(int i,int j)
{
	return b[i]>b[j] || b[i]==b[j] && i<j;
}
inline void up(int i)
{
	while(i>1 && cmp(f[i],f[i>>1]))
	  {
	   swap(f[i],f[i>>1]);
	   g[f[i]]=i;
	   g[f[i>>1]]=i>>1;
	   i>>=1;
 	  }
}
inline void down(int i)
{
	int j;
	while((i<<1)<=p)
	  {
	   if((i<<1)==p || cmp(f[i<<1],f[i<<1|1]))
	     j=i<<1;
	   else
	     j=i<<1|1;
	   if(cmp(f[j],f[i]))
	     {
	      swap(f[i],f[j]);
	      g[f[i]]=i;
	      g[f[j]]=j;
	      i=j;
	     }
	   else
	     break;
	  }
}
inline void del(int i)
{
	l[r[i]]=l[i];
	r[l[i]]=r[i];
}
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	  {
	   scanf("%d",&j);
	   if(!m || j!=a[m])
	     {
	      a[++m]=j;
	      b[m]=1;
	     }
	   else
	     b[m]++;
	  }
	for(i=1;i<=m;i++)
	  {
	   l[i]=i-1;
	   r[i]=i+1;
	  }
	for(i=1;i<=m;i++)
	  {
	   f[++p]=i;
	   g[i]=p;
	   up(p);
	  }
	while(p)
	  {
	   q++;
	   i=f[1];
	   f[1]=f[p--];
	   g[f[1]]=1;
	   down(1);
	   del(i);
	   if(l[i]>0 && r[i]<=m && a[l[i]]==a[r[i]])
	     {
	      b[l[i]]+=b[r[i]];
	      up(g[l[i]]);
	      j=g[r[i]];
	      f[j]=f[p--];
	      g[f[j]]=j;
	      down(j);
	      up(j);
	      del(r[i]);
	     }
	  }
	printf("%d\n",q);
	return 0;
}