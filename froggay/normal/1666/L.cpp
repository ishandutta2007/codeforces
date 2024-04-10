#include<bits/stdc++.h>
using namespace std;
#define N 200020
int n,m,S,from[N],las[N],vis[N];
vector<int> G[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>S;
	for(int i=1;i<=m;++i){
		int u,v;
		cin>>u>>v;
		G[u].push_back(v);
	}
	vis[S]=1;
	queue<int> q;
	q.push(S);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(auto v:G[u]){
			if(vis[v]){
				if(v==S)continue;
				if(u==S||from[u]^from[v]){
					cout<<"Possible\n";
					vector<int> A,B;
					A.push_back(v);
					for(int x=u;x;x=las[x]){
						A.push_back(x);
					}
					reverse(A.begin(),A.end());
					for(int x=v;x;x=las[x]){
						B.push_back(x);
					}
					reverse(B.begin(),B.end());
					cout<<A.size()<<'\n';
					for(auto x:A){
						cout<<x<<' ';
					}
					cout<<'\n'<<B.size()<<'\n';
					for(auto x:B){
						cout<<x<<' ';
					}
					cout<<'\n';
					return 0;
				}
			}
			else{
				vis[v]=1;
				q.push(v);
				from[v]=u==S?v:from[u];
				las[v]=u;
			}
		}
	}
	cout<<"Impossible\n";
	return 0;
}