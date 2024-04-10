#include <bits/stdc++.h>
using namespace std;

int n, m;
char g[110][110];

void solve(int c, int i) {
	for(int j = 1; j <= m; j++) {
		if(g[i][j] != '*') continue;
		int sz = 1, flag = 0;
		for(;;sz++) {
			if(i + sz > n + 1 || j + sz > m + 1) flag = 1;
			
			for(int k = i; k < i + sz; k++)
				for(int l = j; l < j + sz; l++)
					if(g[k][l] != '*') flag = 1;
			
			for(int k = i; k < i+sz && !flag; k++) if(g[k][j-1] == c) flag = 1;
			for(int k = j; k < j+sz && !flag; k++) if(g[i-1][k] == c) flag = 1;
			for(int k = i; k < i+sz && !flag; k++) if(g[k][j+sz] == c) flag = 1;
			for(int k = j; k < j+sz && !flag; k++) if(g[i+sz][k] == c) flag = 1;
			if(flag) break;
		} sz--;
		for(int k = i; k < i + sz; k++)
			for(int l = j; l < j + sz; l++)
				g[k][l] = c;
	}
}

int main() {
    scanf("%d %d", &n, &m);
    memset(g, '*', sizeof g);
    for(int i = 1; i <= n; i++)
		for(int c = 'A'; c <= 'Z'; c++)
			solve(c, i);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++)
            printf("%c", g[i][j]);
        puts("");
    }
    return 0;
}