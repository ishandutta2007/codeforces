#include<bits/stdc++.h>
using namespace std;
const int N=2e5+11;
int n,m;
int d[N];
int main(){
#ifdef flukehn
	freopen("a.in","r",stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	int ans=n;
	for(int i=1;i<=m;++i){
		int x,y;
		cin>>x>>y;
		x=min(x,y);
		ans-=!d[x];
		++d[x];
		ans+=!d[x];
	}
	int Q;
	cin>>Q;
	while(Q--){
		int op;
		cin>>op;
		int x,y;
		if(op<3){
			cin>>x>>y;
			x=min(x,y);
		}
		if(op==1){
			ans-=!d[x];
			++d[x];
			ans+=!d[x];
		}else if(op==2){
			ans-=!d[x];
			--d[x];
			ans+=!d[x];
		}else{
			cout<<ans<<"\n";
		}
	}
}