#include<iostream>
using namespace std;
string s;
int n;
char t[1000001];
int lc[1000001],rc[1000001];
int v[1000001];
int res[1000001][2];
void dfs(int id){
	if(id==0) return;
	if(t[id]=='I') return;
	dfs(lc[id]);dfs(rc[id]);
	if(t[id]=='N') v[id]=1^v[lc[id]];
	else if(t[id]=='A') v[id]=v[lc[id]]&v[rc[id]];
	else if(t[id]=='O') v[id]=v[lc[id]]|v[rc[id]];
	else if(t[id]=='X') v[id]=v[lc[id]]^v[rc[id]];
}
void solve(int id){
	if(id==0 || t[id]=='I') return;
	if(t[id]=='N'){
		res[lc[id]][0]=res[id][1];
		res[lc[id]][1]=res[id][0];
	}
	else if(t[id]=='A'){
		res[lc[id]][0]=res[id][0&v[rc[id]]];
		res[lc[id]][1]=res[id][1&v[rc[id]]];
		res[rc[id]][0]=res[id][0&v[lc[id]]];
		res[rc[id]][1]=res[id][1&v[lc[id]]];
	}
	else if(t[id]=='O'){
		res[lc[id]][0]=res[id][0|v[rc[id]]];
		res[lc[id]][1]=res[id][1|v[rc[id]]];
		res[rc[id]][0]=res[id][0|v[lc[id]]];
		res[rc[id]][1]=res[id][1|v[lc[id]]];
	}
	else if(t[id]=='X'){
		res[lc[id]][0]=res[id][0^v[rc[id]]];
		res[lc[id]][1]=res[id][1^v[rc[id]]];
		res[rc[id]][0]=res[id][0^v[lc[id]]];
		res[rc[id]][1]=res[id][1^v[lc[id]]];
	}
	solve(lc[id]);
	solve(rc[id]);
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=1; i<=n ;i++){
		cin >> s;
		t[i]=s[0];
		if(t[i]=='A' || t[i]=='O' || t[i]=='X') cin >> lc[i] >> rc[i];
		else if(t[i]=='N') cin >> lc[i];
		else cin >> v[i];
	}
	dfs(1);
	res[1][0]=0,res[1][1]=1;
	solve(1);
	for(int i=1; i<=n ;i++){
		if(t[i]=='I') cout << res[i][v[i]^1];
	}
}