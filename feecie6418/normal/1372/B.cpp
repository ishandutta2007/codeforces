#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
void Solve(){
	int n;
	cin>>n;
	for(int i=2;i*i<=n;i++){
		if(n%i==0){
			cout<<n/i<<' '<<n-n/i<<'\n';
			return ;
		}
	}
	cout<<1<<' '<<n-1<<'\n';
}
int main(){
	int t;
	cin>>t;
	while(t--)Solve();
}