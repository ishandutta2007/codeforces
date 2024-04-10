#include<bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;
int n,a[N];
void Solve(){
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	if(a[n-1]>a[n]){
		cout<<-1<<'\n';
		return;
	}
	if(a[n]<0){
		bool ok=true;
		for(int i=1;i<n;++i){
			if(a[i]>a[i+1]){
				ok=false;break;
			}
		}
		cout<<(ok?0:-1)<<'\n';
		return;
	}
	cout<<n-2<<'\n';
	for(int i=1;i<=n-2;++i){
		cout<<i<<' '<<n-1<<' '<<n<<'\n';
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