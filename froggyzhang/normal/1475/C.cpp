#include<bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;
int A,B,n,a[N],b[N],ca[N],cb[N];
map<pair<int,int>,int> mp;
void Solve(){
	cin>>A>>B>>n;
	for(int i=1;i<=A;++i)ca[i]=0;
	for(int i=1;i<=B;++i)cb[i]=0;
	mp.clear();
	for(int i=1;i<=n;++i)cin>>a[i];
	for(int i=1;i<=n;++i)cin>>b[i];
	for(int i=1;i<=n;++i){
		++mp[make_pair(a[i],b[i])];
		++ca[a[i]],++cb[b[i]];
	}
	ll ans=0;
	for(int i=1;i<=n;++i){
		ans+=n-ca[a[i]]-cb[b[i]]+mp[make_pair(a[i],b[i])];	
	}
	cout<<ans/2<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}