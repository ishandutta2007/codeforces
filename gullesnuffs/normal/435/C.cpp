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

int a[1005];
char field[4005][4005];

int main(){
	int n;
	scanf("%d", &n);
	for(int i=0; i < n; ++i)
		scanf("%d", a+i);
	for(int i=0; i < 4005; ++i)
		for(int j=0; j < 4005; ++j)
			field[i][j]=' ';
	int y=2000;
	int minY=2000, maxY=2000;
	int x=0;
	for(int i=0; i < n; ++i){
		char c=(i%2 == 0)?'/':'\\';
		for(int j=0; j < a[i]; ++j){
			field[y][x] = c;
			minY=min(minY, y);
			maxY=max(maxY, y);
			++x;
			if(j < a[i]-1){
				if(i%2)
					++y;
				else
					--y;
			}
		}
	}
	for(int i=0; i < 4005; ++i)
		field[i][x]=0;
	for(int i=minY; i <= maxY; ++i){
		printf("%s\n", field[i]);
	}
	return 0;
}