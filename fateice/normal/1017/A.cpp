#include<bits/stdc++.h>
#define L long long
#define vi vector<int>
#define pb push_back
using namespace std;
int n,x[1010];
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i,k=1,a,b,c,d;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	  {
       scanf("%d%d%d%d",&a,&b,&c,&d);
       x[i]=a+b+c+d;
      }
    for(i=2;i<=n;i++)
      if(x[i]>x[1])
        k++;
    cout<<k;
	return 0;
}