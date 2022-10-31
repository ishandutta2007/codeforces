#include<cstdio>
#include<algorithm>
#include<cstring>
#define IT std::vector<int>::iterator

typedef long long ll;

const int N=3005;
ll a[N],b[N];
int n;
ll h;
bool check(int x)
{
	ll H=h;
	//memcpy(b,a,8*(x+1));
	for(int i=1;i<=x;++i) b[i]=a[i];
	std::sort(b+1,b+x+1);
	if(x&1)
	{
		int l=2;
		H-=b[1];
		while(l<x)
		{
			H-=b[l+1];
			l+=2;
		}
		return H>=0;
	}
	else
	{
		int l=1;
		while(l<x)
		{
			H-=b[l+1];
			l+=2;
		}
		return H>=0;
	}
}
int main()
{
	scanf("%d %lld",&n,&h);
	for(int i=1;i<=n;++i) scanf("%lld",&a[i]);
	int l=1,r=n;
	while(l<r)
	{
		int mid=(l+r+1)>>1;
		if(check(mid)) l=mid;
		else r=mid-1;
	}
	printf("%d\n",l);
	return 0;
}
//Dpair AK IOI