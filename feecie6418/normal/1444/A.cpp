#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n>>m;
		if(n%m)cout<<n<<endl;
		else {
			vector<ll> v;
			ll tm=m,ans=0;
			for(ll j=2;j*j<=m;j++){
				if(m%j)continue;
				while(m%j==0)m/=j;
				v.push_back(j);
			}
			if(m>1)v.push_back(m);
			for(ll i:v){
				ll tn=n;
				while(tn%tm==0)tn/=i;
				ans=max(ans,tn);
			}
			cout<<ans<<endl;
		}
	}
}