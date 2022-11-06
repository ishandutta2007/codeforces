#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		long long ans=0;
		int y=-1;
		for(int i=1;i<=n;++i){
			int x;
			cin>>x;
			ans=max(ans,1LL*x*y);
			y=x;
		}
		cout<<1LL*ans<<"\n";
	}
}