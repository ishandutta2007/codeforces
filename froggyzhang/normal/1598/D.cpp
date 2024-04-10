#include<bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;
int n,cnt[N];
vector<int> a[N];
void Solve(){
	cin>>n;
	for(int i=1;i<=n;++i)a[i].clear(),cnt[i]=0;
	for(int i=1,x,y;i<=n;++i){
		cin>>x>>y;
		++cnt[y];
		a[x].push_back(y);
	}
	for(int i=1;i<=n;++i)--cnt[i];
	ll ans=0;
	for(int i=1;i<=n;++i){
		for(auto x:a[i]){
			ans+=cnt[x]*(a[i].size()-1);	
		}
	}
	cout<<1LL*n*(n-1)*(n-2)/6-ans<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}