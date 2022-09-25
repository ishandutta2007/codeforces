#include<bits/stdc++.h>
using namespace std;
#define N 1026
typedef long long ll;
int n,d[N],f[N],vis[N],dep[N];
//#define mak akioi
namespace Grader{
	int dis[N][N];
	vector<int> G[N];
	void dfs(int u,int fa,int *dis){
		for(auto v:G[u]){
			if(v==fa)continue;
			dis[v]=dis[u]+1;
			dfs(v,u,dis);	
		}	
	}
	void init(){
		for(int i=1;i<n;++i){
			int u,v;
			cin>>u>>v;
			G[u].push_back(v);
			G[v].push_back(u);	
		}
		for(int i=1;i<=n;++i){
			dfs(i,0,dis[i]);	
		}
	}
	bitset<N> Query(){
		bitset<N> ans;
		ans.reset();
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				if(i==j)continue;
				if(dis[i][j]<=d[i])ans[j]=1;	
			}
		}
		for(int i=1;i<=n;++i){
			cerr<<ans[i];
		}
		cerr<<endl;
		return ans;
	}	
}
bitset<N> Ask(){
	cout<<"? ";
	for(int i=1;i<=n;++i){
		cout<<d[i]<<' ';
	}
	cout<<endl;
	#ifdef mak
	return Grader::Query();
	#endif
	static string s;
	cin>>s;
	bitset<N> B;
	B.reset();
	for(int i=1;i<=n;++i){
		B[i]=s[i-1]-'0';
	}
	return B;
}
vector<int> g[N],e[N],h[N],_e[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	#ifdef mak
	Grader::init();
	#endif
	int p=1;
	while((1<<p)<n)++p;
	e[0].push_back(1);
	vis[1]=1;
	for(int i=2;i<=n;++i){
		g[0].push_back(i);
	}
	for(int t=p-1,m=1;t>=0;--t,m<<=1){
		for(int i=0;i<(1<<p);++i)h[i].clear(),_e[i].clear();
		memset(d,0,sizeof(d));
		for(int i=0;i<m;++i){
			if(i&1){
				for(auto x:e[i])d[x]=(1<<t)-1;
			}
		}
		auto B1=Ask();
		
		
		memset(d,0,sizeof(d));
		for(int i=0;i<m;++i){
			if(!(i&1)){
				for(auto x:e[i])d[x]=(1<<t)-1;
			}
		}
		auto B2=Ask();
		
		
		memset(d,0,sizeof(d));
		for(int i=0;i<m;++i){
			if(i&1){
				for(auto x:e[i])d[x]=1<<t;
			}
		}
		auto C1=Ask();
		C1^=B1;
		for(int i=0;i<m;++i){
			if(i&1){
				for(auto x:g[i]){
					if(C1[x]){
						_e[i<<1|1].push_back(x);
						vis[x]=1;	
					}	
				}	
			}	
		}
		
		memset(d,0,sizeof(d));
		for(int i=0;i<m;++i){
			if(!(i&1)){
				for(auto x:e[i])d[x]=1<<t;
			}
		}
		auto C2=Ask();
		C2^=B2;
		for(int i=0;i<m;++i){
			if(!(i&1)){
				for(auto x:g[i]){
					if(C2[x]){
						_e[i<<1|1].push_back(x);
						vis[x]=1;	
					}	
				}	
			}	
		}
		for(int i=0;i<m;++i){
			if(i&1){
				for(auto x:g[i]){
					if(!vis[x])h[i<<1|(!B1[x])].push_back(x);	
				}
			}
		}
		for(int i=0;i<m;++i){
			if(!(i&1)){
				for(auto x:g[i]){
					if(!vis[x])h[i<<1|(!B2[x])].push_back(x);	
				}
			}
		}
		for(int i=0;i<m;++i){
			_e[i<<1]=e[i];
		}
		for(int i=0;i<(1<<p);++i)g[i]=h[i],e[i]=_e[i];
	}
	for(int i=0;i<(1<<p);++i){
		for(auto x:e[i])dep[x]=i;
	}
	for(int w=0;w<3;++w){
		static bitset<N> B[20];
		for(int i=0;i<p;++i){
			memset(d,0,sizeof(d));
			for(int j=0;j<(1<<p);++j){
				if(j%3==w){
					for(auto x:e[j]){
						if(x>>i&1)d[x]=1;
					}	
				}
			}
			B[i]=Ask();
		}
		for(int j=0;j<(1<<p);++j){
			if(j%3==w){
				for(auto x:e[j]){
					bitset<N> zyk;
					zyk.set();
					for(int i=0;i<p;++i){
						if(x>>i&1){
							zyk&=B[i];
						}
						else{
							zyk&=~B[i];	
						}
					}
					for(int k=1;k<=n;++k){
						if(zyk[k]&&dep[k]==dep[x]+1)f[k]=x;	
					}
				}	
			}	
		}
	}
	cout<<"!\n";
	for(int i=2;i<=n;++i){
		cout<<i<<' '<<f[i]<<'\n';
	}
	cout<<endl;
	return 0;
}