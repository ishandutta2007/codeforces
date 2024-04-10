#include<bits/stdc++.h>
using namespace std;
#define N 233
typedef long long ll;
int n,a[N];
void Solve(){
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	int ans=n-1;
	for(int i=1;i<=n;++i){
		for(int j=i+1;j<=n;++j){
			int tmp=0;
			for(int k=1;k<=n;++k){
				if((a[k]-a[i])*(j-i)!=(a[j]-a[i])*(k-i))++tmp;
			}	
			ans=min(ans,tmp);
		}
	}
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}