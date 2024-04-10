#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const int N=8e5+5;
int f[226];
int n,m;
vector<int>adj[N];
int tid[N],d[N];
int ans[N];
int mxd;

int sz=1;
char col[N];
int ch[N][26],pa[N];
int jp[N][26],fa[N];
vector<int>ly[N];
vector<int>slc[N];

vector<pair<int,int> >qr[N];

int bit[N];
void upd(int id,int v){
	for(int i=id; i<=sz ;i+=i&-i) bit[i]+=v;
}
int qry(int id){
	int res=0;
	for(int i=id; i>=1 ;i-=i&-i) res+=bit[i];
	return res;
}

int ptr;
int st[N],en[N];
void dfs(int id){
	st[id]=++ptr;
	for(auto c:slc[id]) dfs(c);
	en[id]=ptr;
}
void dfs2(int id){
	upd(st[tid[id]],1);
	for(auto c:qr[id]){
		ans[c.se]=qry(en[c.fi])-qry(st[c.fi]-1);
	}
	for(auto c:adj[id]){
		dfs2(c);
	}
	upd(st[tid[id]],-1);
}
int main(){
	ios::sync_with_stdio(false);
	for(char c='a'; c<='z' ;c++) f[c]=c-'a';
	cin >> n;tid[0]=1;
	for(int i=1; i<=n ;i++){
		int t;cin >> t;
		int x=0;
		if(t==2) cin >> x;
		char c;cin >> c;
		int y=tid[x];
		if(ch[y][f[c]]==0){
			ch[y][f[c]]=++sz;
			d[sz]=d[y]+1;
			pa[sz]=y;	
			col[sz]=c;
			ly[d[sz]].push_back(sz);
			mxd=max(mxd,d[sz]);
		}
		tid[i]=ch[y][f[c]];
		adj[x].push_back(i);
	}
	cin >> m;
	for(int i=1; i<=m ;i++){
		int k;string s;cin >> k >> s;
		int y=1;
		for(auto c:s){
			if(ch[y][f[c]]==0){
				ch[y][f[c]]=++sz;
				d[sz]=d[y]+1;
				pa[sz]=y;	
				col[sz]=c;
				ly[d[sz]].push_back(sz);
				mxd=max(mxd,d[sz]);
			}
			y=ch[y][f[c]];
		}
		qr[k].push_back({y,i});
	}
	//return 0;
	for(int j=0; j<26 ;j++) jp[1][j]=ch[1][j];
	for(int i=1; i<=mxd ;i++){
		for(auto id:ly[i]){
			int x=fa[pa[id]];
			char c=col[id];
			fa[id]=jp[x][f[c]];
			if(fa[id]==0) fa[id]=1;
			slc[fa[id]].push_back(id);
			for(int j=0; j<26 ;j++){
				if(ch[id][j]!=0) jp[id][j]=ch[id][j];
				else jp[id][j]=jp[fa[id]][j];
			}
			//cout << "sl " << id << ' ' << fa[id] << endl;
		}
	}
	//cout << "bad" << endl;
	dfs(1);
	dfs2(0);
	for(int i=1; i<=m ;i++){
		cout << ans[i] << '\n';
	}
}