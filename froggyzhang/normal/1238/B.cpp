#include<bits/stdc++.h>
using namespace std;
#define N 100010
typedef long long ll;
int n,m,a[N];
void Solve(){
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	n=unique(a+1,a+n+1)-a-1;
	for(int i=n;i>=1;--i){
		if(a[i-1]-1LL*(n-i+1)*m<=0){
			cout<<n-i+1<<'\n';
			return;
		}		
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