#include<bits/stdc++.h>
using namespace std;

int main(){
#ifdef flukehn
	freopen("a.in","r",stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--){
		long long a,b,c;
		cin>>a>>b>>c;
		cout<<a+b+c-1<<"\n";
	}
}