#include<bits/stdc++.h>
using namespace std;
#define next drhgbteet

int sum[500010],num[500010];
int a[500010],b[500010],next[500010],lst[500010],m,k,n,s;
bool bo[500010];

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline bool check(int x)
{
	for (int i=1;i<=x;i++) sum[a[i]]++;
	bool flag=true;
	for (int i=1;i<=500000;i++) if (sum[i]<num[i]) flag=false;
	for (int i=1;i<=x;i++) sum[a[i]]--;
	return flag; 
}

inline void gao_ans(int l,int r,int tt,int ttt)
{
	memset(sum,0,sizeof(sum));
	int res=0,now=0;
	for (int i=1;i<=ttt;i++) bo[i]=true;
	for (int i=l;i<=r;i++)
	{
		sum[a[i]]++;
		if (sum[a[i]]>num[a[i]])
		{
			if (now<tt) res++,bo[i]=true,now++;
		}
	}
	printf("%d\n",res);
	for (int i=1;i<=m;i++) if (bo[i]) printf("%d ",i);
	puts("");
}

int main()
{
	m=rd();k=rd();n=rd();s=rd();
	for (int i=1;i<=m;i++) a[i]=rd();
	for (int i=1;i<=s;i++) b[i]=rd();
	int tt=m-n*k;
	for (int i=1;i<=s;i++) num[b[i]]++;
	int l=1,r=m;
	while (l<r)
	{
		int mid=(l+r)>>1;
		if (check(mid)) r=mid;
		else l=mid+1;
	}
	if (!check(l)) { puts("-1");return 0; }
	for (int i=1;i<=l;i++) sum[a[i]]++;
	for (int i=1;i<=m;i++)
	{
		if (l-i+1<=k) { puts("0");return 0; }
		int hhh=(i-1>(n-1)*k)?(i-1-(n-1)*k):(i-1)%k;
		int hh=l-i+1-k;
		if (hh+hhh<=tt) { gao_ans(i,l,hh,hhh);return 0; }
		sum[a[i]]--;
		while (l<m&&sum[a[i]]<num[a[i]]) sum[a[++l]]++;
		if (sum[a[i]]<num[a[i]]) { puts("-1");return 0; }
	}
	puts("-1");
	return 0;
}