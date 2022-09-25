#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,ans;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1,now=0;i<=n;++i){
		int x;
		cin>>x;
		now=max(now,x);
		if(now==i)now=0,++ans;
	}
	cout<<ans<<'\n';
	return 0;
}