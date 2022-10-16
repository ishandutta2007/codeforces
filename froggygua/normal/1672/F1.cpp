#include<bits/stdc++.h>
using namespace std;
#define N 200010
typedef long long ll;
int n,a[N],b[N];
vector<int> p[N];
void Solve(){
	cin>>n;
	for(int i=1;i<=n;++i)p[i].clear(),b[i]=0;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		p[a[i]].push_back(i);
	}
	set<int> S;
	for(int i=1;i<=n;++i){
		if(!p[i].empty())S.insert(i);
	}
	while(!S.empty()){
		vector<int> del,A;
		for(auto x:S){
			A.push_back(p[x].back());
			p[x].pop_back();
			if(p[x].empty())del.push_back(x);
		}
		for(auto x:del)S.erase(x);
		for(int i=0;i<(int)A.size();++i){
			b[A[i]]=a[A[(i+1)%A.size()]];
		}
	}
	for(int i=1;i<=n;++i){
		cout<<b[i]<<' ';
	}
	cout<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}