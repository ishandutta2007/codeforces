#include<bits/stdc++.h>
using namespace std;
vector<int> spread[200001];
vector<int> u;
vector<int> v;
int n,m,color[200001];
int ansflag=1;
void dfs(int now,int c){
	if(!ansflag) return;
	if(color[now]!=c&&color[now]!=-1){
		ansflag=0;
		return;
	}
	if(color[now]!=-1) return;
	color[now]=c;
	vector<int>::iterator ite=spread[now].begin();
	for(ite;ite!=spread[now].end();ite++){
		dfs(*ite,c^1);
	}
}
int main(){
	memset(color,-1,sizeof(color));
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++){
		int U,V;
		U--;
		V--;
		scanf("%d %d",&U,&V);
		spread[U].push_back(V);
		spread[V].push_back(U);
		u.push_back(U);
		v.push_back(V);
	}
	dfs(1,0);// 
	if(!ansflag){
		printf("No\n");
		return 0;
	}
	printf("Yes\n");
	for(int i=0;i<m;i++){
		if(color[u[i]]){
			printf("0");
		}
		else{
			printf("1");
		}
	}
	return 0;
}