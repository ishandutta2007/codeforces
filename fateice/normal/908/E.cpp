#include<bits/stdc++.h>
#define L long long
using namespace std;
const int q=1000000007;
int m,n,x[1010],f[1010],c[1010][1010],p;
char s[60][1010];
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i,j,k;
	scanf("%d%d",&m,&n);
	for(i=1;i<=n;i++)
	  scanf("%s",&s[i]);
	for(i=0;i<m;i++)
	  {
	   for(j=0;j<i;j++)
	     {
		  for(k=1;k<=n;k++)
		    if(s[k][i]!=s[k][j])
		      break;
		  if(k>n)
		    break;
		 }
	   x[j]++;
	  }
	for(i=0;i<=m;i++)
	  for(c[i][0]=1,j=1;j<=i;j++)
	    c[i][j]=(c[i-1][j]+c[i-1][j-1])%q;
	f[0]=f[1]=1;
	for(i=2;i<=m;i++)
	  for(j=1;j<=i;j++)
	    f[i]=(f[i]+(L)c[i-1][j-1]*f[i-j])%q;
	p=1;
	for(i=0;i<m;i++)
	  p=(L)p*f[x[i]]%q;
	cout<<p;
	return 0;
}