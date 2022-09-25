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
	int ans=0;
	for(int i=1;i<=n;++i){
		for(int j=i;j<=n;++j){
			ans+=j-i+1;
			for(int k=i;k<=j;++k){
				ans+=!a[k];
			}
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