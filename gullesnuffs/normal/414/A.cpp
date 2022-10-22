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

int main(){
	int n, k;
	scanf("%d%d", &n, &k);
	int first=k-(n/2)+1;
	if(first < 1){
		printf("-1\n");
		return 0;
	}
	if(n >= 2)printf("%d %d ", first, first*2);
	else{
	       if(k == 0)
	       	       printf("1");
	       else
		       printf("-1");
	}
	for(int i=2; i < n; ++i){
		printf("%d ", first*2+i);
	}
	printf("\n");
	return 0;
}