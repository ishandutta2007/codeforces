#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
ll F(ll x){
	ll mn=9,mx=0,P=x;
	while(x){
		mn=min(mn,x%10),mx=max(mx,x%10);
		x/=10;
	}
	return P+mn*mx;
}
bool Zero(ll x){
	while(x){
		if(!(x%10))return 1;
		x/=10;
	}
	return 0;
}
int main(){
	int T;
	cin>>T;
	while(T--){
		ll n,k;
		cin>>n>>k;
		for(ll i=2;i<=k&&!Zero(n);i++)n=F(n);
		cout<<n<<endl;
	} 
}