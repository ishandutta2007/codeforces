#include<bits/stdc++.h>
using namespace std;
#define N 100010
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
set<int> s[N];
int n,m,cnt,a[N];
ll ans[N];
struct Data{
	int opt,l,r,x;	
	friend bool operator < (const Data &a,const Data &b){
		return a.l==b.l?a.opt<b.opt:a.l>b.l;	
	}
}q[N<<3];
struct BIT{
	ll b[N];
	inline int lowbit(int x){return x&(-x);}
	inline void Add(int x,int d){
		while(x<=n)b[x]+=d,x+=lowbit(x);
	}
	inline ll Ask(int x){
		ll ans=0;
		while(x)ans+=b[x],x-=lowbit(x);
		return ans;
	}	
}B;
inline void Del(int u,int x){
	auto it=s[x].lower_bound(u);
	int l=0,r=0;
	if(it!=s[x].begin()){
		l=(*--it);
		++it;
	}
	if((++it)!=s[x].end()){
		r=*it;	
	}
	--it;
	if(l&&r)q[++cnt]={1,l,r,1};
	if(l)q[++cnt]={1,l,u,-1};
	if(r)q[++cnt]={1,u,r,-1};
	s[x].erase(it);
}
inline void Insert(int u,int x){
	auto it=s[x].lower_bound(u);
	int l=0,r=0;
	if(it!=s[x].begin()){
		l=(*--it);
		++it;
	}
	if(it!=s[x].end()){
		r=*it;	
	}
	if(l&&r)q[++cnt]={1,l,r,-1};
	if(l)q[++cnt]={1,l,u,1};
	if(r)q[++cnt]={1,u,r,1};
	s[x].insert(u);
}
void CDQ(int l,int r){
	if(l==r)return;
	int mid=(l+r)>>1;
	CDQ(l,mid),CDQ(mid+1,r);
	sort(q+l,q+mid+1),sort(q+mid+1,q+r+1);
	int i=l;
	for(int j=mid+1;j<=r;++j){
		while(i<=mid&&q[i].l>=q[j].l){
			if(q[i].opt==1)B.Add(q[i].r,q[i].x*(q[i].r-q[i].l));
			++i;	
		}
		if(q[j].opt==2)ans[q[j].x]+=B.Ask(q[j].r);
	}
	for(int k=l;k<i;++k){
		if(q[k].opt==1)B.Add(q[k].r,-q[k].x*(q[k].r-q[k].l));
	}
}
int main(){
	n=read(),m=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
		Insert(i,a[i]);
	}
	for(int i=1;i<=m;++i){
		int opt=read();
		if(opt==1){
			int p=read(),x=read();
			Del(p,a[p]);
			a[p]=x;
			Insert(p,x);
			ans[i]=-1;
		}
		else{
			int l=read(),r=read();
			ans[i]=0;
			q[++cnt]={2,l,r,i};	
		}
	}
	CDQ(1,cnt);
	for(int i=1;i<=m;++i){
		if(~ans[i])printf("%lld\n",ans[i]);
	}
	return 0;
}