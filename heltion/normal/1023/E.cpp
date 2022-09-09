#include<bits/stdc++.h>
#define maxn 1000
using namespace std;
char s[maxn];
int ask(int r1, int c1, int r2, int c2){
	printf("? %d %d %d %d\n", r1, c1, r2, c2);
	fflush(stdout);
	scanf("%s", s);
	if(s[0] == 'Y') return 1;
	return 0;
}
int a[maxn][maxn];
int main(){
	int n;
	scanf("%d", &n);
	int x = 1, y = 1;
	for(int i = 1; i < n; i += 1){
		a[x][y] = 1;
		if(ask(x + 1, y, n, n)) x += 1;
		else y += 1;
	}
	a[x][y] = 1;
	x = n, y = n;
	for(int i = 1; i < n; i += 1){
		a[x][y] = 1;
		if(ask(1, 1, x, y - 1)) y -= 1;
		else x -= 1;
	}
	a[x][y] = 1;
	printf("! ");
	x = 1, y = 1;
	for(int i = 0; i < 2 * n - 2; i += 1){
		if(x == n && y == n) break;
		if(a[x + 1][y] == 1){
			printf("D");
			x += 1;
		}
		else{
			printf("R");
			y += 1;
		}
	}
	printf("\n");
	fflush(stdout);
}