#include<bits/stdc++.h>
using namespace std;
const int N=2e5+11,mo=998244353;
int Pow(int a,int b){
	int r=1;
	for(;b;b>>=1,a=1ll*a*a%mo)
		if(b&1)r=1ll*r*a%mo;
	return r;
}
int jc[N],jcv[N];
int C(int a,int b){
	return (a<b||b<0)?0:1ll*jc[a]*jcv[b]%mo*jcv[a-b]%mo;
}
int a[N],n;
int work(){
	sort(a+1,a+n+1);
	if(a[n]==a[n-1])return jc[n];
	if(a[n]>a[n-1]+1)return 0;
	int s=0;
	for(int i=n-1;i>=1;--i)
		if(a[i]==a[n-1])++s;
	long long ans=jc[n];
	for(int i=1;i<=n;++i){
		ans-=1ll*C(i-1,s)*jc[s]%mo*jc[n-1-s]%mo;
	}
	return (ans%mo+mo)%mo;
}
int main(){
#ifdef flukehn
	freopen("a.in","r",stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	jc[0]=1;
	for(int i=1;i<N;++i)jc[i]=1ll*jc[i-1]*i%mo;
	jcv[N-1]=Pow(jc[N-1],mo-2);
	for(int i=N-1;i>=1;--i)jcv[i-1]=1ll*jcv[i]*i%mo;
	int T;cin>>T;
	while(cin>>n){
		for(int i=1;i<=n;++i)cin>>a[i];
		cout<<work()<<"\n";
	}
}