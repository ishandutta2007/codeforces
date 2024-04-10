#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[233];
void Solve(){
	int n,sum=0;
	cin>>n;
	for(int i=1;i<=n;++i)cin>>a[i],sum+=a[i];
	cout<<(sum%n==0?0:1)<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--){
		Solve();
	}
	return 0;
}