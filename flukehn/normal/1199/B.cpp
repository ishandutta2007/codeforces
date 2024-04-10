#include<bits/stdc++.h>
using namespace std;
int main(){
#ifdef flukehn
	freopen("a.in","r",stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout<<fixed<<setprecision(12);
	double H,L;
	while(cin>>H>>L){
		cout<<(H*H+L*L)/(2*H)-H<<"\n";
	}
}