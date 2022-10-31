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
vector<pair<int,int> > g[1100];
long long ijk[2][1100];
int v[2][1100];
int main(){
	int a,b,c,d,e;
	scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
	for(int i=0;i<b;i++){
		int p,q,r;scanf("%d%d%d",&p,&q,&r);
		g[p].push_back(make_pair(q,r));
		g[q].push_back(make_pair(p,r));
	}
	for(int i=0;i<2;i++)for(int j=0;j<a;j++)ijk[i][j]=inf;
	priority_queue<pair<long long,int> > Q;
	Q.push(make_pair(0,d));
	ijk[0][d]=0;
	while(Q.size()){
		long long cost=-Q.top().first;
		int at=Q.top().second;Q.pop();
		if(v[0][at])continue;
		v[0][at]=1;
		for(int i=0;i<g[at].size();i++){
			int to=g[at][i].first;
			if(g[at][i].second==0)continue;
			long long toc=cost+g[at][i].second;
			if(v[0][to]||ijk[0][to]<=toc)continue;
			ijk[0][to]=toc;
			Q.push(make_pair(-toc,to));
		}
	}
	if(ijk[0][e]<c){
		printf("NO\n");return 0;
	}
	Q.push(make_pair(0,e));
	ijk[1][e]=0;
	map<pair<int,int>,long long>M;
	while(Q.size()){
		long long cost=-Q.top().first;
		int at=Q.top().second;Q.pop();
		if(v[1][at])continue;
		v[1][at]=1;
		for(int i=0;i<g[at].size();i++){
			int to=g[at][i].first;
			long long toc=cost+g[at][i].second;
			if(g[at][i].second==0){
				if(M.count(make_pair(min(at,to),max(at,to))))toc=cost+M[make_pair(min(at,to),max(at,to))];
				else{
					if(cost+1+ijk[0][to]>=c){
						toc=cost+1;
						M[make_pair(min(at,to),max(at,to))]=1;
					}else{
						toc=(c-ijk[0][to]);
						M[make_pair(min(at,to),max(at,to))]=c-cost-ijk[0][to];
					}
				}
			}
			if(v[1][to]||ijk[1][to]<=toc)continue;
			ijk[1][to]=toc;
			Q.push(make_pair(-toc,to));
		}
	}
	if(ijk[1][d]>c){
		printf("NO\n");return 0;
	}
	printf("YES\n");
	for(int i=0;i<a;i++)for(int j=0;j<g[i].size();j++){
		if(i>g[i][j].first)continue;
		if(g[i][j].second)printf("%d %d %d\n",i,g[i][j].first,g[i][j].second);
		else printf("%d %d %I64d\n",i,g[i][j].first,M[make_pair(i,g[i][j].first)]);
	}
}