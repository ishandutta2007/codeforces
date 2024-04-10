#include<bits/stdc++.h>
using namespace std;
#define N 400040
typedef long long ll;
int a[N],n;
void Solve(){
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int g=0;
	for(int i=2;i<=n;++i){
		if(a[i]==a[i-1])continue;
		g=__gcd(g,a[i]-a[i-1]);
	}
	cout<<(g?g:-1)<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}