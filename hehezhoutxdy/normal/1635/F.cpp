// Problem: F. Closest Pair 
// Contest: Codeforces Round #772 (Div. 2)
// URL: https://codeforces.com/contest/1635/problem/F
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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
int ans[1200003];
void update(int l,int r,int x,int id,int val)
{
	if(l==r) 
	{
		ans[id]=min(ans[id],val);
		return ;
	}
	int mid=(l+r)>>1;
	if(x<=mid) update(l,mid,x,id<<1,val);
	else update(mid+1,r,x,(id<<1)+1,val);
	ans[id]=min(ans[(id<<1)],ans[(id<<1)+1]);
	return ;
}
int query(int l,int r,int L,int R,int id)
{
	if(L<=l && r<=R) return ans[id];
	int mid=(l+r)>>1;
	int res=0x3f3f3f3f3f3f3f3f;
	if(L<=mid) res=min(res,query(l,mid,L,R,id<<1));
	if(R>=mid+1) res=min(res,query(mid+1,r,L,R,(id<<1)+1));
	return res;
}
struct node
{
	int l,id;
};
vector<node> e[300003];
int Ans[300003],a[300003],w[300003];
signed main()
{
	memset(ans,0x3f,sizeof(ans));
	int n=read(),m=read();
	for(int i=1; i<=n; ++i) a[i]=read(),w[i]=read();
	for(int i=1; i<=m; ++i)
	{
		int l=read(),r=read();
		e[r].push_back((node){l,i});
	}
	stack<int> stk;
	for(int i=1; i<=n; ++i)
	{
		while(!stk.empty())
		{
			int A=stk.top();
			update(1,n,A,1,(a[i]-a[A])*(w[i]+w[A]));
			if(w[A]>w[i])//i
				stk.pop();
			else break;
		}
		stk.push(i);
		for(node j:e[i])
			Ans[j.id]=query(1,n,j.l,i,1);
	}
	for(int i=1; i<=m; ++i) printf("%lld\n",Ans[i]);
	return 0;
}