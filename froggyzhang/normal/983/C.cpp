#include<bits/stdc++.h>
using namespace std;
#define N 2005
typedef long long ll;
const int inf=0x3f3f3f3f;
int n,a[N],b[N],pw[5],id[9*9*9*9];
struct State{
	int x,d,pos,st;	
};
int dis[N][5][9][505],cnt;
queue<State> q;
map<vector<int>,int> mp;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	pw[0]=1;
	for(int i=1;i<=4;++i)pw[i]=pw[i-1]*9;
	for(int i=0;i<9;++i)
		for(int j=0;j<=i;++j)
			for(int k=0;k<=j;++k)
				for(int l=0;l<=k;++l)
					mp[vector<int>({i,j,k,l})]=++cnt;	
	for(int i=0;i<9;++i)
		for(int j=0;j<9;++j)
			for(int k=0;k<9;++k)
				for(int l=0;l<9;++l){
					vector<int> v({i,j,k,l});
					int s=0;
					for(int p=0;p<4;++p){
						s+=pw[p]*v[p];
					}	
					sort(v.begin(),v.end(),greater<int>());
					id[s]=mp[v];
				}
	for(int i=1;i<=n;++i){
		cin>>a[i]>>b[i];
		--a[i],--b[i];
	}
	memset(dis,0x3f,sizeof(dis));
	dis[1][0][0][1]=0;
	q.push({1,0,0,0});
	while(!q.empty()){
		auto [u,d,pos,st]=q.front();
		q.pop();
		int w=dis[u][d][pos][id[st]];
		if(u>n&&!d){
			cout<<w<<'\n';
			return 0;
		}
		if(u<=n&&a[u]==pos&&d<4){
			int &k=dis[u+1][d+1][pos][id[st+pw[d]*b[u]]];
			if(k==inf)k=w+1,q.push({u+1,d+1,pos,st+pw[d]*b[u]});
		}
		for(int i=0;i<d;++i){
			if((st/pw[i])%9==pos){
				int nst=st%pw[i]+(st/pw[i]/9*pw[i]);
				int &k=dis[u][d-1][pos][id[nst]];
				if(k==inf)k=w+1,q.push({u,d-1,pos,nst});
			}
		}
		if(pos>0){
			int &k=dis[u][d][pos-1][id[st]];
			if(k==inf)k=w+1,q.push({u,d,pos-1,st});
		}
		if(pos<8){
			int &k=dis[u][d][pos+1][id[st]];
			if(k==inf)k=w+1,q.push({u,d,pos+1,st});
		}
	}
	return 0;
}