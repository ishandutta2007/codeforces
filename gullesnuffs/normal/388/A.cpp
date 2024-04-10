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

int x[105];
int n;
int main(){
	scanf("%d", &n);
	for(int i=0; i < n; ++i){
		scanf("%d", x+i);
	}
	sort(x, x+n);
	int ans=0;
	for(int i=0; i < n; ++i){
		ans=max(ans, (i+x[i]+1)/(x[i]+1));
	}
	printf("%d\n", ans);
	return 0;
}