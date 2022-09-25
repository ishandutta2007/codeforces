#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a[233];
ll f[233];
void Solve(){
	cin>>n;
	ll sum=0;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		sum+=a[i];
	}
	int p=0;ll now=1;
	while(now<sum){
		now+=f[++p];
	}
	if(now!=sum){
		cout<<"NO\n";
		return;
	}
	for(int i=p,las=0;i>=0;--i){
		int u=-1;
		for(int j=1;j<=n;++j){
			if(las==j||a[j]<f[i])continue;
			if(u==-1||a[j]>a[u]){
				u=j;
			}
		}
		if(u==-1){
			cout<<"NO\n";
			return;
		}
		a[u]-=f[i];
		las=u;
	}
	cout<<"YES\n";
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	f[0]=f[1]=1;
	for(int i=2;i<=60;++i){
		f[i]=f[i-1]+f[i-2];
	}
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}