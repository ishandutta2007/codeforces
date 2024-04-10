#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=998244353;
const int iu=3e5;
const int N=2e6+1;
int n;
ll bit1[N],bit2[N],bit3[N];
void upd(ll* bit,int id,ll v){
	for(int i=id; i<=iu ;i+=i&-i) bit[i]+=v;
}
ll qry(ll* bit,int id){
	ll res=0;
	for(int i=id; i>=1 ;i-=i&-i) res+=bit[i];
	return res;
}

int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	cin >> n;
	ll sum=0;
	ll ans=0;
	for(int i=1; i<=n ;i++){
		ll x;cin >> x;
		ll s1=qry(bit1,iu);
		ll s2=sum;
		for(int j=1; j*x<=iu ;j++){
			ll cur=qry(bit1,j*x-1);
			s2-=(s1-cur)*x;
		}
		upd(bit1,x,1);sum+=x;
		ll diu=x*(i-1);
		ll funny=qry(bit2,x);
		diu+=funny;
		ans=ans+s2+diu;
		//cout << diu << ' ' << s2 << ' ' << ans << endl;
		cout << ans << ' ';
		for(int j=1; j*x<=iu ;j++){
			upd(bit2,j*x,-x);
		}
		
	}
}