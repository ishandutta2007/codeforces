#include<bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;
int n,a[N];
set<pair<int,int> > s;
void Solve(){
	cin>>n;
	s.clear();
	for(int i=1;i<=n;++i){
		cin>>a[i];
		if(a[i])s.emplace(a[i],i);
	}
	vector<pair<int,int> > ans;
	while(s.size()>1){
		int x=s.begin()->second;
		int y=s.rbegin()->second;
		s.erase(s.begin());
		s.erase(--s.end());
		--a[x],--a[y];
		ans.emplace_back(x,y);
		if(a[x])s.emplace(a[x],x);
		if(a[y])s.emplace(a[y],y);
	}
	cout<<ans.size()<<'\n';
	for(auto [x,y]:ans)cout<<x<<' '<<y<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}