#include<bits/stdc++.h>
#define L long long
#define vi vector<int>
#define pb push_back
using namespace std;
int n,x[100010],y[100010];
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i;
	scanf("%d",&n);
	if(n&1)
	  {
       printf("NO\n");
       return 0;
      }
	for(i=1;i<=n;i++)
	  scanf("%d%d",&x[i],&y[i]);
	x[0]=x[n];
	y[0]=y[n];
	for(i=1;i<=n/2;i++)
	  if(x[i]-x[i-1]!=-(x[i+n/2]-x[i+n/2-1]) || y[i]-y[i-1]!=-(y[i+n/2]-y[i+n/2-1]))
	  {
       printf("NO\n");
       return 0;
      }
    printf("YES\n");
	return 0;
}