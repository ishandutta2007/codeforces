#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,m;
struct unionFindSet{
	LL fa[1000005];
	void makeSet(LL up){for(LL i=0;i<=up;++i)	fa[i]=i;}
	LL findSet(LL x){return x==fa[x]?x:fa[x]=findSet(fa[x]);}
};
LL a[1000005];
struct Tree1{
	unionFindSet ufs;
private:
	LL L[1000005],R[1000005],siz[1000005],tag[4000005],cnt,dfn;
	vector<LL> G[1000005];
public:
	LL unionSet(LL x,LL y)
	{
		LL xx=ufs.findSet(x),yy=ufs.findSet(y);
		++cnt;
		G[cnt].push_back(xx),G[cnt].push_back(yy);
		return ufs.fa[xx]=ufs.fa[yy]=ufs.fa[cnt]=cnt;
	}
	void dfs(LL now)
	{
		L[now]=++dfn;
		siz[now]=LL(now<=n);
		for(auto st:G[now])	dfs(st),siz[now]+=siz[st];
		R[now]=dfn;
	}
	void init(){ufs.makeSet(cnt=n);}
	void init2(){for(LL i=1;i<=cnt;++i)	if(ufs.findSet(i)==i)	dfs(i);}
private:
	#define lc(x) (x<<1)
	#define rc(x) (lc(x)|1)
	#define Mm LL mid=(l+r)>>1
	void push_down(LL now){if(tag[now])	tag[lc(now)]+=tag[now],tag[rc(now)]+=tag[now],tag[now]=0;}
	void modify(LL l,LL r,LL now,LL x,LL y,LL val)
	{
		if(x<=l && r<=y)
		{
			tag[now]+=val;
			return ;
		}
		Mm;
		push_down(now);
		if(x<=mid)	modify(l,mid,lc(now),x,y,val);
		if(mid<y)	modify(mid+1,r,rc(now),x,y,val);
	}
	LL query(LL l,LL r,LL now,LL pos)
	{
		if(l==r)	return tag[now];
		push_down(now);
		Mm;
		if(pos<=mid)	return query(l,mid,lc(now),pos);
		return query(mid+1,r,rc(now),pos);
	}
	#undef lc
	#undef rc
	#undef Mm
public:
	void modifyPoint(LL x){modify(1,cnt,1,L[x],R[x],siz[x]);}
	LL queryPoint(LL x){return query(1,cnt,1,L[x]);}
}t1;
struct Tree2{
	unionFindSet ufs;
private:
	LL L[1000005],R[1000005],tag[4000005],cnt,dfn;
	vector<LL> G[1000005];
public:
	LL unionSet(LL x,LL y)
	{
		LL xx=ufs.findSet(x),yy=ufs.findSet(y);
		++cnt;
		G[cnt].push_back(xx),G[cnt].push_back(yy);
		return ufs.fa[xx]=ufs.fa[yy]=ufs.fa[cnt]=cnt;
	}
	void dfs(LL now)
	{
		L[now]=++dfn;
		for(auto st:G[now])	dfs(st);
		R[now]=dfn;
	}
	void init(){ufs.makeSet(cnt=n);}
	void init2(){for(LL i=1;i<=cnt;++i)	if(ufs.findSet(i)==i)	dfs(i);}
private:
	#define lc(x) (x<<1)
	#define rc(x) (lc(x)|1)
	#define Mm LL mid=(l+r)>>1
	void push_down(LL now){if(tag[now])	tag[lc(now)]=tag[rc(now)]=tag[now],tag[now]=0;}
	void modify(LL l,LL r,LL now,LL x,LL y,LL val)
	{
		if(x<=l && r<=y)
		{
			tag[now]=val;
			return ;
		}
		Mm;
		push_down(now);
		if(x<=mid)	modify(l,mid,lc(now),x,y,val);
		if(mid<y)	modify(mid+1,r,rc(now),x,y,val);
	}
	LL query(LL l,LL r,LL now,LL pos)
	{
		if(l==r)	return tag[now];
		push_down(now);
		Mm;
		if(pos<=mid)	return query(l,mid,lc(now),pos);
		return query(mid+1,r,rc(now),pos);
	}
	#undef lc
	#undef rc
	#undef Mm
public:
	void modifyPoint(LL x){modify(1,cnt,1,L[a[x]],R[a[x]],x);}
	LL queryPoint(LL x){return query(1,cnt,1,L[a[x]]);}
}t2;
char ost[2];
LL op[500005],ans[500005];
vector<pair<LL,LL>> G[500005];
#define mp make_pair
int main(){
	scanf("%lld %lld",&n,&m);
	t1.init(),t2.init();
	for(LL i=1;i<=m;++i)
	{
		scanf("%s %lld",ost,&a[i]);
		if(*ost=='U')
		{
			op[i]=1;
			LL x;
			scanf("%lld",&x);
			a[i]=t1.unionSet(a[i],x);
		}
		else if(*ost=='M')
		{
			op[i]=2;
			LL x;
			scanf("%lld",&x);
			a[i]=t2.unionSet(a[i],x);
		}
		else if(*ost=='A')	op[i]=3,a[i]=t1.ufs.findSet(a[i]);
		else if(*ost=='Z')	op[i]=4,a[i]=t2.ufs.findSet(a[i]);
		else	op[i]=5;
	}
	t1.init2(),t2.init2();
	for(LL i=1;i<=m;++i)
	{
		if(op[i]==4)	t2.modifyPoint(i);
		else if(op[i]==5)	G[t2.queryPoint(i)].push_back(mp(a[i],i));
	}
	for(LL i=1;i<=m;++i)
	{
		if(op[i]==3)	t1.modifyPoint(a[i]);
		else if(op[i]==4)	for(auto st:G[i])	ans[st.second]-=t1.queryPoint(st.first);
		else if(op[i]==5)	ans[i]+=t1.queryPoint(a[i]);
	}
	for(LL i=1;i<=m;++i)	if(op[i]==5)	printf("%lld\n",ans[i]);
	return 0;
}
#undef mp