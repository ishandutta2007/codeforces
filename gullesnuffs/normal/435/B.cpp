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

char inp[25];

int main(){
	scanf("%s", inp);
	int k;
	scanf("%d", &k);
	for(int i=0; inp[i]; ++i){
		int best=0;
		int bestI;
		for(int j=i; inp[j] && j-i <= k; ++j){
			if(inp[j] > best){
				best=inp[j];
				bestI=j;
			}
		}
		for(int j=bestI; j > i; --j)
			inp[j]=inp[j-1];
		inp[i]=best;
		k -= bestI-i;
	}
	printf("%s\n", inp);
	return 0;
}