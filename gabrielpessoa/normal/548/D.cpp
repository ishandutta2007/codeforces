#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef pair<ii, int> iii;
typedef pair<ll, ll> llll;

const int SIZE  = 2E5+5;
const int MOD = 1E6;
const double EPS = 1e-7;
const int INF = 0x3f3f3f3f;

ii arr[SIZE];
//int arrBF[SIZE];
int melhor[SIZE];
//int melhorBF[SIZE];
set<int> pos;

int main() {
	int n;
	scanf("%d", &n);
	//n = 50;
	for(int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		//x = rand() % 100;
		arr[i] = ii(x, i+1);
		//arrBF[i] = x;
	}
	sort(arr, arr+n);
	pos.insert(0);
	pos.insert(n+1);
	for(int i = 0; i < n; i++) {
		auto bound = pos.lower_bound(arr[i].second);
		int top, bot;
		top = *bound;
		--bound;
		bot = *bound;
		melhor[top - bot - 1] = arr[i].first;
		pos.insert(arr[i].second);
	}
	for(int i = n-1; i >= 1; i--) {
		melhor[i] = max(melhor[i], melhor[i+1]);
	}
	for(int i = 1; i <= n; i++) {
		printf("%d ", melhor[i]);
	}
	/*for(int i = 0; i < n; i++) {
		int tamanho = 1;
		for(int j = i+1; j < n; j++) {
			if(arrBF[j] < arrBF[i]) break;
			tamanho++;
		}
		for(int j = i-1; j >= 0; j--) {
			if(arrBF[j] < arrBF[i]) break;
			tamanho++;
		}
		melhorBF[tamanho] = max(melhorBF[tamanho], arrBF[i]);
	}
	for(int i = n-1; i >= 1; i--) {
		melhorBF[i] = max(melhorBF[i], melhorBF[i+1]);
	}
	printf("\n");
	for(int i = 1; i <= n; i++) {
		printf("%d ", melhorBF[i]);
	}*/
	return 0;
}