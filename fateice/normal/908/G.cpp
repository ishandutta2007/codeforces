#include<bits/stdc++.h>
#define L long long
using namespace std;
const int q=1000000007;
int n,f[710][710][2],p;
char s[710];
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i,j,k,l,u,kk,ll;
	scanf("%s",&s);
	n=strlen(s);
	for(i=1;i<=9;i++)
	  {
	   f[0][0][1]=1;
	   for(j=0;j<n;j++)
	     for(k=0;k<=j;k++)
	       for(l=0;l<=1;l++)
	         for(u=0;u<=9;u++)
	           {
				if(u<s[j]-'0')
				  ll=0;
				else if(u==s[j]-'0')
				  ll=l;
				else if(l)
				  continue;
				else
				  ll=0;
				if(u>=i)
				  kk=k+1;
				else
				  kk=k;
				f[j+1][kk][ll]=(f[j+1][kk][ll]+f[j][k][l])%q;
			   }
	   for(j=1,k=1;j<=n;j++,k=(k*10ll+1)%q)
	     p=(p+(L)k*(f[n][j][0]+f[n][j][1]))%q;
	   for(j=0;j<=n;j++)
	     for(k=0;k<=j;k++)
	       for(l=0;l<=1;l++)
	         f[j][k][l]=0;
	  }
	cout<<p;
	return 0;
}