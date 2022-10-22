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

char field[105][105];

/*void rec(int n, int m){
	int sz=min(n, m);
	char c;
	for(c='A'; true; ++c){
		if(c != forbtop && c != forbleft && c != forbright)
			break;
	}
	for(int i=0; i < sz; ++i)
		for(int j=0; j < sz; ++j)
			field[i+offn][j+offm]=c;
	if(n == m)
		return;
	if(n > m)
		rec(n-m, m, offn+sz, offm, c, forbleft);
	else{
		rec(n, m-n-1, offn, offm+sz+1, forbtop, c);
		rec(n, 1, offn, offm+sz, forbtop, c, c);
	}

}*/
int n, m;

void rec2(int y, int x){
	if(field[y][x])
		return;
	set<char> imp;
	char c='A';
	imp.insert(field[y-1][x]);
	imp.insert(field[y][x-1]);
	imp.insert(field[y+1][x]);
	imp.insert(field[y][x+1]);
	while(imp.find(c) != imp.end())
		++c;
	int i;
	for(i=2; true; ++i){
		bool ok=1;
		for(int j=0; j < i; ++j){
			if(field[y+i-1][x+j] || field[y+j][x+i-1]){
				ok=0;
				break;
			}
		}
		if(!ok)
			break;
		for(int j=0; j < i; ++j){
			imp.insert(field[y+i][x+j]);
			imp.insert(field[y+j][x+i]);
		}
		imp.insert(field[y+i-1][x-1]);
		imp.insert(field[y-1][x+i-1]);
		if(imp.find(c) != imp.end())
			break;
		bool stop=0;
		for(char c2='A'; c2 < c; ++c2){
			bool ok=1;
			if(field[y][x+i] == c2)
				ok=0;
			if(field[y-1][x+i-1] == c2)
				ok=0;
			if(field[y+1][x+i-1] == c2)
				ok=0;
			if(ok)
				stop=1;
		}
		if(stop)
			break;
	}
	for(int j=0; j < i-1; ++j)
		for(int k=0; k < i-1; ++k)
			field[y+j][x+k]=c;
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i=0; i < n+2; ++i)
		for(int j=0; j < m+2; ++j)
			field[i][j]=1;
	for(int i=1; i <= n; ++i)
		for(int j=1; j <= m; ++j)
			field[i][j]=0;
	for(int i=1; i <= n; ++i)
		for(int j=1; j <= m; ++j)
			rec2(i, j);
	for(int i=1; i <= n; ++i)
		field[i][m+1]=0;
	for(int i=1; i <= n; ++i)
		printf("%s\n", field[i]+1);
	return 0;
}