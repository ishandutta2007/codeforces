#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
const int N=1000000;
const ll inf=1e18;
int n,m,g[N+5],at[N+5],d[N+5],dlt,k;
struct T{
	ll k,b;
}tag[4*N+5];
ll a[N+5][2],b[N+5],ans=inf;
void rAdd1(ll l,ll r){
	b[++b[0]]=l,b[++b[0]]=r;
}
void Add1(ll l,ll r){
	l=(l+dlt)%m,r=(r+dlt)%m;
	if(l<=r)rAdd1(l,r);
	else {
		rAdd1(l,m);
		rAdd1(0,r);
	}
}
void Rotate(int x){
	dlt=(dlt+x)%m;
}
void Tag(int p,T z){
	tag[p]=z;
}
void Pushdown(int p){
	if(tag[p].k!=1)Tag(p*2,tag[p]),Tag(p*2+1,tag[p]),tag[p]={1,1};
}
void Get1(int x){
	x=(x+dlt)%m;
	b[++b[0]]=x;
}
ll Get(int p,int l,int r,int x){
	if(l==r){
		assert(tag[p].k!=1);
		return tag[p].k*b[l]+tag[p].b;
	}
	Pushdown(p);
	int mid=(l+r)/2;
	if(x<=mid)return Get(p*2,l,mid,x);
	return Get(p*2+1,mid+1,r,x);
}
ll Get2(int x){
	x=(x+dlt)%m;
	x=lower_bound(b+1,b+b[0]+1,x)-b;
	return Get(1,1,b[0],x);
}
void Make(int p,int l,int r,int x,int y,T z){
	if(x<=l&&r<=y)return Tag(p,z),void();
	Pushdown(p);
	int mid=(l+r)/2;
	if(x<=mid)Make(p*2,l,mid,x,y,z);
	if(mid<y)Make(p*2+1,mid+1,r,x,y,z);
}
void rAdd2(ll l,ll r,ll x){
	//cout<<l<<' '<<r<<' '<<x<<'\n';
	l=lower_bound(b+1,b+b[0]+1,l)-b;
	r=lower_bound(b+1,b+b[0]+1,r)-b;
	//cout<<"LR:"<<l<<' '<<r-1<<' '<<x+b[l]<<'\n';
	if(l<r)Make(1,1,b[0],l,r-1,{-1,x+b[l]});
}
void Make2(ll l,ll r,ll x){
	l=(l+dlt)%m,r=(r+dlt)%m;
	if(l<=r)rAdd2(l,r,x);
	else {
		rAdd2(l,m,x);
		rAdd2(0,r,x-(m-l));
	}
}
void dfs(int p,int l,int r){
	if(l==r){
		if(l==b[0])return ;
		ans=min(ans,tag[p].k*b[l]+tag[p].b);
		ans=min(ans,tag[p].k*(b[l+1]-1)+tag[p].b);
		return ;
	}
	Pushdown(p);
	int mid=(l+r)/2;
	dfs(p*2,l,mid),dfs(p*2+1,mid+1,r);
}
void dfsp(int p,int l,int r){
	if(l==r){
		cout<<"X:"<<b[l]<<' '<<tag[p].k*b[l]+tag[p].b<<'\n';
		return ;
	}
	Pushdown(p);
	int mid=(l+r)/2;
	dfsp(p*2,l,mid),dfsp(p*2+1,mid+1,r);
}
int main(){
	ll sum=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&g[i],&at[i]);
	}
	for(int i=1;i<n;i++)scanf("%d",&d[i]),sum+=d[i];
	fill(tag,tag+4*N+1,(T){0,0});
	dlt=0;
	for(int i=n;i>=1;i--){
		Get1((g[i]-at[i]+m)%m);
		if(at[i]<g[i]){
			Add1(g[i]-at[i],m-at[i]);
		}
		else {
			Add1(0,m-at[i]);
			Add1(g[i]-at[i]+m,m);
		}
		Rotate(d[i-1]);
	}
	b[++b[0]]=0,b[++b[0]]=m;
	sort(b+1,b+b[0]+1);
	b[0]=unique(b+1,b+b[0]+1)-b-1;
	dlt=0;
	for(int i=n;i>=1;i--){
		//puts("");
		ll v=Get2((m-at[i])%m);
		if(at[i]<=g[i]){
			Make2(g[i]-at[i],m-at[i],m-g[i]+v);
		}
		else {
			Make2(0,m-at[i],m-at[i]+v);
			Make2(g[i]-at[i]+m,m,m-g[i]+v);
		}
		Rotate(d[i-1]);
		//dfsp(1,1,b[0]);
		//puts("");
	}
	dfs(1,1,b[0]);
	cout<<ans+sum;
}