#include <bits/stdc++.h>

using namespace std;

int n, q;
vector<int> adj[100005];
int Slast[2000005];
int Sl[2000005];
int Sprev[2000005];
//stack<int> S[2000005];
vector<int> primes[2000005];
vector<int> A(2000005);
int ans[2000005];
int nodeAtDepth[2000005];
int spos;

void rec(int node, int parent, int depth){
	nodeAtDepth[depth]=node;
	ans[node] = -1;
	for(int i=0; i < primes[A[node]].size(); ++i){
		int ind=primes[A[node]][i];
		if(Slast[ind] != -1){//!S[ind].empty())
			//ans[node]=max(ans[node], S[ind].top());	
			ans[node]=max(ans[node], Sl[Slast[ind]]);
		}
		Sl[spos]=depth;
		Sprev[spos]=Slast[ind];
		Slast[ind]=spos;
		spos++;		
		//S[ind].push(depth);
	}
	if(ans[node] >= 0)
		ans[node]=nodeAtDepth[ans[node]]+1;
	else
		ans[node]=-1;
	for(int i=0; i < adj[node].size(); ++i){
		int j=adj[node][i];
		if(j == parent)
			continue;
		rec(j, node, depth+1);
		
	}
	for(int i=0; i < primes[A[node]].size(); ++i){
		int ind=primes[A[node]][i];
		//S[ind].pop();
		Slast[ind]=Sprev[Slast[ind]];
	}
}

void makeTree(){
	for(int i=0; i < 2000005; ++i){
		Slast[i]=-1;
	}
	spos=0;
	rec(0, -1, 0);
}

int main(){
	for(int i=2; i < 2000005; ++i){
		if(primes[i].empty()){
			for(int j=i; j < 2000005; j += i)
				primes[j].push_back(i);
		}
	}
	scanf("%d%d", &n, &q);
	for(int i=0; i < n; ++i){
		int a;
		scanf("%d", &a);
		A[i]=a;
	}
	for(int i=0; i < n-1; ++i){
		int u, v;
		scanf("%d%d", &u, &v);
		--u;
		--v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	makeTree();
	for(int i=0; i < q; ++i){
		int type;
		scanf("%d", &type);
		if(type == 1){
			int v;
			scanf("%d", &v);
			--v;
			printf("%d\n", ans[v]);
		}
		else{
			int v, w;
			scanf("%d%d", &v, &w);
			--v;
			A[v]=w;
			makeTree();
		}
	}
}