#include <cstdio>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <stack>
#include <iostream>
using namespace std;

int chosen[300005];
map<pair<int, int>, int> Map;

int main(){
	int n, p;
	scanf("%d%d", &n, &p);
	for(int i=0; i < n; ++i){
		int x, y;
		scanf("%d%d", &x, &y);
		--x;
		--y;
		chosen[x]++;
		chosen[y]++;
		if(x > y)
			swap(x, y);
		Map[make_pair(x, y)]++;
	}
	long long ans=0;
	for(auto it = Map.begin(); it != Map.end(); ++it){
		if(chosen[it->first.first]+chosen[it->first.second] >= p &&
				chosen[it->first.first]+chosen[it->first.second]-it->second < p)
			--ans;
	}
	sort(chosen, chosen+n);
	int j=n-1;
	for(int i=0; i < n-1; ++i){
		if(j <= i)
			++j;
		while(j > i && chosen[i]+chosen[j] >= p)
			--j;
		ans += n-j-1;
	}
	printf("%I64d\n", ans);
	return 0;
}