#include<bits/stdc++.h>
using namespace std;
const int mo=1e9+7;
const int N=2e5+11;
int a[N];
int n;
int p2[N];
int work(){
	cin>>n;
	for(int i=0;i<n;++i)cin>>a[i];
	int ans=0;
	int b[33]={0};
	for(int i=0;i<n;++i){
		int x=0;
		while(a[i]%2==0)x++,a[i]>>=1;
		++b[x];
	}
	int s=0;
	for(int i=30;i>=1;--i){
		if(!b[i])continue;
		int t=p2[b[i]-1]-1;
		ans=(ans+1ll*p2[s]*t)%mo;
		s+=b[i];
	}
	ans=(ans+1ll*p2[s]*(p2[b[0]]-1))%mo;
	return (ans%mo+mo)%mo;
}
int main(){
#ifdef flukehn
	freopen("a.in","r",stdin);
#endif
	ios::sync_with_stdio(0),cin.tie(0);
	p2[0]=1;
	for(int i=1;i<N;++i)p2[i]=p2[i-1]*2%mo;
	int t=1;
#ifdef flukehn	
	cin>>t;
#endif
	while(t--)cout<<work()<<"\n";
}