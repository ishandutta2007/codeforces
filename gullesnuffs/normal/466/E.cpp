#include <bits/stdc++.h>

using namespace std;

int par[100005][20];
int packet[100005];

int getHeight(int node){
	int i;
	for(i=0; par[node][i] != -1; ++i){
		par[node][i+1]=par[par[node][i]][i];
	}
	if(i == 0)
		return 0;
	int ans=(1<<(i-1))+getHeight(par[node][i-1]);
	for(i=0; par[node][i] != -1; ++i){
		par[node][i+1]=par[par[node][i]][i];
	}
	return ans;
}

int getParent(int node, int h){
	if(h == 0)
		return node;
	int i;
	for(i=0; par[node][i] != -1 && (1<<i) <= h; ++i){
	}
	return getParent(par[node][i-1], h-(1<<(i-1)));
	for(i=0; par[node][i] != -1; ++i){
		par[node][i+1]=par[par[node][i]][i];
	}
	
}

vector<int> children[100005];
int ans[100005];

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i=0; i < n; ++i)
		for(int j=0; j < 20; ++j)
			par[i][j]=-1;
	int packetN=0;
	vector<pair<int, pair<int, int> > > q;
	for(int i=0; i < m; ++i){
		int t;
		scanf("%d", &t);
		if(t == 1){
			int x, y;
			scanf("%d%d", &x, &y);
			--x;--y;
			//par[x][0]=y;
			q.push_back(make_pair(1, make_pair(x, y)));
		}
		else if(t == 2){
			int x;
			scanf("%d", &x);
			--x;
			q.push_back(make_pair(2, make_pair(packetN+1, x)));
			packet[++packetN]=x;
		}
		else{
			int x, p;
			scanf("%d%d", &x, &p);
			--x;
			int y=packet[p];
			q.push_back(make_pair(3, make_pair(x, y)));
			children[p].push_back(i);
			/*int xh=getHeight(x), yh=getHeight(y);
			if(yh >= xh && getParent(y, yh-xh) == x)
				puts("YES");
			else
				puts("NO");*/
		}
	}
	for(int i=0; i < q.size(); ++i){
		if(q[i].first == 1){
			par[q[i].second.first][0]=q[i].second.second;

		}
		else if(q[i].first == 2){
			int p=q[i].second.first;
			for(int j=0; j < children[p].size(); ++j){
				int x=q[children[p][j]].second.first, y=q[children[p][j]].second.second;
			int xh=getHeight(x), yh=getHeight(y);
			if(yh >= xh && getParent(y, yh-xh) == x)
				ans[children[p][j]]=1;
			else
				ans[children[p][j]]=0;
			}
		}
		else{
			if(ans[i])
				puts("YES");
			else
				puts("NO");
		}
	}
}