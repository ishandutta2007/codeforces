#include<bits/stdc++.h>
using namespace std;
#define N 1000100
typedef long long ll;
bool ntp[N];
void init(int n){
	ntp[1]=1;
	for(int i=2;i<=n;++i){
		if(!ntp[i]){
			for(int j=i+i;j<=n;j+=i)ntp[j]=1;	
		}	
	}	
}
int n,e,a[N],suf[N];
void Solve(){
	cin>>n>>e;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		suf[i]=0;
	}
	for(int i=n;i>=1;--i){
		suf[i]=a[i]>1?0:(i+e<=n?suf[i+e]:0)+1;	
	}
	ll ans=0;
	for(int i=1;i<=n;++i){
		int p=i+suf[i]*e;
		if(p<=n&&!ntp[a[p]]){
			ans+=(p+e<=n?suf[p+e]:0)+(p>i);
		}	
	}
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	init(1000000);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}