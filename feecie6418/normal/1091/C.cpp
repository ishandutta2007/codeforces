#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
int n;
ll Calc(ll x){
	ll y=n/x;
	return (1+(y-1)*x+1)*y/2;
}
int main(){
	cin>>n;
	vector<ll> ans;
	for(int i=1;i*i<=n;i++){
		if(n%i)continue;
		ans.push_back(Calc(i));
		ans.push_back(Calc(n/i));
	}
	sort(ans.begin(),ans.end());
	ans.resize(unique(ans.begin(),ans.end())-ans.begin());
	for(ll i:ans)cout<<i<<' ';
}