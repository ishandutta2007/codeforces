#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=998244353;
const int N=2e6+1;
ll n,a,b,c;
char s[N];
vector<int>fun,gun;
ll en=0;
ll bunny(ll y,ll z){
	sort(gun.begin(),gun.end());
	reverse(gun.begin(),gun.end());
	//for(auto c:gun) cout << c << ' ';
	//cout << endl;
	swap(y,z);
	//cout << y << ' ' << z << endl;
	ll best=0;
	ll cur=0;
	while(true){
		ll tmp=cur+min(y,z)*(a+b)+min(en+(ll)gun.size(),z-y)*max(0LL,b-c);
		if(y>z) tmp=cur+(z+1)*a+z*b;
		best=max(best,tmp);
		if(gun.empty()) break;
		if(z+1<gun.back()) break;
		ll x=gun.back();
		z-=x-1;
		y-=x-1;
		gun.pop_back();
		cur+=(x-1)*(a+b)+(b-c);
	}
	return best;
}
void solve(){
	cin >> n >> a >> b >> c;
	for(int i=1; i<=n ;i++){
		cin >> s[i];
	}
	int fi=n+1,li=0;
	for(int i=1; i<=n ;i++){
		if(s[i]=='1') fi=min(fi,i),li=max(li,i);
	}
	en=0;
	if(s[1]=='0') en++;
	if(s[n]=='0') en++;
	if(li==0){
		if(n==1) cout << "0\n";
		else cout << a << '\n';
		return;
	}
	ll y=0,z=0;
	for(int i=1; i<=n-1 ;i++){
		if(s[i]=='1' && s[i+1]=='1') y++;
		if(s[i]=='0' && s[i+1]=='0') z++;
	}
	int run=0;fun.clear();
	for(int i=fi; i<=li ;i++){
		if(s[i]=='1' && run>0){
			fun.push_back(run);run=0;
			//cout << i << endl;
		}
		else if(s[i]=='0') run++;
	}
	gun=fun;
	ll ans=bunny(y,z);
	gun=fun;
	if(y!=0) ans=max(ans,bunny(y-1,z)+b);
	cout << ans << endl;
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin >> t;
	while(t--) solve();
}