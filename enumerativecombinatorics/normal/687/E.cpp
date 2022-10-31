#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<string.h>
#include<vector>
#include<set>
#include<map>
#include<stdlib.h>
using namespace std;
const long long mod=1000000007;
const long long inf=mod*mod;

vector<int>g[5100];
vector<int>rev[5100];
int v[5100];
int num[5100];
int conv[5100];
int scc[5100];
int fi[5100];
int ss[5100];
int cur;
void dfs(int a){
	for(int i=0;i<g[a].size();i++){
		if(v[g[a][i]])continue;
		v[g[a][i]]=1;
		dfs(g[a][i]);
	}
	conv[a]=cur;
	num[cur++]=a;
}
void dfs2(int a){
	scc[a]=cur;
	ss[cur]++;
	for(int i=0;i<rev[a].size();i++){
		if(v[rev[a][i]])continue;
		v[rev[a][i]]=1;
		dfs2(rev[a][i]);
	}
}
int len[5100];
int dp[2][5100];
int st;
void dfs3(int a,int b){
	v[a]=1;
	for(int i=0;i<g[a].size();i++){
		if(g[a][i]==st){
			if(len[st]==-1)len[st]=b+1;
			else if(len[st]>b+1)len[st]=b+1;
		}
		if(v[g[a][i]])continue;
		dfs3(g[a][i],b+1);
	}
}
vector<int>G[5100];
int g2[5100][5100];
int used[5100];
pair<pair<int,int>,int> q[5100];
int main(){
	int a,b;scanf("%d%d",&a,&b);
	for(int i=0;i<b;i++){
		int p,q;scanf("%d%d",&p,&q);p--;q--;
		g[p].push_back(q);
		rev[q].push_back(p);
	}
	for(int i=0;i<a;i++){
		if(v[i])continue;
		v[i]=1;
		dfs(i);
	}
	cur=0;
	for(int i=0;i<a;i++)v[i]=0;
	for(int i=a-1;i>=0;i--){
		if(v[num[i]])continue;
		v[num[i]]=1;
		fi[cur]=num[i];
		dfs2(num[i]);
		cur++;
	}
	for(int i=0;i<a;i++){
		len[i]=-1;
		st=i;
		for(int j=0;j<a;j++)v[j]=0;

		dfs3(i,0);
	//printf("%d: %d\n",i,len[i]);
		q[i]=make_pair(make_pair(len[i],conv[i]),i);
	}
	std::sort(q,q+a);
	for(int i=0;i<a;i++){
		for(int j=0;j<rev[i].size();j++){
			if(scc[i]!=scc[rev[i][j]]){
				g2[scc[i]][scc[rev[i][j]]]=1;
			}
		}
	}
	for(int i=0;i<cur;i++){
		for(int j=0;j<cur;j++){
			if(g2[i][j])G[i].push_back(j);
		}
	}
	int ret=0;
	for(int i=0;i<a;i++){
		int at=q[i].second;
		int cost=q[i].first.first;
		if(used[scc[at]])continue;
		if(cost!=-1){
			ret+=998*cost+1;
		}
		used[scc[at]]=1;
		queue<int>Q;
		Q.push(scc[at]);
		while(Q.size()){
			int now=Q.front();Q.pop();
			ret+=ss[now];
			for(int j=0;j<G[now].size();j++){
				if(used[G[now][j]])continue;
				used[G[now][j]]=1;
				Q.push(G[now][j]);
			}
		}
	}
	printf("%d\n",ret);
}