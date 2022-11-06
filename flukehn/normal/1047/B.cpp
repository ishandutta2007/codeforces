#include<bits/stdc++.h>
using namespace std;
int main(){
#ifdef flukehn
	freopen("a.in","r",stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	while(cin>>n){
		int ans=0;
		for(int i=0;i<n;++i){
			int x,y;
			cin>>x>>y;
			ans=max(ans,x+y);
		}
		cout<<ans<<'\n';
	}
}