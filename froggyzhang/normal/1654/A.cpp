#include<bits/stdc++.h>
using namespace std;
#define N 2333
typedef long long ll;
int n,a[N];
void Solve(){
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	cout<<a[n]+a[n-1]<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}