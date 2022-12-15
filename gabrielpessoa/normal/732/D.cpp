#include <bits/stdc++.h>
using namespace std;

#define SIZE 100005

int exame[SIZE];
int dias[SIZE];
bool examesFeitos[SIZE];

int check(int m, int exames) {
	int diasNecessarios = 0;
	memset(examesFeitos, 0, sizeof(examesFeitos));
	//printf("========\n INICIANDO DIA %dd\n", m);
	for(int i = m; i > 0; i--) {
		if(exame[i] == 0 || examesFeitos[exame[i]]) {
			diasNecessarios = max(0, diasNecessarios - 1);
			continue;
		}
		//printf("Exame %d fazer no dia %d\n", exame[i], i);
		examesFeitos[exame[i]] = true;
		diasNecessarios += dias[exame[i]];
	}
	for(int i = 1; i <= exames; i++) {
		if(!examesFeitos[i]) {
			//printf("ate o dia %d nao foi feito o exame %d\n", m, i);
			return 1;
		}
	}
	//printf("Ate o dia %d faltou %d dias\n", m, diasNecessarios);
	return diasNecessarios;
}
int main() {
	int n, m, diasLivres = 0, ultimoDia = 0;
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++) {
		scanf("%d", exame + i);
	}
	for(int i = 1; i <= m; i++) {
		scanf("%d", dias + i);
	}
	int l = 0, r = n;
	int best = 0x3f3f3f;
	while(l < r - 1) {
		int meio = (l+r)/2;
		//printf("Com L = %d  e R = %d  o meio  = %d\n", l, r, meio);
		if(check(meio, m)) {
			l = meio + 1;
		} else {
			best = min(best, meio);
			r = meio - 1;
		}
	}
	if(!check(l, m)) {
		best = min(best, l);
	} else if(!check(r, m)) {
		best = min(best, r);
	}
	if(best == 0x3f3f3f) {
		printf("-1\n");
	} else {
		printf("%d\n", best);
	}
	return 0;
}