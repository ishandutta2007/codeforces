// Problem: C. Anonymity Is Important
// Contest: Codeforces Round #773 (Div. 1)
// URL: https://codeforces.com/contest/1641/problem/C
// Memory Limit: 256 MB
// Time Limit: 1500 ms
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
int tag[1000003],ans[1000003],ttt[1000003];
void update(int l,int r,int L,int R,int id,int tt)
{
	if(tag[id]) return ;
	if(L<=l && r<=R) 
	{
		tag[id]=1;
		ans[id]=r-l+1;
		ttt[id]=tt;
		return ;
	}
	int mid=(l+r)>>1;
	if(L<=mid) update(l,mid,L,R,id<<1,tt);
	if(R>=mid+1) update(mid+1,r,L,R,(id<<1)+1,tt);
	ans[id]=ans[(id<<1)]+ans[(id<<1)+1];
	return ;
}
int query(int l,int r,int L,int R,int id)
{
	if(tag[id])
	{
		int zr=min(r,R),zl=max(l,L);
		return zr-zl+1;
	}
	if(L<=l && r<=R) return ans[id];
	int mid=(l+r)>>1;
	int res=0;
	if(L<=mid) res+=query(l,mid,L,R,id<<1);
	if(R>=mid+1) res+=query(mid+1,r,L,R,(id<<1)+1);
	return res;
}
int sta[1000003],Tm[1000003],TTT[1000003],tmd[1000003];
void build(int l,int r,int id,int cur=0x3f3f3f3f)
{
	if(tag[id]) cur=min(cur,ttt[id]);
	if(l==r) 
	{
		if(cur!=0x3f3f3f3f)
		sta[l]=0,TTT[id]=Tm[l]=cur,tmd[id]=0x3f3f3f3f;
		else tmd[id]=l;
		return ;
	}
	int mid=(l+r)>>1;
	build(l,mid,id<<1,cur),build(mid+1,r,(id<<1)+1,cur);
	TTT[id]=max(TTT[id<<1],TTT[(id<<1)+1]);
	tmd[id]=min(tmd[id<<1],tmd[(id<<1)+1]);
	return ;
}
int Query(int l,int r,int L,int R,int id)
{
	if(L<=l && r<=R) return TTT[id];
	int mid=(l+r)>>1;
	int res=0;
	if(L<=mid) res=max(res,Query(l,mid,L,R,id<<1));
	if(R>=mid+1) res=max(res,Query(mid+1,r,L,R,(id<<1)+1));
	return res;
}
int Query1(int l,int r,int L,int R,int id)
{
	if(L<=l && r<=R) return tmd[id];
	int mid=(l+r)>>1;
	int res=0x3f3f3f3f;
	if(L<=mid) res=min(res,Query1(l,mid,L,R,id<<1));
	if(R>=mid+1) res=min(res,Query1(mid+1,r,L,R,(id<<1)+1));
	return res;
}
int op[500003],x[500003],y[500003],k[500003];
signed main()
{
	// memset(ttt,0x3f,sizeof(ttt)),
	memset(sta,-1,sizeof(sta)),
	memset(Tm,0x3f,sizeof(Tm));
	int n=read(),m=read();
	for(int i=1; i<=m; ++i)
	{
		op[i]=read(),x[i]=read();
		if(op[i]==0) y[i]=read(),k[i]=read();
	}
	for(int i=1; i<=m; ++i) if(!op[i]&&k[i]==0)
		update(1,n,x[i],y[i],1,i);
	build(1,n,1);
	for(int i=1; i<=m; ++i) if(!op[i]&&k[i]==1)
	{
		int z=query(1,n,x[i],y[i],1);
		// printf("%d %d %d\n",x[i],y[i],z);
		if(y[i]-x[i]==z)
		{
			int o=Query1(1,n,x[i],y[i],1);
			sta[o]=1,Tm[o]=
			min(Tm[o],max(Query(1,n,x[i],y[i],1),i));
			// printf("%d\n",o);
		} 
	}
	// for(int i=1; i<=n; ++i) printf("%d %d\n",sta[i],Tm[i]);
	for(int i=1; i<=m; ++i) if(op[i]) {
	if(sta[x[i]]==-1) puts("N/A");
	else if(Tm[x[i]]>i) puts("N/A");
	else
	{
		if(sta[x[i]]) puts("YES");
		else puts("NO");
	}
	}
	return 0;
}