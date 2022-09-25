#include<bits/stdc++.h>
using namespace std;
#define N 233333
typedef long long ll;
int n,a[N];
void Solve(){
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	bool ok=true;
	for(int i=2;i<=n;++i){
		if(a[i]<a[i-1]){
			ok=false;break;
		}
	}
	cout<<(!ok?"YES\n":"NO\n");
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}