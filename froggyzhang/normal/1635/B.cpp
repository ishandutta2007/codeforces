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
	int ans=0;
	auto check=[&](int i)->bool{
		return a[i]<=a[i-1]||a[i]<=a[i+1];
	};
	for(int i=3;i<n-1;++i){
		if(!check(i-1)&&!check(i+1)){
			a[i]=max(a[i-1],a[i+1]);
			++ans;
		}
	}
	for(int i=2;i<n;++i){
		if(!check(i)){
			a[i]=max(a[i-1],a[i+1]);
			++ans;
		}
	}
	cout<<ans<<'\n';
	for(int i=1;i<=n;++i){
		cout<<a[i]<<' ';
	}
	cout<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}