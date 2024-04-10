#include<bits/stdc++.h>
using namespace std;
const int mo=1e9+7;
int Pow(int a,long long b){
	int r=1;
	for(;b;b>>=1,a=1ll*a*a%mo)
		if(b&1)r=1ll*r*a%mo;
	return r;
}
int main(){
#ifdef flukehn
	freopen("a.in","r",stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	int k;
	while(cin>>k){
		long long n=(1LL<<k)-1;
		cout<<6LL*Pow(4,n-1)%mo<<"\n";
	}
}