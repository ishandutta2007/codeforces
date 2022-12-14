#include<iostream>
#include<cstdlib>
#include<vector>
#include<cstdio>
#define MN 300000
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
struct Tree{int l,r;long long mn,val;}T[MN*25+5];
int n,m,head[MN+5],cnt=0,rt[MN+5],dep[MN+5];long long w[MN+5];
struct edge{int to,next;}e[MN*2+5];
vector<pair<int,int> >v[MN+5];
inline void ins(int f,int t)
{
	e[++cnt]=(edge){t,head[f]};head[f]=cnt;
	e[++cnt]=(edge){f,head[t]};head[t]=cnt;	
}
inline int newnode(int x=0){return x?x:(T[++cnt].mn=1e18,cnt);}
inline void Mark(int x,long long v){T[x].val+=v;T[x].mn+=v;}
void pushdown(int x){if(T[x].l)Mark(T[x].l,T[x].val);if(T[x].r)Mark(T[x].r,T[x].val);T[x].val=0;}
long long Query(int x,int lt,int rt,int l,int r)
{
//	cout<<"Query"<<x<<" "<<lt<<" "<<rt<<" "<<l<<" "<<r<<endl;
	if(!x) return 1e18;
	if(lt==l&&rt==r) return T[x].mn;
	int mid=lt+rt>>1;if(T[x].val) pushdown(x);
	if(r<=mid) return Query(T[x].l,lt,mid,l,r);
	else if(l>mid) return Query(T[x].r,mid+1,rt,l,r);
	else return min(Query(T[x].l,lt,mid,l,mid),Query(T[x].r,mid+1,rt,mid+1,r));	
}
void Modify(int x,int lt,int rt,int k,long long v)
{
	//cout<<"Modify"<<x<<" "<<lt<<" "<<rt<<" "<<k<<" "<<v<<endl;
	if(lt==rt){T[x].mn=min(T[x].mn,v);return;}
	int mid=lt+rt>>1;if(T[x].val) pushdown(x);
	if(k<=mid) Modify(T[x].l=newnode(T[x].l),lt,mid,k,v);
	else Modify(T[x].r=newnode(T[x].r),mid+1,rt,k,v);
	T[x].mn=min(T[T[x].l].mn,T[T[x].r].mn);
} 
int Merge(int x,int y,int lt=1,int rt=n)
{
	if(!x||!y)return x+y;
	if(lt==rt)return T[x].mn=min(T[x].mn,T[y].mn),x;
	if(T[x].val) pushdown(x);if(T[y].val) pushdown(y);
	int mid=lt+rt>>1;
	int L=Merge(T[x].l,T[y].l,lt,mid);
	int R=Merge(T[x].r,T[y].r,mid+1,rt);
	T[x].l=L;T[x].r=R;
	T[x].mn=min(T[L].mn,T[R].mn);
	return x;
}
void Solve(int x,int fa)
{
	long long tot=0;
	for(int i=head[x];i;i=e[i].next)
		if(e[i].to!=fa)
		{
			dep[e[i].to]=dep[x]+1;Solve(e[i].to,x);
			w[e[i].to]=Query(rt[e[i].to],1,n,1,dep[x]);tot+=w[e[i].to];
	//		cout<<e[i].to<<" "<<w[e[i].to]<<endl;
			if(w[e[i].to]>=1e18){puts("-1");exit(0);}

		}
//	cout<<"??"<<x<<" tot = "<<tot<<endl;
	for(int i=head[x];i;i=e[i].next)
		if(e[i].to!=x)
		{
			Mark(rt[e[i].to],tot-w[e[i].to]);
			rt[x]=Merge(rt[x],rt[e[i].to]);
		}
//	cout<<"finish"<<x<<" tot = "<<tot<<endl;
	for(int i=0;i<v[x].size();++i) Modify(rt[x],1,n,dep[v[x][i].first],tot+v[x][i].second);
}
int main()
{
	n=read();m=read();T[0].mn=1e18;
    if(n==1) return 0*puts("0");
	for(int i=1;i<n;++i) ins(read(),read());cnt=0;
	for(int i=1;i<=n;++i) rt[i]=newnode();
	for(int i=1;i<=m;++i)
	{
		int u=read(),V=read(),c=read();
		v[u].push_back(make_pair(V,c));	
	}
	Solve(dep[1]=1,0);
	printf("%lld\n",Query(rt[1],1,n,1,1));
	return 0;
}