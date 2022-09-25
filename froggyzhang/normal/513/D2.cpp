#include<bits/stdc++.h>
using namespace std;
#define N 1000010
typedef long long ll;
int n,m,qwq,son[N][2],L[N][2],R[N][2];
#define NO cout<<"IMPOSSIBLE\n"
int now;
void dfs(int u,int lim){
	++now;
	if(L[u][1]){
		dfs(son[u][0]=u+1,L[u][1]);
	}
	if(R[u][1]&&now>=R[u][0]){
		NO;exit(0);	
	}
	if(lim>now||R[u][1]){
		dfs(son[u][1]=now+1,max(R[u][0]?R[u][1]:0,lim));	
	}
}
void get_ans(int u){
	if(!u)return;
	get_ans(son[u][0]);
	cout<<u<<' ';
	get_ans(son[u][1]);	
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		R[i][0]=L[i][0]=n+1;
	}
	for(int i=1;i<=m;++i){
		int a,b;
		string c;
		cin>>a>>b>>c;
		if(a>=b){
			NO;
			return 0;
		}
		if(c[0]=='L')L[a][0]=min(L[a][0],b),L[a][1]=max(L[a][1],b);
		else R[a][0]=min(R[a][0],b),R[a][1]=max(R[a][1],b);
	}
	dfs(1,n);
	get_ans(1);
	return 0;
}