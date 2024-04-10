#include <bits/stdc++.h>

using namespace std;

vector<int> v[3];

int main(){
	int n;
	scanf("%d", &n);
	for(int i=0; i < n; ++i){
		int t;
		scanf("%d", &t);
		--t;
		v[t].push_back(i+1);
	}
	int m=min(min(v[0].size(), v[1].size()), v[2].size());
	printf("%d\n", m);
	for(int i=0; i < m; ++i)
		printf("%d %d %d\n", v[0][i], v[1][i], v[2][i]);
}