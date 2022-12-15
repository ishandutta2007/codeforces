#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef pair<ii, int> iii;
typedef pair<ll, ll> llll;

const int SIZE  = 2E6+5;
const int MOD = 1E6;
const double EPS = 1e-7;
const int INF = 0x3f3f3f3f;

ll cicloA[SIZE];
ll cicloB[SIZE];
ll diferencasDistancias[SIZE];

int main() {
	ll m, h1, a1, x1, y1, h2, a2, x2, y2;
	scanf("%lld %lld %lld %lld %lld %lld %lld %lld %lld", &m, &h1, &a1, &x1, &y1, &h2, &a2, &x2, &y2);
	ll duracaoCiclo1 = -1;
	ll inicioCiclo1 = -1;
	for(ll t = 2; cicloA[h1] == 0; t++) {
		//cerr << "certo aqui zero" << endl;
		//printf("cicloA[%d] era %d e agora eh %d\n", h1, cicloA[h1], t - 1);
		cicloA[h1] = t-1;
		h1 = (x1*h1+y1)%m;
		if(cicloA[h1] != 0) {	
			duracaoCiclo1 = t - cicloA[h1];
			inicioCiclo1 = cicloA[h1] - 1;
			cicloA[a1]--;
			//cerr << "certo aqui um" << endl;
		}
	}
	if(cicloA[a1] == -1) {
		printf("-1\n");
		//cerr << "menosum" << endl;
		return 0;
	}
	ll duracaoCiclo2 = -1;
	ll inicioCiclo2 = -1;
	for(ll t = 2; cicloB[h2] == 0; t++) {
		cicloB[h2] = t-1;
		h2 = (x2*h2+y2)%m;
		if(cicloB[h2] != 0) {
			duracaoCiclo2 = t - cicloB[h2];
			inicioCiclo2 = cicloB[h2] - 1;
			cicloB[a2]--;
			//cerr << "certo aqui dois" << endl;
		}
	}
	if(cicloB[a2] == -1) {
		printf("-1\n");
		//cerr << "zero" << endl;
		return 0;
	}
	if(cicloA[a1] == cicloB[a2]) {
		printf("%lld\n", cicloA[a1]);
		//cerr << "um" << endl;
		return 0;
	}
	if(cicloA[a1] < inicioCiclo1) {
		if(cicloB[a2] >= inicioCiclo2 && cicloB[a2] < cicloA[a1] && (cicloA[a1] - cicloB[a2]) % duracaoCiclo2 == 0) {
			printf("%lld\n", cicloA[a1]);
			return 0;
		}
		printf("-1\n");
		//cerr << "dois" << endl;
		return 0;
	}
	if(cicloB[a2] < inicioCiclo2) {
		if(cicloA[a1] >= inicioCiclo1 && cicloA[a1] < cicloB[a2] && (cicloB[a2] - cicloA[a1]) % duracaoCiclo1 == 0) {
			printf("%lld\n", cicloB[a2]);
			return 0;
		}
		printf("-1\n");
		//cerr << "dois" << endl;
		return 0;
	}
	inicioCiclo1 = cicloA[a1];
	inicioCiclo2 = cicloB[a2];
	if(inicioCiclo2 < inicioCiclo1) {
		swap(inicioCiclo1, inicioCiclo2); //
		swap(duracaoCiclo1, duracaoCiclo2);
	}
	//printf("oi\n");
	//inicioCiclo1 = inicioCiclo1 + duracaoCiclo1*((inicioCiclo2 - inicioCiclo1)/duracaoCiclo1);
	while(diferencasDistancias[inicioCiclo2 - inicioCiclo1] == 0) {
		diferencasDistancias[inicioCiclo2 - inicioCiclo1] = 1;
		if(inicioCiclo1 + duracaoCiclo1 > inicioCiclo2) {
			inicioCiclo2 += duracaoCiclo2;
		} else {
			inicioCiclo1 += duracaoCiclo1;
		}
		if(inicioCiclo1 == inicioCiclo2) {
			printf("%lld\n", inicioCiclo1);
			//cerr << "quatro" << endl;
			return 0;
		}
		//printf("%lld\n", inicioCiclo2 - inicioCiclo1);
	}
	printf("-1\n");
	//cerr << "cinco" << endl;
	return 0;
}