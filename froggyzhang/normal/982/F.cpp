#include<bits/stdc++.h>
using namespace std;
#define N 200050
#define M 600060
typedef long long ll;
typedef pair<int,int> pii;
int n,m,vis[N],ins[N],onc[M],pos[N],l[N],r[N],ovo[M];
vector<pii> G[N],H[N];
vector<int> cir;
bool check_cir(){
	static int d[N];
	for(int i=1;i<=n<<1;++i)d[i]=0;
	for(int i=1;i<=n<<1;++i){
		for(auto [v,id]:G[i]){
			if(!onc[id])++d[v];
		}	
	}
	queue<int> q;
	for(int i=1;i<=n<<1;++i){
		if(!d[i]){
			q.push(i);
		}	
	}
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(auto [v,id]:G[u]){
			if(onc[id])continue;
			if(!--d[v])q.push(v);	
		}
	}
	for(int i=1;i<=n<<1;++i){
		if(d[i])return true;
	}
	return false;
}
void dfs(int u){
	static int st[N],top,is_find,fe[N];
	ins[u]=vis[u]=1;
	st[++top]=u;
	for(auto [v,id]:G[u]){
		if(ins[v]&&!is_find){
			is_find=1;
			for(int i=top;i>=1;--i){
				cir.push_back(st[i]);
				if(st[i]==v)break;	
				onc[fe[st[i]]]=1;
				ovo[st[i-1]]=fe[st[i]];
			}
			onc[id]=1;
			ovo[u]=id;
		}
		else if(!vis[v]){
			fe[v]=id;
			dfs(v);	
		}
	}
	ins[u]=0;
	--top;
}
int _ok[N],need;
void topo1(){
	static int d[N];
	for(int i=1;i<=n<<1;++i){
		for(auto [v,id]:G[i]){
			if(!onc[id])++d[v];
		}	
	}
	queue<int> q;
	for(int i=1;i<=n<<1;++i){
		if(!d[i]){
			q.push(i);
		}	
	}
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(auto [v,id]:G[u]){
			if(onc[id])continue;
			l[v]=min(l[v],l[u]);
			r[v]=max(r[v],r[u]);
			if(!--d[v])q.push(v);	
		}
	}
	for(int i=0;i<(int)cir.size();++i){
		int u=cir[i];
		if(r[u]>i){
			++need;
			++_ok[i];
		}
	}
}
void topo2(){
	static int d[N];
	for(int i=1;i<=n<<1;++i){
		for(auto [v,id]:H[i]){
			if(!onc[id])++d[v];
		}	
	}
	queue<int> q;
	for(int i=1;i<=n<<1;++i){
		if(!d[i]){
			q.push(i);
		}	
	}
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(auto [v,id]:H[u]){
			if(onc[id])continue;
			l[v]=min(l[v],l[u]);
			r[v]=max(r[v],r[u]);
			if(!--d[v])q.push(v);	
		}
	}
	for(int i=0;i<(int)cir.size();++i){
		int u=cir[i];
		if(l[u]<i){
			++need;
			++_ok[0],--_ok[i];
		}
		if(r[u]>i){
			++need;
			++_ok[0],--_ok[i],++_ok[r[u]];
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		G[(i<<1)-1].emplace_back(i<<1,i);
		H[i<<1].emplace_back((i<<1)-1,i);
	}
	for(int i=1;i<=m;++i){
		int u,v;
		cin>>u>>v;
		G[u<<1].emplace_back((v<<1)-1,n+i);
		H[(v<<1)-1].emplace_back(u<<1,n+i);
	}
	if(!check_cir()){
		cout<<1<<'\n';
		return 0;	
	}
	for(int i=1;i<=n<<1;++i){
		if(!vis[i])dfs(i);	
	}
	reverse(cir.begin(),cir.end());
	if(check_cir()){
		cout<<-1<<'\n';
		return 0;
	}
	for(int i=1;i<=n<<1;++i){
		l[i]=n*2+1,r[i]=-1;	
	}
	for(int i=0;i<(int)cir.size();++i){
		pos[cir[i]]=l[cir[i]]=r[cir[i]]=i;
	}
	topo1();
	for(int i=1;i<=n<<1;++i){
		l[i]=n*2+1,r[i]=-1;	
	}
	for(int i=0;i<(int)cir.size();++i){
		l[cir[i]]=r[cir[i]]=i;
	}
	topo2();
	for(int i=1;i<(int)cir.size();++i){
		_ok[i]+=_ok[i-1];
	}
	vector<int> ans;
	for(int i=0;i<(int)cir.size();++i){
		if(_ok[i]==need){
			if(ovo[cir[i]]<=n){
				cout<<ovo[cir[i]]<<'\n';
				return 0;
			}	
		}	
	}
	cout<<-1<<'\n';
	return 0;
}