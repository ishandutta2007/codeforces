#include<bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;
int a[N],n;
void Solve(){
	cin>>n;
	int l=n+1,r=0;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	for(int i=1;i<n;++i){
		if(a[i]==a[i+1])l=min(l,i),r=max(r,i);
	}
	if(l>=r){
		cout<<0<<'\n';
		return;
	}
	cout<<max(1,r-l-1)<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}