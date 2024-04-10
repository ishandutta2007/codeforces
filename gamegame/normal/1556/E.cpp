#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const int N=2e6+1;
const ll mod=1e9+7;
ll n,q;
ll gets(int x,int y){
	ll ans=0,res=0;
	cout << "and " << x << ' ' << y << endl;
	cin >> res;ans+=res;
	cout << "or " << x << ' ' << y << endl;
	cin >> res;ans+=res;
	return ans;
}
ll a[N],p[N];
const int ts=262144;
ll mn[ts],mx[ts];
void build(int id,int l,int r){
	if(l==r){
		mn[id]=mx[id]=p[l];
		return;
	}
	int mid=(l+r)/2;
	build(id*2,l,mid);
	build(id*2+1,mid+1,r);
	mn[id]=min(mn[id*2],mn[id*2+1]);
	mx[id]=max(mx[id*2],mx[id*2+1]);
}
ll qmn(int id,int l,int r,int ql,int qr){
	if(l>qr || r<ql) return 1e18;
	if(ql<=l && r<=qr) return mn[id];
	int mid=(l+r)/2;
	return min(qmn(id*2,l,mid,ql,qr),qmn(id*2+1,mid+1,r,ql,qr));
}
ll qmx(int id,int l,int r,int ql,int qr){
	if(l>qr || r<ql) return -1e18;
	if(ql<=l && r<=qr) return mx[id];
	int mid=(l+r)/2;
	return max(qmx(id*2,l,mid,ql,qr),qmx(id*2+1,mid+1,r,ql,qr));
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	cin >> n >> q;
	for(int i=1; i<=n ;i++) cin >> a[i];
	for(int i=1; i<=n ;i++){
		ll x;cin >> x;a[i]=x-a[i];
		p[i]=p[i-1]+a[i];
	}
	build(1,1,n);
	for(int i=1; i<=q ;i++){
		int l,r;cin >> l >> r;
		if(p[l-1]!=p[r]){
			cout << "-1\n";continue;
		}
		ll duh=qmn(1,1,n,l,r);
		if(duh<p[l-1]){
			cout << "-1\n";continue;
		}
		duh=qmx(1,1,n,l,r);
		cout << duh-p[l-1] << '\n';
	}
}