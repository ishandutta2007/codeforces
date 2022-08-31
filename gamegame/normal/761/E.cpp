#include<iostream>
#include<queue>
using namespace std;
int n;
int ansx[31],ansy[31];
int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int pard[31];
bool vis[31];
vector<int>edge[31];
void dfs(int id,int deg){
	vis[id]=true;
	if(edge[id].size()>4){
		cout << "NO" << endl;
		exit(0);
	}
	int cur=-1;
	for(int i=0; i<edge[id].size() ;i++){
		if(vis[edge[id][i]]) continue;
		cur++;
		if(cur==(pard[id]+2)%4) cur++;
		int newi=edge[id][i];
		pard[newi]=cur;
		ansx[newi]=ansx[id]+(1<<deg)*dir[pard[newi]][0];
		ansy[newi]=ansy[id]+(1<<deg)*dir[pard[newi]][1];
		dfs(newi,deg-1);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	int p,q;
	pard[1]=-3;
	for(int i=1; i<n ;i++){
		cin >> p >> q;
		edge[p].push_back(q);
		edge[q].push_back(p);
	}
	dfs(1,n-1);
	cout << "YES\n";
	for(int i=1; i<=n ;i++){
		cout << ansx[i] << ' ' << ansy[i] << '\n';
	}
}