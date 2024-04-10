#include<iostream>
#include<vector>
using namespace std;
int pre[100001],pos[100001];
vector<int>c[100001];
int type,u,v;
int n,q;
int t[100001],anc[100001],anc2[100001];
int cnt1,cnt2;
void dfs(int id){
	cnt1++;
	pre[id]=cnt1;
	for(int i=0; i<c[id].size() ;i++) dfs(c[id][i]);
	cnt2++;
	pos[id]=cnt2;
}
bool isanc(int u,int v){
	return (pre[u]<pre[v] && pos[u]>pos[v]);
}
bool ieanc(int u,int v){
	return (pre[u]<=pre[v] && pos[u]>=pos[v]);
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	anc[1]=anc2[1]=1;
	for(int i=1; i<=n ;i++){
		cin >> u >> v;
		if(i==1) continue;
		c[u].push_back(i);
		t[i]=v;
		if(v!=1) anc[i]=i;
		else anc[i]=anc[u];
		if(v!=0) anc2[i]=i;
		else anc2[i]=anc2[u];
	}
	for(int i=1; i<=n ;i++){
		if(pre[i]==0) dfs(i);
	}
	cin >> q;
	for(int i=1; i<=q ;i++){
		cin >> type >> u >> v;
		if(type==2){
			if(anc[v]!=v && v!=u && ieanc(anc[v],anc2[u]) && isanc(anc2[u],v)) cout << "YES\n";
			else if(anc[v]!=v && v!=u && ieanc(anc2[u],anc[v]) && ieanc(anc[v],u)) cout << "YES\n";
			else cout << "NO\n";
		}
		else{
			if(ieanc(anc2[v],u) && isanc(u,v)) cout << "YES\n";
			else cout << "NO\n";
		}
		
	}
}