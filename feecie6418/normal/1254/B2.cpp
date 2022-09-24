#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
typedef vector<int> ve;
const int mod=998244353;
int n,a[1000005],m;
ll s=0;
ll Solve(ll val){
	ll sum=0,t=0;
	for(int i=1;i<n;i++){
		t=(t+a[i])%val;
		sum+=min(t,val-t);
	}
	return sum;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),s+=a[i];
	if(s==1)return puts("-1"),0;
	vector<ll> ps;
	for(ll i=2;i*i<=s;i++){
		if(s%i)continue;
		while(s%i==0)s/=i;
		ps.push_back(i);
	}
	if(s>1)ps.push_back(s);
	ll ans=1e18;
	for(auto i:ps)ans=min(ans,Solve(i));
	cout<<ans;
}