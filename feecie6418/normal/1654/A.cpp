#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
typedef long long ll;
int n,a[1005];
void Solve(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	cout<<a[n]+a[n-1]<<'\n';
}
int main(){
	int t;
	cin>>t;
	while(t--)Solve();
}