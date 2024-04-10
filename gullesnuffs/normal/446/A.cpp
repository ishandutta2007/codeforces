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
#include <cassert>
using namespace std;

int a[100005];
int dp[100005][3];
map<pair<int, int>, int> M[2];

int main(){
	int n;
	scanf("%d", &n);
	for(int i=0; i < n; ++i)
		scanf("%d", a+i);
	int ans=1;
	bool read=0, write=1;
	M[write][make_pair(0, 0)]=0;
	for(int i=0; i < n; ++i){
		read^=1;
		write^=1;
		M[write].clear();
		for(auto it=M[read].begin(); it != M[read].end(); ++it){
			if(it->first.second > 1)
				continue;
			if(a[i] > it->first.first)
				M[write][make_pair(a[i], it->first.second)]=max(M[write][make_pair(a[i], it->first.second)], it->second+1);
				M[write][make_pair(it->first.first+1, it->first.second+1)]=max(it->second+1, M[write][make_pair(it->first.first+1, it->first.second+1)]);
		}
		M[write][make_pair(0, 1)]=max(M[write][make_pair(0, 1)], 1);
		M[write][make_pair(a[i], 0)]=max(M[write][make_pair(a[i], 0)], 1);
		for(auto it=M[write].begin(); it != M[write].end(); ++it){
			if(it->first.second > 1)
				continue;
			ans=max(ans, it->second);
		}
	}
	printf("%d\n", ans);
	return 0;
}