#include<bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;
int n,m;
vector<int> a[N];
set<vector<int> > S,q;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	vector<int> beg(n+1);
	for(int i=1;i<=n;++i){
		int k;
		cin>>k;
		a[i].resize(k);
		for(int j=0;j<k;++j)cin>>a[i][j];
	}
	for(int i=1;i<=n;++i)beg[i]=(int)a[i].size()-1,beg[0]+=a[i][beg[i]];
	q.insert(beg);
	cin>>m;
	for(int i=1;i<=m;++i){
		vector<int> v(n+1);
		for(int j=1;j<=n;++j){
			cin>>v[j];
			--v[j];
			v[0]+=a[j][v[j]];
		}
		S.insert(v);
	}
	while(true){
		auto u=*--q.end();
		q.erase(--q.end());
		if(!S.count(u)){
			for(int i=1;i<=n;++i)cout<<u[i]+1<<' ';
			cout<<'\n';
			return 0;
		}
		for(int i=1;i<=n;++i){
			if(u[i]>0){
				auto v=u;
				--v[i];
				v[0]+=a[i][v[i]]-a[i][v[i]+1];
				q.insert(v);
			}
		}
	}
	return 0;
}