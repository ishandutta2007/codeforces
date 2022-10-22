#include <bits/stdc++.h>
#define OFFSET (1<<17)
using namespace std;

int n;
vector<int> adj[100005];
map<pair<int,int>, int> dis;
priority_queue<pair<int, int> > pq;
int sz[100005];
int szOut[100005];
bool vis[100005];
int deg[100005];
int parent[100005];
set<int> S[100005];
int tree[500005];
int top[100005];
long long dToRoot[100005];
int root;
int secondLast;
int ans[100005];
priority_queue<pair<int, int> > szPq;

void dfs(int node, set<int>* s, int ind, long long d){
	s->insert(node);
	top[node]=ind;
	dToRoot[node]=d;
	for(int i=0; i < adj[node].size(); ++i){
		int to=adj[node][i];
		if(to == parent[node])
			continue;
		dfs(to, s, ind, d+dis[make_pair(node, adj[node][i])]);
	}
}

void select(int node){
	if(node == root){
		//--sz[root];
	}
	else{
		/*if(top[node] == secondLast)
			--sz[secondLast];
		else
			--sz[root];*/
		node=top[node];
		S[node].erase(S[node].begin());
		if(!S[node].empty())
			tree[OFFSET+node]=*S[node].begin();
		else
			tree[OFFSET+node]=999999;
		for(int i=(OFFSET+node)/2; i >= 1; i/=2){
			tree[i]=min(tree[2*i], tree[2*i+1]);
		}
	}
}

int only(int node){
	return tree[OFFSET+node];
}

int exclude(int node){
	if(node == -1)
		return tree[1];
	int a=999999;
	for(int i=OFFSET+node; i >= 2; i/=2){
		a=min(a, tree[i^1]);
	}
	return a;
}

int main(){
	scanf("%d", &n);
	if(n == 1){
		printf("0\n1\n");
		return 0;
	}
	for(int i=0; i < n-1; ++i){
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		--u;
		--v;
		adj[u].push_back(v);
		adj[v].push_back(u);
		dis[make_pair(u,v)]=w;
		dis[make_pair(v,u)]=w;
	}
	for(int i=0; i < n; ++i){
		sz[i]=1;
		if(adj[i].size() == 1)
			pq.push(make_pair(-1, i));
		deg[i]=adj[i].size();
	}
	while(!pq.empty()){
		int cur=pq.top().second;
		pq.pop();
		vis[cur]=1;
		if(deg[cur] == 0){
			root=cur;
			continue;
		}
		for(int i=0; i < adj[cur].size(); ++i){
			int to=adj[cur][i];
			if(vis[to])
				continue;
			parent[cur]=to;
			sz[to] += sz[cur];
			--deg[to];
			if(deg[to] == 1)
				pq.push(make_pair(-sz[to], to));
			if(deg[to] == 0){
				secondLast=cur;
				sz[to] -= sz[cur];
			}
		}
	}
	for(int i=0; i < OFFSET*2; ++i)
		tree[i]=999999;
	for(int i=0; i < adj[root].size(); ++i){
		dfs(adj[root][i], S+adj[root][i], adj[root][i], dis[make_pair(root, adj[root][i])]);
		tree[OFFSET+adj[root][i]]=*(S[adj[root][i]].begin());
		szPq.push(make_pair(2*sz[adj[root][i]], adj[root][i]));
	}
	for(int i=OFFSET-1; i >= 1; --i)
		tree[i]=min(tree[2*i], tree[2*i+1]);
	for(int i=0; i < n; ++i)
		szOut[i]=sz[i];
	long long disTot=0;
	bool rootUsed=0;
	top[root]=-1;
	for(int i=0; i < n; ++i){
		//int t=top[i];
		int tInd=top[i];
		int j;
		secondLast=szPq.top().second;
		if(i == root){
			if(n-i-szOut[secondLast] > sz[secondLast]){
				j=exclude(-1);
				if(root < j && !rootUsed)
					j=root;
			}
			else
				j=only(secondLast);
		}
		else if(tInd == secondLast){
			j=exclude(secondLast);
			if(root < j && !rootUsed)
				j=root;
		}
		else{
			if(n-i-szOut[secondLast] > sz[secondLast]){
				j=exclude(tInd);
				if(root < j && !rootUsed){
					j=root;
				}
			}
			else
				j=only(secondLast);
		}
		if(j != root){
			sz[top[j]]--;
		}
		if(i != root)
			szOut[top[i]]--;
		while(szPq.top().first > sz[szPq.top().second]+szOut[szPq.top().second]){
			int t=szPq.top().second;
			szPq.pop();
			szPq.push(make_pair(sz[t]+szOut[t], t));
		}
		if(j >= n){
			printf("i=%d\nroot=%d\nsecondLast=%d\nsz=%d\nszOut=%d\nrootUsed=%d\nj=%d\nsz[tInd]=%d\nszOut[tInd]=%d\n", i, root, secondLast, sz[secondLast], szOut[secondLast], rootUsed, j, sz[tInd], szOut[tInd]);
			return 0;
		}
		/*if(tInd != secondLast && top[j] != secondLast)
			--sz[root];*/
		/*if(i != root){
			if(tInd == secondLast)
				--sz[secondLast];
			else
				--sz[root];
		}*/
		disTot += dToRoot[i];
		disTot += dToRoot[j];
		select(j);
		ans[i]=j;
		if(j == root)
			rootUsed=1;
	}
	printf("%I64d\n", disTot);
	for(int i=0; i < n; ++i)
		printf("%d ", ans[i]+1);
}