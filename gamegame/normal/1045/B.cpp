#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
int n;
ll m;
ll mod=1e9+7;
ll b;
ll a[200001];
ll sum;
ll cur;
pair<ll,int>q[400001];
vector<ll>ans;
ll pw(ll x,ll y){
	if(y==0) return 1;
	if(y%2) return x*pw(x,y-1)%mod;
	ll res=pw(x,y/2);
	return res*res%mod;
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m;
	b=48239409;
	for(int i=1; i<=n ;i++){
		cin >> a[i];
		sum=(sum+pw(b,a[i]))%mod;
		cur=(cur+pw(b,m-a[i]))%mod;
		q[i]={(a[1]+a[i])%m,1};
		q[i+n]={a[i],0};
	}
	sort(q+1,q+2*n+1);
	for(int i=1; i<=2*n ;i++){
		cur=cur*pw(b,q[i].first-q[i-1].first)%mod;
		if(q[i].second==1){
			bool ok=true;
			if(cur!=sum)  ok=false;
			if(ok) ans.push_back(q[i].first);
		}
		else{
			cur=(cur-pw(b,m)+1+mod)%mod;
		}
	}
	cout << ans.size() << endl;
	for(int i=0; i<ans.size() ;i++) cout << ans[i] << ' ';
	if(!ans.empty()) cout << endl;
}