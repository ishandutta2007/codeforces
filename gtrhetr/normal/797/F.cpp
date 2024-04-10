#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 2333333333333333333LL

struct node { ll x,c; }a[2000010];
struct Stack
{
	int tot=0;ll tag=0;
	ll st[4000010];
	inline bool empty() { return (!tot); }
	inline void push(ll x) { st[++tot]=x-tag; }
	inline ll top() { return st[tot]+tag; }
	inline void pop() { tot--; }
	inline void modify(ll hh) { tag+=hh; }
}zheng,fu;

stack<int> st;

ll num[2000010],num1[2000010],n,m,ans;

inline ll rd()
{
	ll x=0,f=1;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') f=-1;
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x*f;
}

inline bool cmp(const node &x,const node &y) { return x.x<y.x; }

int main()
{
	n=rd();m=rd();
	for (int i=1;i<=n;i++) a[i].x=rd();
	ll sum=0;
	for (int i=1;i<=m;i++) a[i+n].x=rd(),a[i+n].c=rd(),sum+=a[i+n].c;
	if (sum<n) { puts("-1");return 0; }
	n+=m;
	sort(a+1,a+n+1,cmp);
	while (!st.empty()) st.pop();
	for (int i=1;i<=n;i++)
	{
		if (!a[i].c)
		{
			if (!st.empty()) num[st.top()]++;
			if (!st.empty()&&num[st.top()]==a[st.top()].c) st.pop();
		}
		else st.push(i);
	}
	while (!st.empty()) st.pop();
	for (int i=n;i;i--)
	{
		if (!a[i].c)
		{
			if (!st.empty()) num1[st.top()]++;
			if (!st.empty()&&num1[st.top()]==a[st.top()].c) st.pop();
		}
		else st.push(i);
	}
	for (int i=1;i<=n;i++) num[i]=min(num[i]+num1[i],a[i].c);
	ans=0LL;
	for (int i=1;i<=n;i++)
	{
		if (!a[i].c)
		{
			zheng.modify(-a[i].x);zheng.push(ans-a[i].x);
			ans=inf;
			if (!fu.empty())
			{
				ans=min(ans,fu.top()+a[i].x);
				fu.pop();fu.modify(a[i].x);
			}
		}
		else for (int hhhh=1;hhhh<=num[i];hhhh++)
		{
			if (ans!=inf) fu.modify(-a[i].x),fu.push(ans-a[i].x);
			if (!zheng.empty())
			{
				ans=min(ans,zheng.top()+a[i].x);
				zheng.pop();zheng.modify(a[i].x);
			}
		}
	}
	printf("%I64d\n",ans);
	return 0;
}