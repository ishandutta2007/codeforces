#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll a[1000010],b[1000010],m;
int L[1000010],R[1000010],mx[1000010],n;

inline ll rd()
{
	ll x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline int min(const int &x,const int &y) { return (x<y)?x:y; }
inline int max(const int &x,const int &y) { return (x>y)?x:y; }

inline bool check(ll mid)
{
	int l=1,r=0;
	for (int i=1;i<=n*2;i++)
	{
		while (l<=n*4&&b[l]<a[i]-mid) l++;
		while (r+1<=n*4&&b[r+1]<=a[i]+mid) r++;
		if (l>r) return false;
		L[i]=l;R[i]=r;
	}
	mx[n*2]=n*2-R[n*2];
	for (int i=n*2;i;i--)
	{
		if (i<n*2) mx[i]=max(mx[i+1],i-R[i]);
		if (mx[i]>i-L[i]) return false;
	}
	return true;
}

int main()
{
	n=rd();m=rd();
	for (int i=1;i<=n;i++) a[i]=rd();
	for (int i=1;i<=n;i++) b[i]=rd();
	sort(a+1,a+n+1);
	sort(b+1,b+n+1);
	for (int i=1;i<=n;i++) a[i]+=m,a[i+n]=a[i]+m;
	for (int i=1;i<=n;i++) b[i+n]=b[i]+m,b[i+n*2]=b[i+n]+m,b[i+n*3]=b[i+n*2]+m;
	ll l=0,r=m-1;
	while (l<r)
	{
		ll mid=(l+r)>>1;
		if (check(mid)) r=mid;
		else l=mid+1;
	}
	printf("%lld\n",l);
	return 0;
}