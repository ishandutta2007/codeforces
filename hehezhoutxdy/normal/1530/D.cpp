// Problem: D. Secret Santa
// Contest: Codeforces - Codeforces Round #733 (Div. 1 + Div. 2, based on VK Cup 2021 - Elimination (Engine))
// URL: https://codeforces.com/contest/1530/problem/D
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//And in that light,I find deliverance.
#include<bits/stdc++.h>
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int a[1000003],ans[1000003];
bool vis[1000003];
signed main()
{
	for(int T=read();T--;)
	{
		int n=read();
		for(int i=1; i<=n; ++i) vis[i]=0,a[i]=read(),ans[i]=0;
		for(int i=1; i<=n; ++i) if(!vis[a[i]]) ans[i]=a[i],vis[a[i]]=1;
		stack<int> s;
		for(int i=1; i<=n; ++i)
		if(!vis[i])
		s.push(i);
		for(int i=1; i<=n; ++i) if(!ans[i])
		{
			ans[i]=s.top();
			s.pop();
		}
		for(int i=1; i<=n; ++i) if(ans[i]==i)
		{
			if(s.empty())
			{
				s.push(i);
				continue;
			}
			swap(ans[i],ans[s.top()]);s.pop();
		}
		if(!s.empty())for(int i=1; i<=n; ++i) if(a[i]==a[s.top()])
		{
			swap(ans[i],ans[s.top()]);
			s.pop();
			break;
		}
		assert(s.empty());
		int A=0;
		for(int i=1; i<=n; ++i) A+=(ans[i]==a[i]);
		printf("%d\n",A);
		for(int i=1; i<=n; ++i) printf("%d ",ans[i]);
		puts("");
	}
	return 0;
}