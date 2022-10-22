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

int x[505];
int c[505][505];

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i=0; i < n; ++i){
		scanf("%d", x+i);
		for(int j=0; j < n; ++j){
			c[i][j]=0;
		}
	}
	if(!m){
		printf("0\n");
		return 0;
	}
	for(int i=0; i < m; ++i){
		int a,b;
		scanf("%d%d", &a, &b);
		--a;
		--b;
		scanf("%d", &c[a][b]);
		c[b][a]=c[a][b];
	}
	double ans=0;
	for(int i=0; i < n; ++i)
		for(int j=0; j < n; ++j){
			if(!c[i][j])
				continue;
			ans=max(ans, (x[i]+x[j]+0.0)/(c[i][j]+0.0));
		}
	printf("%.10lf\n", ans);
	return 0;
}