#include<bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;
int n,Q,a[N],vis[N];
vector<int> d;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>Q;
	ll ans=0;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		ans+=a[i];
	}
	int tag=-1;
	while(Q--){
		int opt;
		cin>>opt;
		if(opt==1){
			int x,y;
			cin>>x>>y;
			if(~tag&&!vis[x]){
				d.push_back(x);
				vis[x]=1;
				a[x]=tag;
			}
			ans-=a[x];
			a[x]=y;
			ans+=y;
		}
		else{
			int x;
			cin>>x;
			ans=1LL*x*n;
			tag=x;
			for(auto x:d){
				vis[x]=0;
			}
			d.clear();
		}
		cout<<ans<<'\n';
	}
	return 0;
}