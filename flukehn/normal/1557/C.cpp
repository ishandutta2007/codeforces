#include<bits/stdc++.h>
using namespace std;
const int N=2e5+11,mo=1e9+7;
int Pow(int a,int b){
	int r=1;
	for(;b;b>>=1,a=1ll*a*a%mo)
		if(b&1)r=1ll*r*a%mo;
	return r;
}
int p2[N];
int work(int n,int k){
	if(n==1)return p2[k];
	//if(!k) return (n%2) ? 2 : 1;
	if(n%2) {
		return Pow(1 + p2[n-1] ,k);
	}
	int ans=0,tmp=1;
	for(int i=0;i<k;++i){
		ans = (ans + 1LL * tmp * Pow(p2[k-i-1], n))%mo;
		tmp = 1LL * tmp * (p2[n - 1] - 1)% mo;
	}
	return (ans + tmp + 2LL * mo) % mo;
}
int main(){
#ifdef flukehn
	freopen("c.in","r",stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	p2[0]=1;
	for(int i=1;i<N;++i)p2[i]=(p2[i-1]+p2[i-1])%mo;
	int T;
	cin>>T;
	while(T--){
		int n,k;
		cin>>n>>k;
		cout<<work(n,k)<<"\n";
	}
}