#include<bits/stdc++.h>
using namespace std;
#define N 100010
typedef long long ll;
int n,a[N],b[N],m;
void Solve(){
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		b[i]=a[i];
	}
	sort(a+1,a+n+1);
	for(int i=n-m+1;i<=m;++i){
		if(a[i]^b[i]){
			cout<<"NO\n";return;
		}
	}
	cout<<"YES\n";
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}