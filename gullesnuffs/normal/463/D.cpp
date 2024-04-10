#include <bits/stdc++.h>

using namespace std;

int pos[5][1005];
vector<int> adj[1005];
int inDeg[1005];
int score[1005];

int main(){
	int n, k;
	scanf("%d%d", &n, &k);
	for(int i=0; i < k; ++i){
		for(int j=0; j < n; ++j){
			int a;
			scanf("%d", &a);
			--a;
			pos[i][a]=j;
		}
	}
	for(int i=0; i < n; ++i)
		for(int j=0; j < n; ++j){
			bool ok=1;
			for(int l=0; l < k; ++l)
				if(pos[l][i] >= pos[l][j])
					ok=0;
			if(ok){
				adj[i].push_back(j);
				++inDeg[j];
			}
			score[i]=1;
		}
	queue<int> q;
	for(int i=0; i < n; ++i)
		if(!inDeg[i])
			q.push(i);
	while(!q.empty()){
		int cur=q.front();
		q.pop();
		for(int i=0; i < adj[cur].size(); ++i){
			int j=adj[cur][i];
			--inDeg[j];
			if(!inDeg[j])
				q.push(j);
			score[j]=max(score[j], score[cur]+1);
		}
	}
	int ans=0;
	for(int i=0; i < n; ++i)
		ans=max(ans, score[i]);
	printf("%d\n", ans);
}