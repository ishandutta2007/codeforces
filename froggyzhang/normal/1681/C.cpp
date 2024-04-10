#include<bits/stdc++.h>
using namespace std;
#define N 233
typedef long long ll;
int n,a[N],b[N],p[N],to[N];
void Solve(){
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	for(int i=1;i<=n;++i){
		cin>>b[i];
		p[i]=i;
	}
	sort(p+1,p+n+1,[&](int i,int j){return make_pair(a[i],b[i])<make_pair(a[j],b[j]);});
	for(int i=1;i<n;++i){
		if(b[p[i]]>b[p[i+1]]){
			cout<<-1<<'\n';
			return;
		}
	}
	for(int i=1;i<=n;++i){
		to[p[i]]=i;
	}
	vector<pair<int,int> > ans;
	while(true){
		bool ok=true;
		for(int i=1;i<=n;++i){
			if(to[i]^i){
				ans.emplace_back(i,to[i]);
				swap(to[to[i]],to[i]);
				ok=false;
				break;
			}
		}
		if(ok)break;
	}
	cout<<ans.size()<<'\n';
	for(auto [x,y]:ans){
		cout<<x<<' '<<y<<'\n';
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}