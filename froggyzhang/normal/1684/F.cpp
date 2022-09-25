#include<bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;
int n,m,a[N],g[N],p[N];
map<int,vector<int> > mp;
void Solve(){
	cin>>n>>m;
	mp.clear();
	for(int i=1;i<=n;++i){
		cin>>a[i];
		g[i]=p[i]=n+1;
		mp[a[i]].push_back(i);
	}
	for(int i=1;i<=m;++i){
		int l,r;
		cin>>l>>r;
		g[r]=min(g[r],l);
	}
	int ans=n;
	int lim=1,mx=n+1;
	for(int i=n,k=n;i>=1;--i){
		k=min(k,g[i]);
		mp[a[i]].pop_back();
		if(k<i){
			int las=mp[a[i]].empty()?-1:mp[a[i]].back();
			if(las>=k){
				lim=max(lim,las);
				auto it=lower_bound(mp[a[i]].begin(),mp[a[i]].end(),k);
				int t0=*it;
				int t1=(++it)==mp[a[i]].end()?i:*it;
				mx=min(mx,t1);
				p[i-1]=min(p[i-1],t0);
			}
		}
	}
	for(int i=n;i>=lim;--i){
		mx=min(mx,p[i]);
		ans=min(ans,max(0,i-mx+1));
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