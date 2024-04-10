#include<bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;
int T,n,a[N];
void Solve(){
	cin>>n;
	int cnt=0;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		cnt+=a[i];
	}
	if(cnt&1){
		cout<<"NO\n";
		return;
	}
	vector<int> ans;
	auto OP = [&](int u) ->void{
		int t=a[u]^a[u+1]^a[u+2];
		a[u]=a[u+1]=a[u+2]=t;
		ans.push_back(u);
	};
	for(int i=1,cnt=0;i<=n-2;++i){
		if(a[i]){
			if(!(cnt&1)){
				if(a[i+1]^a[i+2]||(!a[i+1]&&!a[i+2]))OP(i);
			}
		}
		else{
			if(a[i+1]&a[i+2])OP(i);	
		}
		cnt+=a[i];
	}
	for(int i=n;i>=3;--i){
		if(!a[i]&&a[i-1]&&a[i-2])OP(i-2);
	}
	for(int i=1;i<=n-2;++i){
		if(!a[i]&&a[i+1]&&a[i+2])OP(i);	
	}
	for(int i=1;i<=n;++i){
		if(a[i]){
			cout<<"NO\n";
			return;
		}
	}
	cout<<"YES\n";
	cout<<ans.size()<<'\n';
	for(auto x:ans)cout<<x<<' ';
	cout<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>T;
	while(T--)Solve();
	return 0;
}