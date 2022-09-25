#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define N 300030
typedef long long ll;
int n,a[N];
ll s[N];
map<ll,tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> > mp[2];
void Solve(){
	mp[0].clear();
	mp[1].clear();
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		s[i]=a[i]-s[i-1];
	}
	static ll st[2][N];
	static int top[2];
	top[0]=top[1]=0;
	ll ans=0;
	for(int i=n;i>=1;--i){
		int c=i&1;
		while(top[c]&&s[i]<=s[st[c][top[c]]])top[c]--;
		st[c][++top[c]]=i;
		mp[i&1][s[i]].insert(i);
		
		c=(i-1)&1;
		auto Get=[&](ll *a,int len,ll x)->int{
			int l=1,r=len+1,pos=0;
			while(l<r){
				int mid=(l+r)>>1;
				if(s[a[mid]]<x){
					pos=mid;l=mid+1;
				}
				else{
					r=mid;
				}
			}
			return pos;
		};
		int p0=Get(st[c],top[c],s[i-1]);
		int p1=Get(st[c^1],top[c^1],-s[i-1]);
		p0=!p0?n:st[c][p0];
		p1=!p1?n:st[c^1][p1];
		ans+=mp[c][s[i-1]].order_of_key(min(p0,p1)+1)+mp[c^1][-s[i-1]].order_of_key(min(p0,p1)+1);
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