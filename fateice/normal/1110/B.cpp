#include<bits/stdc++.h>
#define L long long
#define vi vector<int>
#define pb push_back
using namespace std;
int n,m,q,x[100010],p;
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i,j,k;
	scanf("%d%d%d",&n,&m,&q);
	for(i=1;i<=n;i++)
	  scanf("%d",&x[i]);
	for(i=2;i<=n;i++)
	  x[i-1]=x[i]-x[i-1]-1;
	sort(x+1,x+n);
	p=n;
	for(i=1;i<=n-q;i++)
	  p+=x[i];
	cout<<p;
	return 0;
}