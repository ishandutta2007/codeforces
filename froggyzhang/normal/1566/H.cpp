#include<bits/stdc++.h>
using namespace std;
#define N 1000100
typedef long long ll;
int n,m,c[N],f[N],bitcnt[N<<1],g[N],ok[N];
pair<int,bool> st[N];
mt19937 rnd(time(0));
class Basis{
	int d[21],mask[21];
public:
	vector<int> V;
	Basis(){memset(d,0,sizeof(d));memset(mask,0,sizeof(mask));V.clear();}
	pair<int,bool> Insert(int x){
		int myh=x,s=0;
		for(int i=20;i>=0;--i){
			if(x>>i&1){
				if(!d[i]){
					int t=1<<V.size();
					V.push_back(myh);
					mask[i]=s|t;
					d[i]=x;
					return make_pair(mask[i],true);
				}
				else{
					x^=d[i];
					s^=mask[i];	
				}
			}
		}
		return make_pair(s,false);
	}
}b[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)c[i]=i;
	for(int i=2;i*i<=n;++i){
		for(int j=i*i;j<=n;j+=i*i){
			while(c[j]%(i*i)==0)c[j]/=i;	
		}
	}
	vector<int> P;
	for(int i=1;i<=n;++i){
		if(c[i]==i)P.push_back(i);
	}
	cout<<P.size()<<'\n';
	for(auto x:P)cout<<x<<' ';
	cout<<endl;
	for(auto x:P)cin>>f[x];	
	for(int i=2;i<=n;++i){
		if(c[i]==i)f[i]^=f[1];
	}
	for(int i=2;i<=n;++i){
		if(c[i]==i)
		for(int j=i+i;j<=n;j+=i){
			if(c[j]==j)f[j]^=f[i];
		}
	}
	for(int i=n;i>=1;--i){
		if(c[i]==i)
		for(int j=i+i;j<=n;j+=i){
			if(c[j]==j)f[i]^=f[j];
		}
	}
	int LG=__lg(n)+1,now=0;
	for(int i=1;i<(1<<LG);++i){
		bitcnt[i]=bitcnt[i>>1]+(i&1);
	}
	vector<int> A;
	for(int i=1;i<=n;++i){
		if(c[i]==i){
			for(int j=i;j<=n;j+=i){
				if(c[j]==i){
					st[j]=b[i].Insert(j);
					if(!st[j].second)A.push_back(j);
				}
			}
			g[i]=b[i].Insert(f[i]).first;
			now+=bitcnt[g[i]];
			for(int j=0;j<(int)b[i].V.size();++j){
				if(g[i]>>j&1){
					ok[b[i].V[j]]=1;	
				}
			}
		}
	}
	while(now^m){
		int u=A[rnd()%A.size()];
		now-=ok[u];
		ok[u]^=1;
		now+=ok[u];
		now-=bitcnt[g[c[u]]];
		g[c[u]]^=st[u].first;
		now+=bitcnt[g[c[u]]];
		for(int j=0;j<(int)b[c[u]].V.size();++j){
			if(st[u].first>>j&1){
				ok[b[c[u]].V[j]]^=1;
			}	
		}
	}
	for(int i=1;i<=n;++i){
		if(ok[i])cout<<i<<' ';
	}
	cout<<endl;
	return 0;
}