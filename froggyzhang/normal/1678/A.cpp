#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a[233];
void Solve(){
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int zero=count(a+1,a+n+1,0);
	bool ok=zero;
	for(int i=1;i<n;++i){
		if(a[i]&&a[i]==a[i+1]){
			ok=1;break;
		}
	}
	cout<<n-zero+(!ok)<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}