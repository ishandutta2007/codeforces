#include<bits/stdc++.h>
using namespace std;
#define N 300020
typedef long long ll;
map<int,int> cnt;
set<pair<int,int> > S;
int n,m,a[N];
map<int,vector<int> > mp;
void Solve(){
	cin>>n>>m;
	cnt.clear();
	mp.clear();
	for(int i=1;i<=n;++i){
		cin>>a[i];
		++cnt[a[i]];
	}
	S.clear();
	for(int i=1;i<=m;++i){
		int u,v;
		cin>>u>>v;
		S.emplace(u,v);
		S.emplace(v,u);
	}
	for(auto [x,y]:cnt){
		mp[y].push_back(x);
	}
	for(auto &[u,A]:mp){
		reverse(A.begin(),A.end());
	}
	ll ans=0;
	for(auto &[u,A]:mp){
		for(int i=0;i<(int)A.size();++i){
			int x=A[i];
			for(auto &[v,B]:mp){
				if(v>u)break;
				for(int j=0;j<(int)B.size();++j){
					int y=B[j];
					if(x!=y&&!S.count(make_pair(x,y))){
						ans=max(ans,1LL*(u+v)*(x+y));
						break;
					}
				}
			}
		}
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