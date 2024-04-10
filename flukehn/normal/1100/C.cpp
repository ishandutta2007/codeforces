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
	int n,r;
	while(cin>>n>>r){
		double w=pi/n;
		double R=sin(w)/(1-sin(w))*r;
		cout<<R<<"\n";
	}
}