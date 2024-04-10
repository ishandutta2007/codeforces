#include<bits/stdc++.h>
#define L long long
using namespace std;
int n;
map<int,int> f;
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i,j,k=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	  {
       scanf("%d",&j);
       f[j]++;
       k=max(k,f[j]);
      }
    printf("%d\n",n-k);
	return 0;
}