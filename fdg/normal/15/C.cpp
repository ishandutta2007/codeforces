#include <cstdio>

#define ll long long

using namespace std;

ll XorInt(ll a)
{
	if (a%4==0) return a;
	if (a%4==1) return 1;
	if (a%4==2) return a+1;
	return 0;
}

ll XorSegment(ll a,ll b)
{
	return XorInt(b)^XorInt(a-1);
}

int main()
{
	ll n,m,x,ans=0;
	scanf("%I64d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%I64d%I64d",&x,&m);
		ans^=XorSegment(x,x+m-1);
	}
	if (ans==0) printf("bolik\n");
	else printf("tolik\n");
	return 0;
}