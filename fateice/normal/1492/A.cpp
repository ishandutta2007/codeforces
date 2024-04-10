#include<bits/stdc++.h>
#define L long long
#define vi vector<int>
#define pb push_back
#define pi pair<int,int>
#define fi first
#define se second
#define mp make_pair
using namespace std;
int t;
L p,a,b,c;
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld%lld%lld%lld",&p,&a,&b,&c);
		printf("%lld\n",min((p-1)/a*a+a,min((p-1)/b*b+b,(p-1)/c*c+c))-p);
	}
	return 0;
}