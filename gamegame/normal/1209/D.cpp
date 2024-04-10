#include<bits/stdc++.h>
using namespace std;
int n,m;
int p[200001];
int find(int x){
	if(p[x]!=x) p[x]=find(p[x]);
	return p[x];
}
int cc;
void join(int x,int y){
	x=find(x);y=find(y);
	if(x!=y) cc--;
	p[x]=y;
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m;
	cc=n;
	for(int i=1; i<=n ;i++) p[i]=i;
	for(int i=1; i<=m ;i++){
		int u,v;cin >> u >> v;
		join(u,v);
	}
	cout << m-(n-cc) << endl;
}