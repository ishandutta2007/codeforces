#include<bits/stdc++.h>
using namespace std;
#define ll long long

int a[200010],b[200010],n;
bool bo[200010];

inline ll rd()
{
	ll x=0,f=1;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') f=-1;
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x*f;
}

inline bool pre_check()
{
	bool flag=false;
	for (int i=1;i<=n;i++) if (b[i]==1) flag=true;
	if (!flag) return false;
	int id=0;
	for (int i=1;i<=n;i++) if (b[i]==1) id=i;
	for (int j=id;j<=n;j++) if (b[j]!=j-id+1) return false;
	int hh=n-id+1;
	for (int i=1;i<id;i++) if (b[i]>0&&b[i]<=hh+i) return false;
	return true;
}

inline bool check(int mid)
{
	memset(bo,false,sizeof(bo));
	for (int i=1;i<=n;i++) if (a[i]) bo[a[i]]=true;
	for (int i=1;i<=mid;i++) if (b[i]) bo[b[i]]=true;
	for (int i=mid+1;i<=n;i++) if (b[i]>0&&i-mid>=b[i]) return false;
	return true;
}

int main()
{
	n=rd();
	for (int i=1;i<=n;i++) a[i]=rd();
	for (int i=1;i<=n;i++) b[i]=rd();
	if (pre_check())
	{
		for (int i=1;i<=n;i++) if (b[i]==1) printf("%d\n",i-1);
		return 0;
	}
	int l=0,r=n;
	while (l<r)
	{
		int mid=(l+r)>>1;
		if (check(mid)) r=mid;
		else l=mid+1;
	}
	printf("%d\n",l+n);
	return 0;
}