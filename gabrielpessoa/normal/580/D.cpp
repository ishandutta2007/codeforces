#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef pair<int, double> id;
typedef vector<id> vid;
typedef pair<double, int> di;
typedef vector<di> vdi;
typedef pair<ll, ll> llp;
typedef pair<string, string> ss;

const int SIZE  = 1E5+5;
const int MOD = 1E9 + 7;
const double EPS = 1e-7;
const int INF = 0x3f3f3f3f;

ll pd[1<<18][20];
int n, m, k;
ll sat[18];
ll rules[18][18];

ll best(int mask, int ultimo, int qnt) {
	//printf("Testando %d %d %d\n", mask, ultimo, qnt);
	if(~pd[mask][ultimo]) return pd[mask][ultimo];
	//printf("Nao fez a pd :)\n");
	if(qnt == m) return pd[mask][ultimo] = 0;
	ll maximo = 0;
	for(int i = 0; i < n; i++) {
		//printf("Indo pra %d\n", i);
		if(!(mask & (1 << i))) {
			ll ganho = sat[i];
			if(ultimo != 19) ganho += rules[ultimo][i];
			maximo = max(maximo, ganho + best(mask | (1 << i), i, qnt + 1));
		}
	}
	return pd[mask][ultimo] = maximo;
}

int main() {
	scanf("%d %d %d", &n, &m, &k);
	memset(pd, -1, sizeof(pd));
	for(int i = 0; i < n; i++) {
		scanf("%lld", &sat[i]);
	}
	for(int i = 0; i < k; i++) {
		int x, y;
		ll c;
		scanf("%d %d %lld", &x, &y, &c);
		x--; y--;
		rules[x][y] = c;
	}
	printf("%lld\n", best(0, 19, 0));
	return 0;
}