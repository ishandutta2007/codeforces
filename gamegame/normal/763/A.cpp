#include<iostream>
#include<queue>
#include<algorithm>
#include<cmath>
using namespace std;
int n,m,k,p,q;
int c[100001];//done
int s[100001];//done
int rcnt;//done
bool vis[100001];//done
vector<int>adj[100001];//done
vector<int>ch[100001];//done
int subc[100001];//done
bool subk[100001];//done
int ans;
void dfs1(int id){
	int cc=c[id];
	s[id]=1;
	vis[id]=true;
	for(int i=0; i<adj[id].size() ;i++){
		if(!vis[adj[id][i]]){
			dfs1(adj[id][i]);
			ch[id].push_back(adj[id][i]);
			s[id]+=s[adj[id][i]];
			if(!subk[adj[id][i]] || cc!=subc[adj[id][i]]){
				cc=0;
			}
		}
	}
	if(cc!=0) subk[id]=true,subc[id]=cc;
}
void dfs2(int id){
	bool ok=true;
	int cnt2=(c[id]==c[1]);
	for(int i=0; i<ch[id].size() ;i++){
		if(!subk[ch[id][i]]) ok=false;
		if(c[ch[id][i]]==c[1]) cnt2+=s[ch[id][i]];
	}
	if(ok && rcnt-cnt2==n-s[id]){
		cout << "YES\n";
		cout << id << '\n';
		exit(0);
	}
	for(int i=0; i<ch[id].size() ;i++){
		dfs2(ch[id][i]);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=1; i<n ;i++){
		cin >> p >> q;
		adj[p].push_back(q);
		adj[q].push_back(p);
	}
	for(int i=1; i<=n ;i++){
		cin >> c[i];
		if(c[i]==c[1]) rcnt++;
	}
	dfs1(1);
	dfs2(1);
	cout << "NO\n";
}