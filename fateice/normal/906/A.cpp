#include<bits/stdc++.h>
using namespace std;
int n,x[100010][26],f[100010],a[26];
char s[100010];
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i,j,k;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	  {
	   scanf("%s",&s);
	   if(s[0]=='!')
	     f[i]=1;
	   else if(s[0]=='.')
	     f[i]=2;
	   else
	     f[i]=3;
	   scanf("%s",&s);
	   k=strlen(s);
	   for(j=0;j<k;j++)
	     x[i][s[j]-'a']=1;
	  }
	for(i=1;i<=n;i++)
	  {
	   if(f[i]==1)
	     {
	      for(j=0;j<26;j++)
	        if(x[i][j]==0)
	          a[j]=1;
		 }
	   else
	     {
	      for(j=0;j<26;j++)
	        if(x[i][j]==1)
	          a[j]=1;
		 }
	   for(j=0,k=0;j<26;j++)
	     if(a[j]==0)
	       k++;
	   if(k==1)
	     break;
	  }
	for(i++,k=0;i<n;i++)
	  if(f[i]==1 || f[i]==3)
	    k++;
	cout<<k;
	return 0;
}