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

int nH[100005];
int x[100005], y[100005];

int main(){
	int n;
	scanf("%d", &n);
	for(int i=0; i < n; ++i){
		scanf("%d%d", x+i, y+i);
		++nH[x[i]];
	}
	for(int i=0; i < n; ++i){
		printf("%d %d\n", n-1+nH[y[i]], n-1-nH[y[i]]);
	}
	return 0;
}