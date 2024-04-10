// Problem: E. Lexicographically Small Enough
// Contest: Good Bye 2021: 2022 is NEAR
// URL: https://codeforces.com/contest/1616/problem/E
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//And in that light,I find deliverance.
#include<bits/stdc++.h>
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
#define int long long
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
char s[1000003],t[1000003],S[1000003];
int tree[1000003];
int n;
void add(int x,int k)
{
	while(x<=n) tree[x]+=k,x+=x&(-x);
	return ;
}
int find(int x)
{
	int res=0;
	while(x) res+=tree[x],x-=x&(-x);
	return res;
}
inline int Find(int x)
{
	return x+find(x);
}
signed main()
{
	for(int T=read();T--;)
	{
		n=read();
		for(int i=1; i<=n; ++i) tree[i]=0;
		scanf("%s",s+1);
		scanf("%s",t+1);
		for(int i=1; i<=n; ++i) S[i]=s[i];
		sort(S+1,S+n+1);
		int f=0;
		for(int i=1; i<=n; ++i) if(S[i]<t[i]) {f=1;break;}
		else if(S[i]>t[i]) {f=-1;break;}
		if(f!=1) 
		{
			puts("-1");
			continue;
		} 
		f=0;
		for(int i=1; i<=n; ++i) if(s[i]<t[i]) {f=1;break;}
		else if(s[i]>t[i]) {f=-1;break;}
		if(f==1)
		{
			puts("0");
			continue;
		}
		queue<int> q[26];
		for(int i=1; i<=n; ++i) q[s[i]-'a'].push(i);
		int ans=1e18,cur=0;
		for(int i=1; i<=n; ++i)
		{
			int pos=0;
			for(int j='a'; j<t[i]; ++j) if(!q[j-'a'].empty())
				ans=min(ans,cur+Find(q[j-'a'].front())-i);
			if(q[t[i]-'a'].empty()) break;
			else
			{
				cur+=Find(q[t[i]-'a'].front())-i;
				add(1,1),add(q[t[i]-'a'].front()+1,-1);
				q[t[i]-'a'].pop();
			} 
		} 
		printf("%lld\n",ans);
	}
	return 0;
}