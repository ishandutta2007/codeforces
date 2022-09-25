#include<bits/stdc++.h>
using namespace std;
#define N 100010
typedef long long ll;
int n,m,Q;
vector<tuple<int,int,int> > E;
class Union_Set{
	int f[N],ok[N];
public:
	void init(int n){
		for(int i=1;i<=n;++i){
			f[i]=i;
		}
	}
	inline int getf(int x){
		return f[x]==x?x:f[x]=getf(f[x]);
	}
	void Merge(int x,int y){
		int fx=getf(x),fy=getf(y);
		if(fx==fy)return;
		f[fy]=fx;
	}
	void set(int u){
		ok[getf(u)]=1;
	}
	bool chk(int u){
		return ok[getf(u)];
	}
}S[30];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=m;++i){
		int u,v,w;
		cin>>u>>v>>w;
		E.emplace_back(u,v,w);
	}
	for(int i=0;i<30;++i){
		S[i].init(n);
	}
	for(auto [u,v,w]:E){
		for(int i=0;i<30;++i){
			if(w>>i&1)S[i].Merge(u,v);
		}
	}
	for(auto [u,v,w]:E){
		if(!(w&1)){
			for(int i=1;i<30;++i){
				S[i].set(u),S[i].set(v);
			}
		}
	}
	cin>>Q;
	while(Q--){
		int u,v;
		cin>>u>>v;
		int ans=2;
		for(int i=0;i<30;++i){
			if(S[i].getf(u)==S[i].getf(v)){
				ans=0;
				break;
			}
		}
		if(ans){
			for(int i=0;i<30;++i){
				if(S[i].chk(u)){
					ans=1;
					break;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}