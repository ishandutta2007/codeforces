#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll a[30],b[30],f[30],n,l,r,ans;

inline ll rd()
{
	ll x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline bool check(int x,int y,int bl,int br)
{
	if (!y) return true;
	if (!x) return false;
	if (!bl&&!br) return true;
	int l=(bl)?a[x]:0,r=(br)?b[x]:9;
	for (int i=l;i<=r;i++)
	{
		if (!f[i]) continue;
		f[i]--;
		bool flag=check(x-1,y-1,bl&&(a[x]==i),br&&(b[x]==i));
		f[i]++;
		if (flag) return true;
	}
	return false;
}

inline void dfs(int x,int y,int z)
{
	if (x>=10) { ans+=(z==n&&check(n,n,1,1));return; }
	for (int i=0;i<=y;i++) f[x]=i,dfs(x+1,y-i,z+i);
}

int main()
{
	l=rd();r=rd();
	for (n=0;l;l/=10) a[++n]=l%10;
	for (n=0;r;r/=10) b[++n]=r%10;
	dfs(0,n,0);
	printf("%lld\n",ans);
	return 0;
}