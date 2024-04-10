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

char field[1005][1005];
char test[1005][1005];
char f[1005][1005];
int n, m;
int dx[4]={1, 1, 1, 0}, dy[4]={-1, 0, 1, 1};
set<char> s[2];

bool check(){
	for(int i=1; i <= n; ++i){
		for(int j=1; j <= m; ++j)
			for(int k=0; k < 4; ++k){
				if(test[i][j] == test[i+dx[k]][j+dy[k]]
						|| test[i][j] == '0')
					return 0;
			}
	}
	return 1;
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i=1; i <= n; ++i){
		scanf("%s", field[i]+1);
	}
	bool ok=1;
	for(int i=0; i <= n; ++i)
		for(int j=0; j <= m; ++j)
			f[i][j]=0;
	s[0].clear();
	s[1].clear();
	for(int i=1; i <= n; ++i)
		for(int j=1; j <= m; ++j){
			if(field[i][j] == '0')
				continue;
			int I=i%2, J=j;
			if(f[I][J] != 0 && f[I][J] != field[i][j])ok=0;
			f[I][J]=field[i][j];
			s[j%2].insert(field[i][j]);
		}
	if(s[0].size() > 2 || s[1].size() > 2)ok=0;
	if(ok){for(int i=0; i < 2; ++i){
		while(s[i].size() < 2){
			for(char c='1'; c <= '4'; ++c){
				if(s[i].find(c) != s[i].end() || s[1-i].find(c) != s[1-i].end())
					continue;
				s[i].insert(c);
				break;
			}
		}
	}
	for(int i=0; i < 2; ++i)
		for(int j=1; j <= m; ++j){
			if(f[i][j] != '0' && f[i][j] != 0)
				continue;
			for(char k='1'; k <= '4'; ++k){
				if(s[j%2].find(k) == s[j%2].end() || k == f[1-i][j])
					continue;
				f[i][j]=k;
				break;
			}
		}
	for(int i=1; i <= n; ++i){
		for(int j=1; j <= m; ++j){
			int I=i%2, J=j;
			test[i][j]=f[I][J];
		}
		test[i][m+1]=0;
	}
	if(ok && check()){
		for(int i=1; i <= n; ++i)
			printf("%s\n", test[i]+1);
		return 0;
	}}
	ok=1;
	for(int i=0; i <= n; ++i)
		for(int j=0; j <= m; ++j)
			f[i][j]=0;
	s[0].clear();
	s[1].clear();
	for(int i=1; i <= n; ++i)
		for(int j=1; j <= m; ++j){
			if(field[i][j] == '0')
				continue;
			int I=i, J=j%2;
			if(f[I][J] != 0 && f[I][J] != field[i][j])ok=0;
			f[I][J]=field[i][j];
			s[i%2].insert(field[i][j]);
		}
	if(s[0].size() > 2 || s[1].size() > 2)ok=0;
	if(ok){for(int i=0; i < 2; ++i){
		while(s[i].size() < 2){
			for(char c='1'; c <= '4'; ++c){
				if(s[i].find(c) != s[i].end() || s[1-i].find(c) != s[1-i].end())
					continue;
				s[i].insert(c);
				break;
			}
		}
	}
	for(int i=1; i <= n; ++i)
		for(int j=0; j < 2; ++j){
			if(f[i][j] != '0' && f[i][j] != 0)
				continue;
			for(char k='1'; k <= '4'; ++k){
				if(s[i%2].find(k) == s[i%2].end() || k == f[i][1-j])
					continue;
				f[i][j]=k;
				break;
			}
		}
	for(int i=1; i <= n; ++i){
		for(int j=1; j <= m; ++j){
			int I=i, J=j%2;
			test[i][j]=f[I][J];
		}
		test[i][m+1]=0;
	}
	if(ok && check()){
		for(int i=1; i <= n; ++i)
			printf("%s\n", test[i]+1);
		return 0;
	}}
	printf("0\n");
	return 0;
}