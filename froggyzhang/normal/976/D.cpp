#include<bits/stdc++.h>
using namespace std;
#define N 1003
typedef long long ll;
typedef pair<int,int> pii;
int m,d[N],n;
vector<pii> E;
pii a[N];
pair<vector<pii>,bool> Solve(){
	vector<pii> E;
	while(true){
		sort(a+1,a+n+1,greater<pii>());
		int u=a[1].second;
		if(!a[1].first)break;
		for(int i=2;i<=a[1].first+1;++i){
			if(!a[i].first)return make_pair(E,false);
			--a[i].first;
			E.emplace_back(u,a[i].second);	
		}
		a[1].first=0;
	}
	return make_pair(E,true);
}
mt19937 rnd(time(0));
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>m;
	for(int i=1;i<=m;++i){
		cin>>d[i];
	}
	n=d[m]+1;
	while(true){
		for(int i=1;i<=m;++i){
			a[n-i+1]=pii(d[m-i+1],n-i+1);
		}
		for(int i=1;i<=n-m;++i){
			a[i]=pii(m==1?d[m]:d[rnd()%(m-1)+1],i);
		}
		int sum=0;
		for(int i=1;i<=n;++i){
			sum+=a[i].first;
		}
		if(sum&1){
			for(int i=1;i<=m;++i){
				if((d[i]^a[1].first)&1){a[1].first=d[i];break;}	
			}
		}
		auto [_e,_ok]=Solve();
		if(_ok){
			E.insert(E.end(),_e.begin(),_e.end());
			break;	
		}
	}
	cout<<E.size()<<'\n';
	for(auto [u,v]:E){
		cout<<u<<' '<<v<<'\n';
	}
	return 0;
}