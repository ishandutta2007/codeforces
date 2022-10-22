#include <bits/stdc++.h>

using namespace std;

char field[105][105];
int x[105], y[105];

int main(){
	int n, m;
	cin >> n >> m;
	for(int i=0; i < n; ++i)
		scanf("%s", field[i]);
	for(int i=0; i < n; ++i)
		for(int j=0; j < m; ++j)
			if(field[i][j] == '*'){
				++x[i];
				++y[j];
			}
	for(int i=0; i < n; ++i)
		for(int j=0; j < m; ++j)
			if(x[i] == 1 && y[j] == 1)
				printf("%d %d\n", i+1, j+1);
	
}