#include <bits/stdc++.h>

using namespace std;

pair<int, int> p[4][2];
map<int, int> x, y;
map<pair<int, int>, int> M;
map<pair<pair<int, int>, pair<int, int> > , int> M2;

int main(){
	bool ok=1;
	for(int i=0; i < 4; ++i){
		for(int j=0; j < 2; ++j){
			scanf("%d%d", &p[i][j].first, &p[i][j].second);
			x[p[i][j].first]++;
			y[p[i][j].second]++;
			M[p[i][j]]++;
		}
		if((p[i][0].first == p[i][1].first) == (p[i][0].second == p[i][1].second))
			ok=0;
		M2[make_pair(p[i][0],p[i][1])]++;
		M2[make_pair(p[i][1],p[i][0])]++;
	}
	for(auto it=x.begin(); it != x.end(); ++it)
		if(it->second != 4)
			ok=0;
	for(auto it=y.begin(); it != y.end(); ++it)
		if(it->second != 4)
			ok=0;
	for(auto it=M.begin(); it != M.end(); ++it)
		if(it->second != 2)
			ok=0;
	for(auto it=M2.begin(); it != M2.end(); ++it)
		if(it->second != 1)
			ok=0;
	puts(ok?"YES":"NO");
}