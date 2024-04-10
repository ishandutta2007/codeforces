#include<bits/stdc++.h>
#define L long long
#define vi vector<int>
#define pb push_back
using namespace std;
int n;
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i,j,k;
	scanf("%d",&n);
	for(i=2,j=1,k=n+1;i<=n;i++)
	  if(i+(n-1)/i+1<k)
	    k=i+(n-1)/i+1,j=i;
	for(i=1;i<=n;i=min(i+j,n+1))
      for(k=min(i+j-1,n);k>=i;k--)
        printf("%d ",k);
	return 0;
}