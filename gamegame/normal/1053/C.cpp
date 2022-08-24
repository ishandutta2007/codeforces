#include<iostream>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
int n,q;
ll suma[524288];
ll sumw[524288];
ll a[200001],w[200001];
void upd(int id,int l,int r,int pos,ll v){
	if(l==r){
		sumw[id]=v;
		suma[id]=(a[l]-l+1)*v%mod;
		return;
	}
	int mid=(l+r)/2;
	if(pos<=mid) upd(id*2,l,mid,pos,v);
	else upd(id*2+1,mid+1,r,pos,v);
	sumw[id]=sumw[id*2]+sumw[id*2+1];
	suma[id]=(suma[id*2]+suma[id*2+1])%mod;
}
ll qr1(int id,int l,int r,int ql,int qr){
	//cout << id << ' ' << l << ' ' << r << ' ' << ql << ' ' << qr << ' ' << suma[id] << endl;
	if(r<ql || l>qr) return 0;
	if(ql<=l && r<=qr) return suma[id];
	int mid=(l+r)/2;
	return (qr1(id*2,l,mid,ql,qr)+qr1(id*2+1,mid+1,r,ql,qr))%mod;
}
ll qr2(int id,int l,int r,int ql,int qr){
	if(r<ql || l>qr) return 0;
	if(ql<=l && r<=qr) return sumw[id];
	int mid=(l+r)/2;
	return qr2(id*2,l,mid,ql,qr)+qr2(id*2+1,mid+1,r,ql,qr);
}
ll cal(ll pos,int x,int y){
	//cout << pos << ' ' << x << ' ' << y << ' ';
	int l=x,r=y+1;
	while(l!=r){
		int mid=(l+r)/2;
		if(a[mid]<pos+mid-1) l=mid+1;
		else r=mid;
	}
	int mid=l;
	//cout << mid << endl;
	ll ans=0;
	if(mid!=x) ans+=qr2(1,1,n,x,mid-1)%mod*pos%mod-qr1(1,1,n,x,mid-1);
	if(mid!=y+1) ans+=qr1(1,1,n,mid,y)-qr2(1,1,n,mid,y)%mod*pos%mod;
	ans%=mod;
	if(ans<0) ans+=mod;
	return ans;
}
ll v;
int find(int id,int l,int r,int ql,int qr){
	if(l==r){
		if(sumw[id]<v){
			v-=sumw[id];
			return r+1;
		}
		return r;
	}
	int mid=(l+r)/2;
	if(qr<=mid) return find(id*2,l,mid,ql,qr);
	if(ql>mid) return find(id*2+1,mid+1,r,ql,qr);
	ll tmp2=qr2(id*2,l,mid,ql,mid);
	if(tmp2<v){
		v-=tmp2;
		return find(id*2+1,mid+1,r,mid+1,qr);
	}
	return find(id*2,l,mid,ql,mid);
	
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> q;
	for(int i=1; i<=n ;i++){
		cin >> a[i];
	}
	for(int i=1; i<=n ;i++){
		cin >> w[i];
		upd(1,1,n,i,w[i]);
	}
	for(int i=1; i<=q ;i++){
		ll x,y;
		cin >> x >> y;
		if(x<0){
			x=-x;
			upd(1,1,n,x,y);
			continue;
		}
		ll l=x,r=y;
		ll sum=qr2(1,1,n,l,r);
		v=sum/2+1;
		l=find(1,1,n,l,r);
		cout << cal(a[l]-l+1,x,y) << '\n';
	}
}