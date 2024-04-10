#include<bits/stdc++.h>
using namespace std;
const double pi=acos(-1);
int main(){
#ifdef flukehn
	freopen("a.in","r",stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout<<fixed<<setprecision(12);
	//int T;cin>>T;
	double d,h,v,e;
	while(cin>>d>>h>>v>>e){
		d=d*d/4*pi;
		e=e*d;
		h=h*d;
		if(e>=v) cout<<"NO\n";
		else{
			cout<<"YES\n";
			cout<<h/(v-e)<<"\n";
		}
	}
}