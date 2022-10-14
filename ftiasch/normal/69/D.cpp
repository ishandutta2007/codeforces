// Codeforces Beta Round #63
// Problem D -- Dot
#include <stdio.h>
#include <string.h>

const int LOSE = 0, WIN = 1;
int x, y, d, n, a[20], b[20], f[2][4][401][401];

int res(int p, int m, int x, int y){
	if(x * x + y * y > d * d)
		return WIN;
	int &r = f[p][m][x + 200][y + 200];
	if(r == -1){
		r = LOSE;
		if((m & (1 << p)) && res(1 - p, m ^ (1 << p), y, x) == LOSE)
			r = WIN;
		for(int i = 0; i != n; ++ i)
			if(res(1 - p, m, x + a[i], y + b[i]) == LOSE)
				r = WIN;
	}
	return r;
}

int main(){
	scanf("%d%d%d%d", &x, &y, &n, &d);
	for(int i = 0; i != n; ++ i)
		scanf("%d%d", a + i, b + i);
	memset(f, -1, sizeof(f));
	printf(res(0, 3, x, y)? "Anton\n": "Dasha\n");
	return 0;
}