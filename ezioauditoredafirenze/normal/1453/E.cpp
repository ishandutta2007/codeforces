#include<bits/stdc++.h>
using namespace std;
#define N 200002
vector<int> graph[N];
int depth[N],b[N];

int dfs(int node,int par){
	int result=0;
	depth[node]=depth[par]+1;
	b[node]=depth[node];
	priority_queue<int> q;
	for(int to:graph[node]){
		if(to==par) continue;
		result=max(result,dfs(to,node));
		if(node==1) q.push(-b[to]);
		else q.push(b[to]);
	}
	while(!q.empty()){
		b[node]=abs(q.top());
		q.pop();
		int extra=0;
		if(q.empty()) extra=0;
		else extra=1;
        result=max(result,b[node]-depth[node]+extra);
	}
	return result;
}

int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,i,x,y;
		cin>>n;
		for(i=1;i<=n;i++)
			graph[i].clear(),depth[i]=b[i]=0;
		for(i=0;i+1<n;i++){
			cin>>x>>y;
			graph[x].push_back(y);
			graph[y].push_back(x);
		}
		cout<<dfs(1,0)<<endl;
	}
	return 0;
}