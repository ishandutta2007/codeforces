#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=1e9+7;
const int N=2e6+1;
int n,m,q;
ll a[101];
ll c[101];
ll b[100001];
ll bit[100001];
ll bit2[100001];
void upd(int id,ll v){
	for(int i=id; i<=m ;i+=i&-i) bit[i]+=v;
	for(int i=id; i<=m ;i+=i&-i) bit2[i]+=id*v;
}

int real(ll v){
	int x=0;
	for(int i=16; i>=0 ;i--){
		if((x|(1<<i))<=m-1 && bit[x|(1<<i)]<v){
			x|=1<<i;
			v-=bit[x];
		}
	}
	return x;
}
ll qry(int id){
	ll res=0;
	for(int i=id; i>0 ;i-=i&-i) res+=bit[i];
	return res;
}
ll qry2(int id){
	ll res=0;
	for(int i=id; i>0 ;i-=i&-i) res+=bit2[i];
	return res;
}
ll get(int id){
	return id*qry(id-1)-qry2(id-1);
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	cin >> n >> m >> q;
	for(int i=1; i<=n ;i++){
		cin >> a[i];
	}
	ll sb=0;
	for(int i=1; i<=m ;i++){
		cin >> b[i];
		sb+=b[i];
	}
	b[0]=b[1];
	for(int i=2; i<=m ;i++){
		upd(i-1,b[i]-2*b[i-1]+b[i-2]);
	}
	for(int i=1; i<=q ;i++){
		int t,p;ll d;
		cin >> t >> p >> d;
		if(t==1){
			for(int j=n-p+1; j<=n ;j++) a[j]+=d*(j-n+p);
		}
		else{
			sb+=1LL*p*(p+1)/2*d;
			if(p==m){
				b[1]+=d;p--;
			}
			upd(m-p,d);
			
		}/*
		for(int i=1; i<=n ;i++){
			cout << a[i] << ' ';
		}
		cout << endl;
		for(int i=1; i<=m ;i++){
			cout << b[1]+get(i) << ' ';
		}
		cout << endl;*/
		ll ans=sb;
		//cout << sb << endl;
		int diu=1;
		//cout << "Path 1 ";
		for(int i=2; i<=n ;i++){
			int nd=real(a[i]-a[i-1])+1;
			ans+=1LL*(nd-diu+1)*a[i-1];
			ans+=b[1]+get(nd);
			diu=nd;
		//	cout << nd << ' ';
		}
		//cout << endl;
		ans+=(m-diu+1)*a[n];
		cout << ans << '\n';
	}
}