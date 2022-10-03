#include<bits/stdc++.h>
using namespace std;
#define inf 2123333333

int tag[1000010];
int l[1000010],r[1000010];
int num[1000010],ans[1000010],n,q;

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline void pushdown(int o)
{
	if (!tag[o]) return;
	tag[o<<1]=tag[o<<1|1]=tag[o];
	tag[o]=0;
}

inline void modify(int o,int l,int r,int x,int y,int hh)
{
	if (l>=x&&r<=y) { tag[o]=hh;return; }
	pushdown(o);
	int mid=(l+r)>>1;
	if (x<=mid) modify(o<<1,l,mid,x,y,hh);
	if (y>mid) modify(o<<1|1,mid+1,r,x,y,hh);
}

inline void gao(int o,int l,int r)
{
	if (l==r) { ans[l]=tag[o];return; }
	pushdown(o);
	int mid=(l+r)>>1;
	gao(o<<1,l,mid);gao(o<<1|1,mid+1,r);
}

int main()
{
	n=rd();q=rd();
	for (int i=1;i<=n;i++) num[i]=rd();
	for (int i=1;i<=q;i++) l[i]=inf;
	int cnt=0;
	for (int i=1;i<=n;i++) if (!num[i]) cnt++;
	if (!cnt)
	{
		for (int i=1;i<=n;i++) l[num[i]]=min(l[num[i]],i),r[num[i]]=max(r[num[i]],i);
		l[q+1]=inf;
		for (int i=q;i;i--) if (l[i]>r[i]) l[i]=l[i+1],r[i]=r[i+1];
		for (int i=1;i<=q;i++) if (l[i]>r[i]) { puts("NO");return 0; }
		for (int i=1;i<=q;i++) modify(1,1,n,l[i],r[i],i);
		gao(1,1,n);
		bool flag=true;
		for (int i=1;i<=n;i++) if (num[i]!=ans[i]) flag=false;
		if (!flag) { puts("NO");return 0; }
		puts("YES");
		for (int i=1;i<=n;i++) printf("%d ",ans[i]);
		puts("");
		return 0;
	}
	int id=0;
	for (int i=1;i<=n;i++) if (!num[i]) id=i;
	for (int i=1;i<=n;i++) l[num[i]]=min(l[num[i]],i),r[num[i]]=max(r[num[i]],i);
	l[1]=1;r[1]=n;
	for (int i=q;i;i--) if (l[i]>r[i]) l[i]=r[i]=id;
	for (int i=1;i<=q;i++) modify(1,1,n,l[i],r[i],i);
	gao(1,1,n);
	bool flag=true;
	for (int i=1;i<=n;i++) if (num[i]!=0&&num[i]!=ans[i]) flag=false;
	if (!flag) { puts("NO");return 0; }
	puts("YES");
	for (int i=1;i<=n;i++) printf("%d ",ans[i]);
	puts("");
	return 0;
}