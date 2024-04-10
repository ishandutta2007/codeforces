#include<bits/stdc++.h>
using namespace std;
#define N 500005
typedef long long ll;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
mt19937 rnd(time(0));
int n,m,k,Day[N];
int opt[N],x[N],y[N];
vector<pair<int,int> > mer;
struct Union_Set{
	int f[N],siz[N];
	void init(int n){
		for(int i=1;i<=n;++i){
			f[i]=i,siz[i]=1;
		}
	}
	inline int getf(int x){
		return f[x]==x?x:getf(f[x]);
	}
	inline void Merge(int x,int y){
		int fx=getf(x),fy=getf(y);
		if(fx==fy)return;
		if(siz[fx]<siz[fy])swap(fx,fy);
		f[fy]=fx;
		siz[fx]+=siz[fy];
		mer.emplace_back(fx,fy);
	}
}S;
vector<pair<int,int> > vec[N<<2];
#define ls i<<1
#define rs i<<1|1
void Add(int i,int L,int R,int l,int r,int t){
	if(L>=l&&R<=r){
		vec[i].emplace_back(x[t],y[t]);
		return;
	}
	int mid=(L+R)>>1;
	if(l<=mid)Add(ls,L,mid,l,r,t);
	if(r>mid)Add(rs,mid+1,R,l,r,t);
}
void dfs(int i,int L,int R){
	int sz=mer.size();
	for(auto [x,y]:vec[i]){
		S.Merge(x,y);
	}
	if(L==R){
		if(opt[L]==2)printf("%d\n",S.siz[S.getf(x[L])]);
	}
	else{
		int mid=(L+R)>>1;
		dfs(ls,L,mid);
		dfs(rs,mid+1,R);
	}
	while((int)mer.size()>sz){
		S.siz[mer.back().first]-=S.siz[mer.back().second],S.f[mer.back().second]=mer.back().second;
		mer.pop_back();
	}
}
int main(){
	n=read(),m=read(),k=read();
	Day[1]=1;
	for(int i=1,now=1;i<=m;++i){
		opt[i]=read();
		if(opt[i]==1)x[i]=read(),y[i]=read();
		else if(opt[i]==2)x[i]=read();
		else Day[++now]=i;
	}
	for(int i=1,now=1;i<=m;++i){
		if(opt[i]==1){
			Add(1,1,m,i,!Day[now+k]?m:Day[now+k]-1,i);
		}
		else if(opt[i]==3)++now;
	}
	S.init(n);
	dfs(1,1,m);
	return 0;
}