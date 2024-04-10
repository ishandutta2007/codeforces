#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
int n;
ll d;
ll v[3055][3055];
ll p[3055];
ll ans[3055];
ll inv[3055];
ll f[3055];
vector<int>ch[3055];
ll pw(ll x,ll y){
	if(y==0) return 1;
	ll res=pw(x,y/2);
	res=res*res%mod;
	if(y%2) res=res*x%mod;
	return res;
}
void dfs(int id){
	for(auto i:ch[id]) dfs(i);
	for(int i=1; i<=n+1 ;i++) v[id][i]=1;
	for(auto son:ch[id]){
		for(int i=1; i<=n+1 ;i++){
			v[id][i]=v[id][i]*v[son][i]%mod;
		}
	}
	for(int i=1; i<=n+1 ;i++){
		v[id][i]+=v[id][i-1];
		if(v[id][i]>=mod) v[id][i]-=mod;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	cin >> d;
	for(int i=2; i<=n ;i++){
		cin >> p[i];
		ch[p[i]].push_back(i);
		p[i]=0;
	}
	dfs(1);
	p[0]=1;
	f[0]=1;
	for(int i=0; i<=n+1 ;i++){
		for(int j=n+2; j>=0 ;j--){
			p[j]+=p[j-1];
			if(p[j]>=mod) p[j]-=mod;
			p[j-1]=(mod-p[j-1])*i%mod;
		}
		inv[i]=pw(i,mod-2);
		if(i!=0) f[i]=f[i-1]*i%mod;
	}
	for(int i=0; i<=n+1 ;i++){
		if(i==0){
			for(int j=0; j<=n+2 ;j++) p[j]=p[j+1];
		}
		else{
			for(int j=0; j<=n+2 ;j++){
				p[j]=mod-p[j]*inv[i]%mod;
				if(p[j]>=mod) p[j]-=mod;
				p[j+1]-=p[j];
				if(p[j+1]<0) p[j+1]+=mod;
			}
		}
		ll cnt;
		cnt=f[n+1-i]*f[i]%mod;
		if(i%2!=(n+1)%2) cnt=mod-cnt;
		cnt%=mod;
		cnt=v[1][i]*pw(cnt,mod-2)%mod;
		for(int j=0; j<=n+2 ;j++){
			ans[j]=(ans[j]+cnt*p[j])%mod;
		}
		for(int j=n+2; j>=0 ;j--){
			p[j]+=p[j-1];
			if(p[j]>=mod) p[j]-=mod;
			p[j-1]=(mod-p[j-1])*i%mod;
		}
	}
	ll out=0;
	for(int i=n+2; i>=0 ;i--){
		out=out*d+ans[i];
		out%=mod;
	}
	cout << out << endl;
}