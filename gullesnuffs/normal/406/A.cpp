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

int M[1005][1005];
int val[1005][2];

int main(){
	int n;
	scanf("%d", &n);
	int ans=0;
	for(int i=0; i < n; ++i)
		for(int j=0; j < n; ++j){
			scanf("%d", M[i]+j);
			if(i == j && M[i][i])
				ans^=1;
		}
	int q;
	scanf("%d", &q);
	for(int i=0; i < q; ++i){
		int t;
		scanf("%d", &t);
		if(t == 3)
			printf("%d", ans);
		else{
			ans^=1;
			scanf("%d", &t);
		}
	}
	printf("\n");
	return 0;
}