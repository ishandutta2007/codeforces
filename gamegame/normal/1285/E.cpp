#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
int n;
pair<ll,int>st[400001];
ll ans[200001];
ll prv[200001];
multiset<int>s;
void solve(){
	cin >> n;
	for(int i=1; i<=n ;i++){
		ll l,r;cin >> l >> r;
		st[2*i-1]={l,-i};
		st[2*i]={r,i};
		ans[i]=0;
	}
	sort(st+1,st+2*n+1);
	ll pf=0;
	st[0].se=1;
	for(int i=1; i<=2*n ;i++){
		int ps=s.size();
		if(st[i].se<0){
			s.insert(-st[i].se);
		}
		else{
			s.erase(s.find(st[i].se));
		}
		if(s.size()==1 && st[i].se>0 && st[i+1].se<0 && st[i+1].fi!=st[i].fi) ans[*(s.begin())]++;
		else if(s.size()==1 && st[i].se<0 && st[i+1].se>0) ans[*s.begin()]--;
		if(s.size()==0) pf++;
	}
	ll mx=-1e9;
	for(int i=1; i<=n ;i++) mx=max(mx,ans[i]);
	cout << mx+pf << '\n';
}
int main(){
	ios::sync_with_stdio(false);
	int t;cin >> t;
	while(t--) solve();
}