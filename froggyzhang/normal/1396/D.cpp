#include<bits/stdc++.h>
using namespace std;
#define N 2020
typedef long long ll;
const int mod=1e9+7;
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
int n,k,L,ans;
int bx[N],by[N],lenx,leny;
struct Point{
	int x,y,c;
	bool operator <(const Point b)const{
		return y<b.y;
	}
}p[N],d[N]; 
int zyk[N],cnt[N],las[N];
struct node{
	int mx,cmx,se,l,r;
	int sum,tag;
	inline void Add(int d){
		tag+=d;
		mx+=d;
		sum=(sum+1LL*d*cmx%mod+mod)%mod;
	}
}tree[N<<2];
#define ls i<<1
#define rs i<<1|1
map<int,int> mp[N]; 
inline void update(int i){
	tree[i].sum=(tree[ls].sum+tree[rs].sum)%mod;
	tree[i].mx=max(tree[ls].mx,tree[rs].mx);
	if(tree[ls].mx>tree[rs].mx){
		tree[i].cmx=tree[ls].cmx;
		tree[i].se=max(tree[ls].se,tree[rs].mx);
	}
	else if(tree[ls].mx<tree[rs].mx){
		tree[i].cmx=tree[rs].cmx;
		tree[i].se=max(tree[rs].se,tree[ls].mx);
	}
	else{
		tree[i].cmx=tree[ls].cmx+tree[rs].cmx;
		tree[i].se=max(tree[ls].se,tree[rs].se);
	}
}
void pushdown(int i){
	int mx=max(tree[ls].mx,tree[rs].mx);
	if(tree[i].tag){
		if(tree[ls].mx==mx)tree[ls].Add(tree[i].tag);
		if(tree[rs].mx==mx)tree[rs].Add(tree[i].tag);
		tree[i].tag=0;
	}
}
void Min(int i,int l,int r,int d){
	if(tree[i].mx<=d)return;
	if(tree[i].l>=l&&tree[i].r<=r&&tree[i].se<d){
		tree[i].Add(d-tree[i].mx);
		return;
	}
	pushdown(i);
	int mid=(tree[i].l+tree[i].r)>>1;
	if(l<=mid){
		Min(ls,l,r,d);
	}
	if(r>mid){ 
		Min(rs,l,r,d);
	}
	update(i);
}
	
void build(int i,int l,int r){
	tree[i].l=l;
	tree[i].r=r;
	tree[i].tag=0;
	if(l==r){
		tree[i].mx=bx[zyk[l]];
		tree[i].se=-1;
		tree[i].cmx=bx[l+1]-bx[l];	
		tree[i].sum=1LL*bx[zyk[l]]*(bx[l+1]-bx[l])%mod;	
		return;
	}
	int mid=(tree[i].l+tree[i].r)>>1;
	build(ls,l,mid);
	build(rs,mid+1,r);
	update(i);
}
int Solve(int beg){
	if(beg>n)return 0;
	int m=0;
	memset(las,0,sizeof(las));
	memset(cnt,0,sizeof(cnt));
	for(int i=beg;i<=n;++i){
		d[++m]=p[i];
	} 
	sort(d+1,d+m+1,[&](Point a,Point b){return a.x<b.x;});
	for(int i=1;i<=k;++i)mp[i].clear(),++mp[i][0];
	for(int i=1;i<=m;++i){
		++mp[d[i].c][d[i].x];
	}
	int now=0;
	for(int i=1,j=1,o=1;i<=lenx;++i){
		while(j<=m&&d[j].x==i){
			if(!las[d[j].c])++now;
			else --cnt[las[d[j].c]];
			++cnt[las[d[j].c]=i];
			++j;
		}
		if(now==k){
			while(!cnt[o])++o;
			zyk[i]=o;
		}
		else zyk[i]=0;
	}
	build(1,1,lenx);
	sort(d+1,d+m+1);
	int tot=0;
	for(int i=leny,j=m;tree[1].sum;--i){
		tot=(tot+1LL*tree[1].sum*(by[i+1]-by[i]))%mod;
		while(j>=1&&d[j].y==i){
			int C=d[j].c;
			--mp[C][d[j].x];
			if(!mp[C][d[j].x]){
				mp[C].erase(d[j].x);
				auto it=mp[C].lower_bound(d[j].x);
				int R=(it==mp[C].end()?lenx:((it-> first)-1));
				assert(R>=d[j].x);
				--it;
				Min(1,d[j].x,R,bx[it->first]);
			}
			--j;
		}
	}
	return tot;
}
int main(){
	n=read(),k=read(),L=read();
	for(int i=1;i<=n;++i){
		p[i].x=read()+1,p[i].y=read()+1,p[i].c=read();
		bx[i]=p[i].x,by[i]=p[i].y;
	}
	bx[n+1]=L,by[n+1]=L;
	sort(bx+1,bx+n+2);
	sort(by+1,by+n+2);
	lenx=unique(bx+1,bx+n+2)-bx-1;
	leny=unique(by+1,by+n+2)-by-1;
	bx[lenx+1]=L+1;
	by[leny+1]=L+1;
	for(int i=1;i<=n;++i){
		p[i].x=lower_bound(bx+1,bx+lenx+1,p[i].x)-bx;
		p[i].y=lower_bound(by+1,by+leny+1,p[i].y)-by;
	}
	sort(p+1,p+n+1);
	for(int i=1,j=1;i<=leny;++i){
		while(j<=n&&p[j].y<i)++j;
		ans=(ans+1LL*(by[i]-by[i-1])*Solve(j))%mod;
	}
	printf("%d\n",ans);
	return 0;
}