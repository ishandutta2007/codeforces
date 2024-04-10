#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
set<int> g[100005];
int n,K,f[100005],d[100005],cnt[100005],inq[100005];
int main(){
	scanf("%d%d",&n,&K);
	if(n==1)return puts("No"),0;
	for(int i=1,x,y;i<n;i++)scanf("%d%d",&x,&y),g[x].insert(y),g[y].insert(x);
	queue<int> q;
	for(int i=1;i<=n;i++)if(g[i].size()==1)q.push(i),inq[i]=1;
	while(!q.empty()){
		int x=q.front();
		q.pop();
		if(!g[x].size()){
			if(f[x]==K)puts("Yes");
			else puts("No");
			return 0;
		}
		for(int y:g[x]){
			if(!f[y])f[y]=f[x]+1;
			else if(f[y]!=f[x]+1)return puts("No"),0;
			cnt[y]++,g[y].erase(x);
			if((g[y].size()==1&&!inq[*g[y].begin()])||g[y].size()==0){
				if(cnt[y]<3)return puts("No"),0;
				q.push(y),inq[y]=1;
			}
		}
	}
	assert(0);
}