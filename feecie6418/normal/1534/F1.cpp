
#include<bits/stdc++.h>
#define mp make_pair
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
int n,m,ans=0,d[400005],sign,dfn[400005],low[400005],ins[400005],st[400005],top,SCC,bel[400005];
string str[400005];
vector<int> g[400005];
int pos(int x,int y){
	if(str[x][y]!='#')return 0;
	return (x-1)*m+y+1;
}
void Add(int x,int y){
	if(!x||!y)return ;
	//cout<<x<<' '<<y<<endl;
	g[x].push_back(y);
}
void Tarjan(int x) {
	dfn[x]=low[x]=++sign,st[++top]=x,ins[x]=1;
	for(int y:g[x]){
		if(!dfn[y])Tarjan(y),low[x]=min(low[x],low[y]);
		else if(ins[y])low[x]=min(low[x],dfn[y]);
	}
	if(low[x]==dfn[x]) {
		int tmp;
		SCC++;
		do {
			tmp=st[top--],bel[tmp]=SCC,ins[tmp]=0;
		} while(tmp!=x);
	}
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>str[i];
	for(int i=0;i<m;i++){
		//cout<<i<<endl;
		for(int j=1;j<=n;j++){
			if(str[j][i]!='#')continue;
			int nxt=j+1;
			while(nxt<=n&&str[nxt][i]!='#')nxt++;
			if(j>1)Add(pos(j,i),pos(j-1,i));
			for(int k=j;k<nxt;k++){
				if(i-1>=0)Add(pos(j,i),pos(k,i-1));
				if(i+1<m)Add(pos(j,i),pos(k,i+1));
				if(k+1<=n)Add(pos(j,i),pos(k+1,i));
			}
		}
	}
	for(int i=1;i<=n;i++)for(int j=0;j<m;j++)if(str[i][j]=='#'&&!dfn[pos(i,j)])Tarjan(pos(i,j));
	for(int i=1;i<=n*m;i++)for(int j:g[i])if(bel[i]^bel[j])d[bel[j]]++;
	for(int i=1;i<=SCC;i++)if(!d[i])ans++;
	cout<<ans;
}