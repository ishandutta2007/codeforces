#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a[233];
void Solve(){
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	cout<<a[1]<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}