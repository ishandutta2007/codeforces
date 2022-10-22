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

int adj[1005][1005];
int Max=33;

int main(){
	int k;
	scanf("%d", &k);
	int pos = 2;
	for(long long i=1; i < (1LL<<Max); i*=2){
			adj[pos][pos+2]=1;
			adj[pos][pos+3]=1;
			adj[pos+1][pos+2]=1;
			adj[pos+1][pos+3]=1;
			pos += 2;
	}
	adj[1][pos]=1;
	adj[1][pos+1]=1;
	pos += 2;
	for(long long i=1; i <= k; i*=2){
		if(!(k&i))
			continue;
		adj[0][pos]=1;
		long long j;
		int m=2;
		for(j=i; j < (1LL<<Max); j*=2){
			adj[pos][pos+1]=1;
			pos += 1;
			m += 2;
		}
		adj[m][pos]=1;
		++pos;
	}
	printf("%d\n", pos);
	for(int i=0; i < pos; ++i){
		for(int j=0; j < pos; ++j)
			printf("%c", (adj[i][j]||adj[j][i])?'Y':'N');
		printf("\n");
	}
	return 0;
}