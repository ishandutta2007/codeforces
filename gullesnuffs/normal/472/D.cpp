#include <bits/stdc++.h>

using namespace std;

int n;
int d[2005][2005];
vector<pair<int, pair<int, int> > > D;
long long dis[2005][2005];

int main(){
	scanf("%d", &n);
	for(int i=0; i < n; ++i)
		for(int j=0; j < n; ++j){
			scanf("%d", d[i]+j);
			D.push_back(make_pair(d[i][j], make_pair(i, j)));
		}
	sort(D.begin(), D.end());
	bool ok=1;
	for(int i=0; i < n; ++i)
		for(int j=0; j < n; ++j){
			dis[i][j]=-1;
			if(d[i][j] != d[j][i])
				ok=0;
			if(i == j && d[i][j] != 0)
				ok=0;
			if(i != j && d[i][j] == 0)
				ok=0;
			dis[i][i]=0;
		}
	if(!ok){
		puts("NO");
		return 0;
	}
	for(int i=0; i < D.size(); ++i){
		int a=D[i].second.first, b=D[i].second.second;
		if(dis[a][b] != -1)
			continue;
		vector<int> va, vb;
		for(int j=0; j < n; ++j){
			if(dis[j][a] != -1)
				va.push_back(j);
			if(dis[j][b] != -1)
				vb.push_back(j);
		}
		dis[a][b]=d[a][b];
		dis[b][a]=d[a][b];
		for(int j=0; j < va.size(); ++j)
			for(int k=0; k < vb.size(); ++k){
				int na=va[j],nb=vb[k];
				dis[na][nb]=dis[na][a]+d[a][b]+dis[b][nb];
				dis[nb][na]=dis[na][nb];
			}
	}
	for(int i=0; i < n; ++i)
		for(int j=0; j < n; ++j)
			if(dis[i][j] != d[i][j])
				ok=0;
	puts(ok?"YES":"NO");
}