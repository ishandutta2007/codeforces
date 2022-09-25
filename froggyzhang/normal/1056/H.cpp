#include<bits/stdc++.h>
using namespace std;
#define N 300030
#define B 505
const int P=500;
typedef long long ll;
typedef pair<int,int> pii;
int n,m;
vector<int> a[N];
vector<pii> G[N];
void Solve(){
	cin>>n>>m;
	for(int i=1;i<=m;++i)a[i].clear();
	for(int i=1;i<=n;++i)G[i].clear();
	for(int i=1;i<=m;++i){
		int len;
		cin>>len;
		a[i].resize(len);
		for(int j=0;j<len;++j){
			cin>>a[i][j];
		}
		if(len<=P){
			for(int j=0;j<len-1;++j){
				for(int k=j+1;k<len;++k){
					G[a[i][j]].emplace_back(a[i][k],a[i][j+1]);	
				}
			}
		}
	}
	static int jb[N];
	for(int i=1;i<=n;++i)jb[i]=0;
	for(int u=1;u<=n;++u){
		for(auto [v,w]:G[u]){
			if(!jb[v])jb[v]=w;
			else if(jb[v]^w){
				cout<<"Human\n";
				return;
			}	
		}
		for(auto [v,w]:G[u]){
			jb[v]=0;
		}
	}
	for(int i=1;i<=m;++i){
		if(a[i].size()>P){
			static int las[N];
			static pii t1[N],t2[N];
			for(int j=1;j<=n;++j){
				t1[j]=t2[j]={-1,-1};	
				las[j]=-1;
			}
			for(int j=0;j<(int)a[i].size();++j){
				las[a[i][j]]=j;
			}
			for(int j=1;j<(int)a[i].size();++j){
				if(!~t1[a[i][j-1]].first){
					t1[a[i][j-1]]={a[i][j],j};
				}
				else if(a[i][j]^t1[a[i][j-1]].second){
					t2[a[i][j-1]]={a[i][j],j};
				}
			}
			for(int j=1;j<=m;++j){
				if(i==j)continue;
				int now=n+1;
				for(int k=0;k<(int)a[j].size();++k){
					int c=a[j][k];
					if(~las[c]){
						if(las[c]>now){
							cout<<"Human\n";
							return;
						}
					}
					if(k>0){
						int x=a[j][k-1];
						if(~t1[x].first&&t1[x].first^c){
							now=min(now,t1[x].second);
						}
						else if(~t2[x].first){
							now=min(now,t2[x].second);
						}
					}
				}	
			}
		}
	}
	cout<<"Robot\n";
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}