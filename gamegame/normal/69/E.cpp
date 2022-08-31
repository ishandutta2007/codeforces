#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const int N=2e6+1;
ll n,m,k;
ll a[N],b[N];
map<ll,int>mp;
set<ll>s;
void upd(ll x,int v){
	if(mp[x]==1) s.erase(x);
	mp[x]+=v;
	if(mp[x]==1) s.insert(x);
}
void out(){
	if(s.empty()) cout << "Nothing\n";
	else cout << *s.rbegin() << '\n';
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	cin >> n >> k;
	for(int i=1; i<=n ;i++){
		cin >> a[i];
	}
	for(int i=1; i<=k ;i++) upd(a[i],1);
	out();
	for(int i=k+1; i<=n ;i++){
		upd(a[i],1);
		upd(a[i-k],-1);
		out();
	}
}