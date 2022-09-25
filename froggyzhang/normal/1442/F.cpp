#include<bits/stdc++.h>
using namespace std;
#define N 1011
typedef long long ll;
typedef pair<int,int> pii;
int n,m,Q,d[N],B,mp[N][N],gg[1<<20],t[N],jb[N];
vector<int> P,G[N];
vector<tuple<int,int,int> > E;
vector<int> qwq[10];
void topo(){
	queue<int> q;
	static int d[N];
	for(int i=1;i<=n;++i){
		for(auto v:G[i])++d[v];
	}
	for(int i=1;i<=n;++i){
		if(!d[i])q.push(i);	
	}	
	while(!q.empty()){
		int u=q.front();
		P.push_back(u);
		q.pop();
		for(auto v:G[u]){
			if(!--d[v])q.push(v);
		}
	}
	reverse(P.begin(),P.end());
}
int Ask(int x){
	cout<<"? 1 "<<x<<endl;
	string opt;
	cin>>opt;
	if(opt=="Win")return 1;
	if(opt=="Draw")return 0;
	if(opt=="Lose")return -1;
	assert(false);	
}
void Report(int x){
	cout<<"! "<<x<<endl;
	string opt;
	cin>>opt;
	assert(opt=="Correct");	
}
mt19937 rnd(time(0));
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>Q;
	B=min(20,n);
	for(int i=1;i<=m;++i){
		int u,v;
		cin>>u>>v;
		G[u].push_back(v);
		mp[u][v]=1;
	}
	for(int i=0;i<(1<<B);++i){
		int cnt=__builtin_popcount(i);
		if(cnt<=8)qwq[cnt].push_back(i);
	}
	topo();
	memset(jb,-1,sizeof(jb));
	for(int i=0;i<B;++i)jb[P[i]]=i;
	for(int i=1;i<B;++i){
		for(int j=0;j<i;++j){
			if(!mp[P[i]][P[j]]){
				E.emplace_back(P[i],P[j],1);
			}	
		}	
	}
	for(int i=B;i<n;++i){
		int u=P[i];
		E.emplace_back(u,u,1);
		for(auto v:G[u]){
			if(~jb[v])t[u]|=1<<jb[v];	
		}
		for(int j=0,ok=0;!ok;++j){
			for(auto z:qwq[j]){
				if(!gg[t[u]^z]){
					for(int k=0;k<B;++k){
						if(z>>k&1){
							E.emplace_back(u,P[k],t[u]>>k&1?0:1);
						}
					}
					t[u]^=z;
					ok=1;
					break;
				}		
			}
		}
		gg[t[u]]=u;
	}
	cout<<E.size()<<'\n';
	for(auto [x,y,opt]:E){
		cout<<(opt?'+':'-')<<' '<<x<<' '<<y<<'\n';
	}
	cout<<endl;
	while(Q--){
		int st=0,ok=0;
		for(int i=0;i<B;++i){
			int z=Ask(P[i]);
			if(z==-1){
				ok=1;
				Report(P[i]);
				break;
			}
			if(z==1)st|=1<<i;
		}
		if(!ok){
			Report(gg[st]);	
		}
	}
	return 0;
}