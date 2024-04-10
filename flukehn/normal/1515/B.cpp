#include<bits/stdc++.h>
using namespace std;
int main(){
#ifdef flukehn
	freopen("a.in","r",stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout<<fixed<<setprecision(12);
	int T;
	cin>>T;
	auto issqr=[](int n){
		int d=sqrt(n);
		while(d*d<n)++d;
		return d*d==n;
	};
	int n;
	while(T--){
		cin>>n;
		puts( ( (n%2==0&&issqr(n/2)) || (n%4==0&&issqr(n/4) ) )?"YES":"NO");
	}
}