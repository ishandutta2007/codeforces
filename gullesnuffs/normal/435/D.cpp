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

char field[405][405];
int num[405][405][4];

int dy[4]={1, 1, 1, 0}, dx[4]={-1, 0, 1, 1};

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i=0; i < 405; ++i)
		for(int j=0; j < 405; ++j){
			field[i][j]='1';
		}
	for(int i=1; i <= n; ++i){
		scanf("%s", field[i]+1);
	}
	for(int i=1; i <= n; ++i)
		for(int j=1; j <= m; ++j){
			for(int k=0; k < 4; ++k){
				num[i][j][k]=0;
				for(int l=0; field[i+dy[k]*l][j+dx[k]*l] == '0'; ++l){
					++num[i][j][k];

				};
			}
		}
	int ans=0;
	for(int i=1; i <= n; ++i)
		for(int j=1; j <= m; ++j)
		for(int l=1; true; ++l){
			bool p[4];
			int pN=0;
			for(int k=0; k < 4; ++k){
				if(num[i][j][k] > l){
					p[k]=1;
					++pN;
				}
				else
					p[k]=0;
			}
			if(pN < 2)
				break;
			if(p[0] && p[1] && num[i+l][j-l][3] > l)
				++ans;
			if(p[0] && p[2] && num[i+l][j-l][3] > 2*l)
				++ans;
			if(p[1] && p[2] && num[i+l][j][3] > l)
				++ans;
			if(p[1] && p[3] && num[i][j+l][0] > l)
				++ans;
			if(p[2] && p[3] && num[i][j+l][1] > l)
				++ans;
			if(num[i][j][1] > 2*l && p[0] && num[i+l][j-l][2] > l)
				++ans;
			if(num[i][j][1] > 2*l && p[2] && num[i+l][j+l][0] > l)
				++ans;
			if(num[i][j][3] > 2*l && p[2] && num[i][j+2*l][0] > l)
				++ans;
		}
	printf("%d\n", ans);
	return 0;
}