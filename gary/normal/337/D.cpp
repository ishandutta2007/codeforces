#include<bits/stdc++.h>
using namespace std;
int p[100001];
struct node{
	vector<int> son;
} a[100001];
int d[3][100001],flag[100001];
void dfs(int p,int t,int id,int de){
	d[id][t]=de;
	for(int j=0;j<a[t].son.size();j++){
		if(a[t].son[j]!=p){
			dfs(t,a[t].son[j],id,de+1);
		}
	}
}
int main(){
	int n,m,D;
	cin>>n>>m>>D;
	for(int i=1;i<=m;i++) scanf("%d",&p[i]),flag[p[i]]=true;;
	for(int i=1;i<n;i++){
		int A,B;
		scanf("%d %d",&A,&B);
		a[A].son.push_back(B);
		a[B].son.push_back(A);
	}int i;
	
	for(i=1;i<=n;i++){
		if(flag[i]) break;
	}
	dfs(-1,i,0,0);
	int y=i;
	for(i=1;i<=n;i++){
		if(d[0][i]>d[0][y]&&flag[i]) y=i;
	}
	dfs(-1,y,1,0);
	int x=y;
	for(i=1;i<=n;i++){
		if(d[1][i]>d[1][x]&&flag[i]) x=i;
	}
	dfs(-1,x,2,0);
	int ans=0;
	for(i=1;i<=n;i++){
		if(d[1][i]<=D&&d[2][i]<=D) ans++;
	}
	printf("%d\n",ans);
	return 0;
	
}