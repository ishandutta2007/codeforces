#include<iostream>
#include<queue>
#include<stack>
using namespace std;
const int ts=262144;
typedef long long ll;
#define fi first
#define se second
int n,q;
ll val[ts],sum[ts];//min (max-min-len),lazy
ll nom[ts];//number of min
ll cnt[ts],lazy[ts];//sum of val,lazy
int a[120001];
ll ans[120001];
vector<pair<int,int> >qr[120001];
stack<pair<int,int> >ma,mi;
void pass(int id,int c){
	val[c]+=sum[id];
	sum[c]+=sum[id];
	if(val[c]==val[id]){
		cnt[c]+=lazy[id]*nom[c];
		lazy[c]+=lazy[id];
	}
}
void pushdown(int id){
	pass(id,id*2);
	pass(id,id*2+1);
	sum[id]=lazy[id]=0;
}
void build(int id,int l,int r){
	nom[id]=1;
	if(l==r) return;
	int mid=(l+r)/2;
	build(id*2,l,mid);
	build(id*2+1,mid+1,r);
}
void upd(int id,int l,int r,int ll,int rr,int v){
	if(r<ll || l>rr) return;
	if(ll<=l && r<=rr){
		val[id]+=v;
		sum[id]+=v;
		return;
	}
	pushdown(id);
	int mid=(l+r)/2;
	upd(id*2,l,mid,ll,rr,v);
	upd(id*2+1,mid+1,r,ll,rr,v);
	val[id]=min(val[id*2],val[id*2+1]);
	cnt[id]=cnt[id*2]+cnt[id*2+1];
	nom[id]=0;
	if(val[id*2]==val[id]) nom[id]+=nom[id*2];
	if(val[id*2+1]==val[id]) nom[id]+=nom[id*2+1];
	
}
ll ask(int id,int l,int r,int ll,int rr){
	if(r<ll || l>rr) return 0;
	if(ll<=l && r<=rr) return cnt[id];
	pushdown(id);
	int mid=(l+r)/2;
	return ask(id*2,l,mid,ll,rr)+ask(id*2+1,mid+1,r,ll,rr);
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=1; i<=n ;i++) cin >> a[i];
	cin >> q;
	for(int i=1; i<=q ;i++){
		int x,y;
		cin >> x >> y;
		qr[y].push_back({x,i});
	}
	build(1,1,n);
	for(int i=1; i<=n ;i++){
		//cout << i << ": \n";
		int lma=i,lmi=i;
		upd(1,1,n,1,i,-1);
		//cout << 1 << ' ' << i << ' ' << -1 << endl;
		while(!ma.empty() && ma.top().fi<a[i]){
			upd(1,1,n,ma.top().se,lma-1,a[i]-ma.top().fi);
			lma=ma.top().se;
			ma.pop();
		}
		ma.push({a[i],lma});
		while(!mi.empty() && mi.top().fi>a[i]){
			upd(1,1,n,mi.top().se,lmi-1,mi.top().fi-a[i]);
			lmi=mi.top().se;
			mi.pop();
		}
		mi.push({a[i],lmi});
		lazy[1]++;
		cnt[1]+=nom[1];
		for(auto cur:qr[i]) ans[cur.se]=ask(1,1,n,cur.fi,i);
	}
	for(int i=1; i<=q ;i++) cout << ans[i] << '\n';
}