#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=998244353;
const int N=2e6+1;
typedef double dd;
ll n,q;
dd x,y;
dd a[N];
const int ts=524288;
typedef array<dd,9> arin;
arin dp[ts];
arin nul={-1,0,0,0,0,0,0,0,0};
void norm(arin &dpid){
	for(int i=0; i<3 ;i++)
		for(int j=0; j<3 ;j++){
			if(i!=2) dpid[i*3+j+3]=max(dpid[i*3+j],dpid[i*3+j+3]);
			if(j!=2) dpid[i*3+j+1]=max(dpid[i*3+j],dpid[i*3+j+1]);		
		}
}
arin merge(arin &x,arin &y){
	if(x[0]==-1) return y;
	if(y[0]==-1) return x;
	arin z=nul;
	for(int k=0; k<3 ;k++){
		for(int i=0; i<3 ;i++){
			for(int j=0; j<3 ;j++){
				z[i*3+j]=max(z[i*3+j],x[i*3+k]+y[(2-k)*3+j]);
			}
		}
	}
	norm(z);
	return z;
}
void upd(int id,int l,int r,int p,dd v){
	if(l==r){
		a[p]=v;
		for(int i=0; i<3 ;i++)
			for(int j=0; j<3 ;j++){
				dp[id][i*3+j]=0;
			}
		dp[id][0]=0;
		dp[id][4]=a[p]/(x+y);
		dp[id][8]=a[p]/x;
		norm(dp[id]);
		return;
	}
	int mid=(l+r)/2;
	if(p<=mid) upd(id*2,l,mid,p,v);
	else upd(id*2+1,mid+1,r,p,v);
	dp[id]=merge(dp[id*2],dp[id*2+1]);
}
arin qry(int id,int l,int r,int ql,int qr){
	if(l>qr || r<ql) return nul;
	if(ql<=l && r<=qr) return dp[id];
	int mid=(l+r)/2;
	auto lc=qry(id*2,l,mid,ql,qr);
	auto rc=qry(id*2+1,mid+1,r,ql,qr);
	return merge(lc,rc);
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	cin >> n >> q >> x >> y;
	if(x<y) swap(x,y);
	for(int i=1; i<=n ;i++){
		ll z;cin >> z;
		upd(1,1,n,i,z);
	}
	cout << fixed << setprecision(20);
	for(int i=1; i<=q ;i++){
		int t;cin >> t;
		if(t==1){
			int id;dd v;cin >> id >> v;
			upd(1,1,n,id,v);
		}
		else{
			int l,r;cin >> l >> r;
			auto aa=qry(1,1,n,l,r);
			cout << aa[8] << '\n';
		}
	}
	
}