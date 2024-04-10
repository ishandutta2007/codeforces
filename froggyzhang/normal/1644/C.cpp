#include<bits/stdc++.h>
using namespace std;
#define N 5005
typedef long long ll;
int n,x,a[N],s[N],ans[N];
void Solve(){
	cin>>n>>x;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		s[i]=s[i-1]+a[i];
	}
	for(int i=0;i<=n;++i)ans[i]=0;
	for(int k=0;k<=n;++k){
		int mx=0;
		for(int i=k;i<=n;++i){
			mx=max(mx,-s[i-k]);
			ans[k]=max(ans[k],s[i]+mx+k*x);
		}
	}
	for(int i=1;i<=n;++i){
		ans[i]=max(ans[i],ans[i-1]);
	}
	for(int i=0;i<=n;++i){
		cout<<ans[i]<<' ';
	}
	cout<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}