#include<bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;
int n,a[N];
void Solve(){
	cin>>n;
	for(int i=0;i<n;++i){
		cin>>a[i];
	}
	int ans=(1<<25)-1;
	for(int i=0;i<n;++i){
		if(i^a[i])ans&=i&a[i];
	}
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}