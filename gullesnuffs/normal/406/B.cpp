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

int x[500005];
bool inx[10000005];

int main(){
	int n;
	scanf("%d", &n);
	for(int i=0; i < n; ++i){
		scanf("%d", x+i);
		inx[x[i]]=1;
	}	
	printf("%d\n", n);
	int m=0;
	for(int i=1; i <= 1000000; ++i){
		if(!inx[i] && inx[1000001-i]){
			printf("%d ", i);
			++m;
		}
	}
	for(int i=1; i <= 1000000; ++i){
		if(m >= n)
			break;
		if(!inx[i] && !inx[1000001-i]){
			printf("%d %d ", i, 1000001-i);
			m += 2;
		}
	}
	printf("\n");
	return 0;
}