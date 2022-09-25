#include<bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;
int n,m,a[N],b[N];
void Solve(){
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	ll all=0;
	for(int i=1;i<=n;++i){
		all+=a[i]+m;
		b[i]=a[i]+i;
	}
	sort(b+1,b+n+1,greater<int>());
	for(int i=1;i<=m;++i){
		all-=b[i];
	}
	all-=1LL*m*(m-1)/2;
	cout<<all<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}