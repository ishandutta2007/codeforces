#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const int N=2e6+1;
ll n,m;
map<ll,int>mp;
ll bit[N];
void upd(ll x){
	for(int i=x; i<=n ;i+=i&-i){
		bit[i]++;
	}
}
void rupd(ll x){
	for(int i=x; i<=n ;i+=i&-i){
		bit[i]--;
	}
}

ll get(int k){
	int x=0;
	for(int i=19; i>=0 ;i--){
		if(x+(1<<i)<=n){
			int y=x+(1<<i);
			if(k>bit[y]){
				k-=bit[y];
				x=y;
			}
		}
	}
	return x+1;
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m;
	ll sz=n;
	for(int i=1; i<=n ;i++){
		ll x;cin >>x;upd(x);
		sz++;
	}
	for(int i=1; i<=m ;i++){
		ll x;cin >> x;
		if(x>0){
			upd(x);
			sz++;
		}
		else{
			//cout << sz << enedl;
			ll y=get(-x);
			rupd(y);
			sz--;
		}
	}
	ll x=get(1);
	if(get(1)>n){
		cout << "0\n";
		return 0;
	}
	cout << get(1) << '\n';
}