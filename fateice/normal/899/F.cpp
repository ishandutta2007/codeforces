#include<bits/stdc++.h>
using namespace std;
int n,m,f[530000][65],g[530000],x[300],p;
char s[200010],t[5];
vector<int> a[530000];
inline void down(int i)
{
	if(g[i])
	  {
	   int j;
	   for(j=1;j<=62;j++)
	     if(!f[i][j])
	       {
	       	if(f[i<<1][j])
	       	  {
	       	   f[i<<1][0]-=f[i<<1][j];
	       	   f[i<<1][j]=0;
	       	   g[i<<1]=1;
	          }
	       	if(f[i<<1|1][j])
	       	  {
	       	   f[i<<1|1][0]-=f[i<<1|1][j];
	       	   f[i<<1|1][j]=0;
	       	   g[i<<1|1]=1;
	          }
	       }
	   g[i]=0;
	  }
}
inline void del(int i,int j,int k,int l,int r,int p)
{
	if(l<=j && k<=r)
	  {
	   f[i][0]-=f[i][p];
	   f[i][p]=0;
	   g[i]=1;
	  }
	else
	  {
	   down(i);
	   if(l<=(j+k>>1))
	     del(i<<1,j,j+k>>1,l,r,p);
	   if(r>(j+k>>1))
	     del(i<<1|1,(j+k>>1)+1,k,l,r,p);
	   f[i][0]-=f[i][p];
	   f[i][p]=f[i<<1][p]+f[i<<1|1][p];
	   f[i][0]+=f[i][p];
	  }
}
inline int find(int i,int j,int k,int p)
{
	if(j==k)
	  return j;
	down(i);
	if(p<=f[i<<1][0])
	  return find(i<<1,j,j+k>>1,p);
	else
	  return find(i<<1|1,(j+k>>1)+1,k,p-f[i<<1][0]);
}
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i,j,l,r;
	for(i='0';i<='9';i++)
	  x[i]=i-'0'+1;
	for(i='a';i<='z';i++)
	  x[i]=i-'a'+11;
	for(i='A';i<='Z';i++)
	  x[i]=i-'A'+37;
	scanf("%d%d%s",&n,&m,&s);
	for(p=1;p<n;p<<=1);
	for(i=1;i<=n;i++)
	  f[i+p-1][0]=f[i+p-1][x[s[i-1]]]=1;
	for(i=p-1;i>0;i--)
	  for(j=0;j<=62;j++)
	    f[i][j]=f[i<<1][j]+f[i<<1|1][j];
	while(m--)
	  {
	   scanf("%d%d%s",&l,&r,&t);
	   l=find(1,1,p,l);
	   r=find(1,1,p,r);
	   del(1,1,p,l,r,x[t[0]]);
	  }
	for(i=1;i<p;i++)
	  down(i);
	for(i=1;i<=n;i++)
	  if(f[i+p-1][0])
	    cout<<s[i-1];
	return 0;
}