// Problem: G. Fishingprince Plays With Array Again
// Contest: Codeforces - Codeforces Global Round 21
// URL: https://codeforces.com/contest/1696/problem/G
// Memory Limit: 1024 MB
// Time Limit: 6000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//
#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
#define int long long
#define ld long double
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
//first&last status
struct node{ld v[3][3];}f[1000003];
int n=read(),m=read(),tx=read(),ty=read(),X=min(tx,ty),Y=max(tx,ty);	
ld d=1.0L*Y/X,s2=1.0L/d,s1=1.0L/(d+1);
node merge(node x,node y)
{
	node f;
	for(int i=0; i<3; ++i)
		for(int j=0; j<3; ++j)
			f.v[i][j]=-1e18;
	for(int i=0; i<3; ++i)
		for(int j=0; j<3; ++j)
			for(int k=0; j+k<3; ++k)
				for(int l=0; l<3; ++l)
					f.v[i][l]=max(f.v[i][l],
					x.v[i][j]+y.v[k][l]);
	return f;
}
ld getans(node x)
{
	ld res=-1e18;
	for(int i=0; i<3; ++i)
		for(int j=0; j<3; ++j)
			res=max(res,x.v[i][j]);
	return res;
}
void build(int l,int r,int id)
{
	for(int i=0; i<3; ++i)
		for(int j=0; j<3; ++j)
			f[id].v[i][j]=-1e18;
	if(l==r) 
	{
		int val=read();
		f[id].v[0][0]=0,
		f[id].v[1][1]=s1*val,
		f[id].v[2][2]=s2*val;
		return ;
	}
	int mid=(l+r)>>1;
	build(l,mid,id<<1),build(mid+1,r,(id<<1)+1),
	f[id]=merge(f[id<<1],f[(id<<1)+1]);
	return ;
}
void update(int l,int r,int x,int id,int val)
{
	if(l==r) 
	{
		f[id].v[0][0]=0,
		f[id].v[1][1]=s1*val,
		f[id].v[2][2]=s2*val;
		return ;
	}
	int mid=(l+r)>>1;
	if(x<=mid) update(l,mid,x,id<<1,val);
	else update(mid+1,r,x,(id<<1)+1,val);
	f[id]=merge(f[id<<1],f[(id<<1)+1]);
	return ;
}
node query(int l,int r,int &L,int &R,int id)
{
	if(L<=l&&r<=R) return f[id];
	int mid=(l+r)>>1;
	if(L>mid) return query(mid+1,r,L,R,(id<<1)+1);
	if(R<=mid) return query(l,mid,L,R,id<<1);
	return merge(query(l,mid,L,R,id<<1),query(mid+1,r,L,R,(id<<1)+1));
}
signed main()
{
	build(1,n,1);
	for(int op,x,y; m--;)
	{
		op=read(),x=read(),y=read();
		if(op==1) update(1,n,x,1,y);
		else printf("%.10Lf\n",getans(query(1,n,x,y,1))/X);
	}	
	return 0;
}