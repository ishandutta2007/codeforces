#include<bits/stdc++.h>
using namespace std;
long long work(int n,int x,int t){
	if(x>t)return 0;
	int d=t/x;
	if(n<d) return 1ll * (0 + n-1) * n / 2;
	return 1ll*(0+d-1)*d/2 + 1ll*(n-d) * d;
}
int main(){
#ifdef flukehn
	freopen("a.in","r",stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout<<fixed<<setprecision(12);
	int T;
	cin>>T;
	int n,x,t;
	while(cin>>n>>x>>t){
		cout<<work(n,x,t)<<"\n";
	}
}