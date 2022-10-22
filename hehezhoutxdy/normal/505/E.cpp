// Problem: CF505E Mr. Kitayuta vs. Bamboos
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF505E
// Memory Limit: 250 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//And in that light,I find deliverance.
#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int a[100003],b[100003];
int n=read(),m=read(),k=read(),p=read();
int h[100003];
struct cmp
{
	bool operator()(const int&A,const int&B)
	{
		return h[A]/b[A]>h[B]/b[B];
	}
};
priority_queue<int,vector<int>,cmp> q;
bool check(int x)
{
	while(!q.empty()) q.pop();
	for(int i=1; i<=n; ++i) h[i]=x;
	for(int i=1; i<=n; ++i) if(x-m*b[i]<a[i]) q.push(i);
	for(int i=1; i<=m; ++i)
	{
		if(q.empty()) return 1;
		int t=q.top();
		if(h[t]/b[t]<i) return 0;
		for(int j=1; j<=k; ++j) 
		{
			if(q.empty()) return 1;
			int t=q.top();
			q.pop(),h[t]+=p;
			if(h[t]-m*b[t]<a[t]) q.push(t);
		}
	}
	return q.empty();
}
signed main()
{
	int l=1,r=1e13,ans=1e13;
	for(int i=1; i<=n; ++i) a[i]=read(),b[i]=read();
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(check(mid)) ans=mid,r=mid-1;
		else l=mid+1;
	}
	printf("%lld\n",ans);
	return 0;
}