#include<bits/stdc++.h>
#define L long long
using namespace std;
int n,a,b;
L p;
char s[300010];
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i,k=0;
	scanf("%d%d%d%s",&n,&a,&b,&s[0]+1);
	for(i=1;i<=n;i++)
	  if(s[i]=='0' && (i==1 || s[i-1]=='1'))
	    k++;
	if(k)
	  p=b+(L)min(a,b)*(k-1);
	cout<<p;
	return 0;
}