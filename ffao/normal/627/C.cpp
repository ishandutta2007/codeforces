#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <inttypes.h>
#include <ctype.h>
#include <algorithm>
#include <utility>
#include <iostream>

using namespace std;

typedef pair<int,int> pii;

int n,m,d;
int t[210000];

void upd(int *t, int x, int s) {
	while (x <= m+10) {
		t[x] += s;
		x += x&-x;
	}
}

int rd(int *t, int x) {
	int s = 0;
	while (x > 0) {
		s += t[x];
		x -= x&-x;
	}
	return s;
}

int pilha[210000];
int st, tam;

pair<int, int> stations[210000];

int main(){
	scanf("%d %d %d", &d, &n, &m);

	int rem = d-n;
	long long spent = 0;
	int filled = 0;

	for (int i = 0; i < m; i++) {
		scanf("%d %d", &stations[i].first, &stations[i].second);
		stations[i].first = d - stations[i].first;
	}

	sort(stations, stations + m);

	for (int i = 0; i < m; i++) {

		while (stations[i].first - filled > n) {
			if (st == tam) {
				printf("-1\n");
				return 0;
			}

			int loc = stations[pilha[st]].first;
			int pric = stations[pilha[st]].second;

			int contains = loc - rd(t, pilha[st]+1);
			int will_buy = min(contains, stations[i].first - filled - n);

			spent += pric * 1ll * will_buy;
			rem -= will_buy;
			upd(t, pilha[st]+1, will_buy);
			filled += will_buy;

			if (will_buy == 0) st++;
		}
		
		while (tam > st && stations[pilha[tam-1]].second >= stations[i].second) tam--;
		pilha[tam++] = i;
	}

	while (rem) {
		if (st == tam) {
			printf("-1\n");
			return 0;
		}

		int loc = stations[pilha[st]].first;
		int pric = stations[pilha[st]].second;

		int contains = loc - rd(t, pilha[st]+1);
		int will_buy = min(contains, rem);

		spent += pric * 1ll * will_buy;
		rem -= will_buy;
		upd(t, pilha[st]+1, will_buy);
		filled += will_buy;

		if (will_buy == 0) st++;
	}

	printf("%lld\n", spent);
}