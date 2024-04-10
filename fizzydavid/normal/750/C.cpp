//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back 
#define MP make_pair
typedef long long ll;
const ll INF=1<<28;
const ll LINF=1ll<<61;
int n;
int main()
{
	ll l=-(1ll<<60),r=(1ll<<60);
	scanf("%d",&n);
	ll dlt=0;
	for(int i=1;i<=n;i++)
	{
		int x,d;
		scanf("%d%d",&x,&d);
		if(d==1)
		{
			l=max(l,1900-dlt);
		}
		else
		{
			r=min(r,1899-dlt);
		}
		dlt+=x;
	}
	if(r>(1ll<<40))puts("Infinity");
	else if(l>r)puts("Impossible");
	else cout<<r+dlt<<endl;
	return 0;
}