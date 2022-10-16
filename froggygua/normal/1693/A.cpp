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
	while(n&&!a[n])--n;
	if(!n){
		cout<<"Yes\n";
		return;
	}
	ll now=0;
	for(int i=1;i<=n;++i){
		now+=a[i];
		if(i<n&&now<=0){
			cout<<"No\n";
			return;
		}
	}
	if(now!=0){
		cout<<"No\n";
	}
	else{
		cout<<"Yes\n";
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