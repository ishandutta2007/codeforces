#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct tree { int ls,rs,sum;ll mn; }t[5000010];

int tot;
ll num[100010],n,m,k,A,B;
int rt;

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline void pushup(int o,ll l,ll r)
{
	if (!t[o].sum) { t[o].mn=A;return; }
	t[o].mn=t[o].sum*(r-l+1)*B;
	ll h1,h2;
	if (t[o].ls) h1=t[t[o].ls].mn;
	else h1=A;
	if (t[o].rs) h2=t[t[o].rs].mn;
	else h2=A;
	t[o].mn=min(t[o].mn,h1+h2);
}

inline void modify(int &o,int l,int r,int hh)
{
	if (!o) o=++tot;
	t[o].sum++;
	if (l==r)
	{
		t[o].mn=t[o].sum*B;
		return;
	}
	int mid=(l+r)>>1;
	if (hh<=mid) modify(t[o].ls,l,mid,hh);
	else modify(t[o].rs,mid+1,r,hh);
	pushup(o,l,r);
}

int main()
{
	n=rd();k=rd();A=rd();B=rd();
	for (int i=1;i<=k;i++) num[i]=rd();
	m=(1<<n);
	rt=tot=1;
	t[rt].mn=A;
	for (int i=1;i<=k;i++) modify(rt,1,m,num[i]);
	printf("%I64d\n",t[rt].mn);
	return 0;
}