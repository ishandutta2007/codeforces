#include<bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;
set<int> S;
int n,a[N],b[N],vis[N];
vector<int> p[N];
void Solve(){
	cin>>n;
	for(int i=1;i<=n;++i)p[i].clear(),vis[i]=0;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	for(int i=1;i<=n;++i){
		cin>>b[i];
		if(b[i]==b[i-1])p[b[i]].push_back(i);
	}
	for(int i=1;i<=n;++i){
		reverse(p[i].begin(),p[i].end());
	}
	S.clear();
	for(int i=1;i<=n;++i)S.insert(i);
	for(int i=1;i<=n;++i){
		if(b[*S.begin()]==a[i]){
			vis[*S.begin()]=1;
			S.erase(S.begin());
			continue;
		}
		while(!p[a[i]].empty()&&vis[p[a[i]].back()])p[a[i]].pop_back();
		if(p[a[i]].empty()){
			cout<<"No\n";
			return;
		}
		S.erase(p[a[i]].back());
		p[a[i]].pop_back();
	}
	cout<<"Yes\n";
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}