#include<bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;
int n,k,a[N];
void Solve(){
	cin>>n>>k;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	if(k==1){
		cout<<(n-1)/2<<'\n';
	}
	else{
		int ans=0;
		for(int i=2;i<n;++i){
			if(a[i]>a[i-1]+a[i+1])++ans;
		}
		cout<<ans<<'\n';
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}