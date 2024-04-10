#include<bits/stdc++.h>
using namespace std;
#define N 400040
typedef long long ll;
int n,k,a[N];
void Solve(){
	cin>>n>>k;
	for(int i=1;i<=k;++i){
		cin>>a[i];
	}
	sort(a+1,a+k+1,greater<int>());
	for(int i=1,now=0;i<=k;++i){
		now+=n-a[i];
		if(now>=n){
			cout<<i-1<<'\n';
			return;
		}
	}
	cout<<k<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}