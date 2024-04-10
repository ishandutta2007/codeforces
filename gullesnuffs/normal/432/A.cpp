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

int c[2005];

int main(){
	int n, k;
	scanf("%d%d", &n, &k);
	int m=0;
	for(int i=0; i < n; ++i){
		int C;
		scanf("%d", &C);
		C=5-C;
		if(C >= k)
			++m;
	}
	printf("%d\n", m/3);
	return 0;
}