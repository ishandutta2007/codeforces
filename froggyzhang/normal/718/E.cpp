#include<bits/stdc++.h>
using namespace std;
#define N 100010
typedef long long ll;
const int inf=0x3f3f3f3f;
int n,a[N],C,L,d[N][8];
char s[N];
queue<int> q;
int dis[N];
vector<int> p[8];
void init(){
	for(int i=1;i<=n;++i)dis[i]=inf;
}
void bfs(){
	static bool vis[8];
	memset(vis,false,sizeof(vis));
	while(!q.empty()){
		int u=q.front();
		q.pop();
		if(!vis[a[u]]){
			vis[a[u]]=1;
			for(auto v:p[a[u]]){
				if(dis[v]==inf){
					q.push(v);
					dis[v]=dis[u]+1;
				}	
			}
		}
		if(u>1){
			if(dis[u-1]==inf){
				q.push(u-1);
				dis[u-1]=dis[u]+1;
			}	
		}
		if(u<n){
			if(dis[u+1]==inf){
				q.push(u+1);
				dis[u+1]=dis[u]+1;
			}
		}
	}
}
map<vector<int>,vector<int> > mp;
ll calc(int L){
	auto check=[&](int i,int j)->bool{
		for(int k=0;k<C;++k){
			if(d[i][k]+d[j][k]+1<L){
				return false;
			}
		}
		return true;
	};
	ll tot=0;
	for(int i=1;i<=n;++i){
		for(int j=i;j<i+L;++j){
			bool ok=check(i,j);	
			if(i==j)tot-=ok;
			else tot-=2*ok;
		}
	}
	for(auto [t1,V1]:mp){
		for(auto [t2,V2]:mp){
			tot+=1LL*V1.size()*V2.size()*check(V1[0],V2[0]);	
		}
	}
	return tot/2;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	cin>>(s+1);
	for(int i=1;i<=n;++i){
		a[i]=s[i]-'a';
		p[a[i]].push_back(i);
	}
	C=(*max_element(a+1,a+n+1))+1;
	L=1;
	for(int t=0;t<C;++t){
		init();
		for(int i=1;i<=n;++i){
			if(a[i]==t){
				q.push(i);
				dis[i]=0;
			}
		}
		if(q.empty()){
			for(int i=1;i<=n;++i)d[i][t]=inf;
			continue;
		}
		bfs();
		for(int i=1;i<=n;++i){
			d[i][t]=dis[i];
			L=max(L,d[i][t]);
		}
	}
	for(int i=1;i<=n;++i){
		vector<int> jb;
		jb.push_back(a[i]);
		for(int j=0;j<C;++j){
			jb.push_back(d[i][j]);	
		}
		mp[jb].push_back(i);
	}
	ll jb=calc(L+1);
	if(jb){
		cout<<L+1<<' '<<jb<<'\n';
		return 0;	
	}
	cout<<L<<" "<<calc(L)<<'\n';
	return 0;
}