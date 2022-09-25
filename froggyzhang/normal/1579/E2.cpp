#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define N 200020
typedef long long ll;
tree<pair<int,int>,null_type,less<pair<int,int> >,rb_tree_tag,tree_order_statistics_node_update> T;
int n,a[N];
void Solve(){
	T.clear();
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	ll ans=0;
	for(int i=1;i<=n;++i){
		int t1=T.order_of_key(make_pair(a[i],0));
		int t2=i-1-T.order_of_key(make_pair(a[i]+1,0));
		ans+=min(t1,t2);
		T.insert(make_pair(a[i],i));	
	}
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}