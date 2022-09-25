#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--){
		int u,v;
		cin>>u>>v;
		cout<<1LL*u*u<<' '<<-1LL*v*v<<'\n';
	}
	return 0;
}