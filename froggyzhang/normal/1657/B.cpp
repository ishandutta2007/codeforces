#include<bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;
int n,B,x,y,a[N];
void Solve(){
	cin>>n>>B>>x>>y;
	for(int i=1;i<=n;++i){
		if(a[i-1]+x<=B)a[i]=a[i-1]+x;
		else a[i]=a[i-1]-y;
	}
	cout<<accumulate(a+1,a+n+1,0LL)<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}