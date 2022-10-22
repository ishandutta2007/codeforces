#include <cstdio>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>

using namespace std;

vector<int> v[1000005]; 
vector<pair<int, int> > e;

int main(){
	long long k, n;
	scanf("%I64d%I64d", &n, &k);
	for(int i=0; i < n; ++i){
		int d;
		scanf("%d", &d);
		v[d].push_back(i);
	}
	if(v[0].size() != 1){
		printf("-1\n");
		return 0;
	}
	for(int i=1; i < n; ++i){
		if(v[i].size() > v[i-1].size()*k){
			printf("-1\n");
			return 0;
		}
		for(int j=0; j < v[i].size(); ++j)
			e.push_back(make_pair(v[i][j], v[i-1][j/k]));
		if(i == 1)
			--k;
	}
	printf("%d\n", e.size());
	for(int i=0; i < e.size(); ++i)
		printf("%d %d\n", e[i].first+1, e[i].second+1);
	return 0;
}