#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;
typedef pair<ll, ii> iii;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;

const int INF = 0x3f3f3f3f;
const int SIZE = 1E5 + 5;


int arr[SIZE];
int maximo[SIZE];

int main() {
	int n, d;
	scanf("%d %d", &n, &d);
	
	for(int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	
	int moneyAtual = 0;
	for(int i = 0; i < n; i++) {
		moneyAtual += arr[i];
		if(moneyAtual > d) {
			printf("-1\n");
			return 0;
		}
		maximo[i] = d - moneyAtual;
	}
	for(int i = n - 2; i >= 0; i--) {
		maximo[i] = min(maximo[i], maximo[i+1]);
	}
	int quantidadeDias = 0, moneyDepositado = 0;
	moneyAtual = 0;
	for(int i = 0; i < n; i++) {
		moneyAtual += arr[i];
		if(!arr[i] && moneyAtual < 0) {
			moneyAtual += maximo[i] - moneyDepositado;
			quantidadeDias++;
			moneyDepositado = maximo[i];
			if(moneyAtual < 0) {
				printf("-1\n");
				return 0;
			}
		}
	}
	printf("%d\n", quantidadeDias);
	return 0;
}