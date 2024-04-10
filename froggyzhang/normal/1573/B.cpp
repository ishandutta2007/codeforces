#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 200020
int p[N],n;
void Solve(){
	cin>>n;
	for(int i=1,x;i<=n;++i){
		cin>>x;
		p[x]=i;
	}
	for(int i=1,x;i<=n;++i){
		cin>>x;
		p[x]=i;
	}
	int ans=2*n;
	for(int i=2*n,mn=2*n;i>=1;--i){
		if(i&1)ans=min(ans,mn+p[i]);
		else mn=min(mn,p[i]);
	}
	cout<<ans-2<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}