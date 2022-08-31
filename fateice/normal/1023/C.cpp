#include<bits/stdc++.h>
#define L long long
#define vi vector<int>
#define pb push_back
using namespace std;
int n,m,x[200010];
char s[200010];
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i,j,k;
	scanf("%d%d%s",&n,&m,&s);
	for(i=0,k=0;i<n;i++)
	  if(s[i]=='(' && k<m/2)
	    x[i]=1,k++;
	for(i=n-1,k=0;i>=0;i--)
	  if(s[i]==')' && k<m/2)
	    x[i]=1,k++;
	for(i=0;i<n;i++)
	  if(x[i])
	    printf("%c",s[i]);
	return 0;
}