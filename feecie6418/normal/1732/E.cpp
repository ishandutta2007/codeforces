#include<bits/stdc++.h>
const int mod=998244353;
using namespace std;
typedef long long ll;
const int N=5e4,inf_=1e9;
const ll inf=1e12;
struct Segtree{

//range set range querymin 
ll tag[4*N+5],t[4*N+5];
void Tag(int p,ll x){
	tag[p]=x,t[p]=x;
}
void Pushdown(int p){
	if(tag[p])Tag(p*2,tag[p]),Tag(p*2+1,tag[p]),tag[p]=0;
}
void Make(int p,int l,int r,int x,int y,ll z){
	//if(p==1)cout<<"Make:"<<x<<' '<<y<<' '<<z<<'\n';
	if(x<=l&&r<=y)return Tag(p,z),void();
	Pushdown(p);
	int mid=(l+r)/2;
	if(x<=mid)Make(p*2,l,mid,x,y,z);
	if(mid<y)Make(p*2+1,mid+1,r,x,y,z);
	t[p]=min(t[p*2],t[p*2+1]);
}
ll Query(int p,int l,int r,int x,int y){
	if(x<=l&&r<=y)return t[p];
	Pushdown(p);
	int mid=(l+r)/2;
	ll ret=inf;
	if(x<=mid)ret=min(ret,Query(p*2,l,mid,x,y));
	if(mid<y)ret=min(ret,Query(p*2+1,mid+1,r,x,y));
	return ret;
}

}segtree;
struct Seg{
	int l,r,x;
}; 
bool operator <(const Seg &x,const Seg &y){
	return x.l<y.l;
}
int n,m,a[N+5],b[N+5],lg2[N+5];
set<Seg> s;
vector<int> divi[N+5];
struct ST{

//range min
vector<int> id,f[20];
void init(){
	for(int i=0;i<20;i++)f[i].resize(id.size());
	for(int i=0;i<id.size();i++)f[0][i]=b[id[i]];
	for(int i=1;(1<<i)<=id.size();i++){
		for(int j=0;j+(1<<i)-1<id.size();j++){
			f[i][j]=min(f[i-1][j],f[i-1][j+(1<<i-1)]);
		}
	}
}
int _get(int l,int r){
	int k=lg2[r-l+1];
	return min(f[k][l],f[k][r-(1<<k)+1]);
}
int get(int l,int r){
	l=lower_bound(id.begin(),id.end(),l)-id.begin();
	r=upper_bound(id.begin(),id.end(),r)-id.begin()-1;
	if(l>r)return inf_;
	return _get(l,r);
}

}st[N+5];
ll Q(int l,int r,int x){
	ll ans=inf;
	for(int i:divi[x]){
		int t=st[i].get(l,r);
		if(t!=inf_)ans=min(ans,1ll*x*t/i/i);
	}
	return ans;
}
Seg Find(int l){
	auto it=s.lower_bound({l,l,0});
	if(it!=s.end()&&(*it).l==l)return *it;
	return *--it;
}
int main(){
	scanf("%d%d",&n,&m),lg2[0]=-1;
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),s.insert({i,i,a[i]}),lg2[i]=lg2[i>>1]+1;
	for(int i=1;i<=n;i++)
		scanf("%d",&b[i]),segtree.Make(1,1,n,i,i,1ll*a[i]*b[i]/__gcd(a[i],b[i])/__gcd(a[i],b[i]));
	for(int i=1;i<=N;i++)for(int j=i;j<=N;j+=i)divi[j].push_back(i);
	for(int i=1;i<=n;i++)for(int j:divi[b[i]])st[j].id.push_back(i);
	for(int i=1;i<=N;i++)st[i].init();
	//cout<<Q(7,10,9)<<'\n';
	for(int i=1,op,l,r,x;i<=m;i++){
		scanf("%d%d%d",&op,&l,&r);
		if(op==2){
			Seg sl=Find(l),sr=Find(r);
			if(sl.l==sr.l)printf("%lld\n",Q(l,r,sl.x));
			else if(sl.r+1==sr.l)printf("%lld\n",min(Q(l,sl.r,sl.x),Q(sr.l,r,sr.x)));
			else {
				ll cur=segtree.Query(1,1,n,sl.r+1,sr.l-1);
				cur=min(cur,min(Q(l,sl.r,sl.x),Q(sr.l,r,sr.x)));
				printf("%lld\n",cur);
			}
			continue;
		}
		scanf("%d",&x);
		while(1){
			auto it=s.lower_bound({l,l,0});
			if(it==s.end()||(*it).l>r)break;
			auto t=*it;
			s.erase(it);
			if(t.r<=r)continue;
			else {
				t.l=r+1;assert(t.l<=t.r);
				segtree.Make(1,1,n,t.l,t.r,Q(t.l,t.r,t.x));
				s.insert(t);
			}
		}
		auto it=s.lower_bound({l,l,0});
		if(it!=s.begin()){
			--it;
			auto t=*it;
			if(t.r>r){
				s.erase(it);
				auto t1=t,t2=t;
				t1.r=l-1,t2.l=r+1;
				s.insert(t1),s.insert(t2);
				segtree.Make(1,1,n,t1.l,t1.r,Q(t1.l,t1.r,t1.x));
				segtree.Make(1,1,n,t2.l,t2.r,Q(t2.l,t2.r,t2.x));
			}
			else if(t.r>=l){
				s.erase(it),t.r=l-1;assert(t.l<=t.r);
				segtree.Make(1,1,n,t.l,t.r,Q(t.l,t.r,t.x));
				s.insert(t);
			}
			else assert(t.r==l-1);
		}
		segtree.Make(1,1,n,l,r,Q(l,r,x));
		s.insert({l,r,x});
		//for(auto i:s){
		//	cout<<i.l<<' '<<i.r<<' '<<i.x<<'\n';
		//}
	}
}