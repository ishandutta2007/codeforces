#include<bits/stdc++.h>
using namespace std;

multiset<int> st;

int p[200010],num[200010],l[200010],r[200010],n,tt;

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline void del(int x)
{
	st.erase(st.find(x));
}

inline void gao(int *ans)
{
	static int a[200010],f[200010];
	st.clear();int top=0;
	for (int i=1;i<=tt;i++)
	{
		int now=0;
		while (top>0&&num[a[top]]<num[i])
		{
			del(f[top]+top);
			now=max(now,f[top])+1;
			top--;
		}
		a[++top]=i;f[top]=now;
		st.insert(now+top);
		ans[i]=*st.rbegin();
	}
}

int main()
{
	n=rd();
	for (int i=1;i<=n;i++) p[i]=n-rd()+1;
	if (n==1) { puts("1 0");return 0; }
	int id=0;
	for (int i=1;i<=n;i++) if (p[i]>p[id]) id=i;
	tt=0;
	for (int i=1;i<n;i++) num[++tt]=p[(id+i-1)%n+1];
	gao(r);
	tt=0;
	for (int i=1;i<n;i++) num[++tt]=p[(id-i+n-1)%n+1];
	gao(l);
	int ans=r[n-1],res=0;
	for (int i=1;i<=n-1;i++)
	{
		if (max(l[i],r[n-1-i])<ans) ans=max(l[i],r[n-1-i]),res=i;
	}
	printf("%d %d\n",ans+1,((id-1)-res+n)%n);
	return 0;
}