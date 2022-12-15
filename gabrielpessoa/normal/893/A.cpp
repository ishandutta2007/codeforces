#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;
typedef pair<ll, ii> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;

const int INF = 0x3f3f3f3f;
const int SIZE = 200005;

int main() {
	int n;	
	int espectador = 3;
	cin >> n;
	while(n--) {
		int ganhador;
		cin >> ganhador;
		if(ganhador == espectador) {
			puts("NO");
			return 0;
		}
		if(espectador == 1) {
			if(ganhador == 2) {
				espectador = 3;
			} else {
				espectador = 2;
			}
		} else if(espectador == 2) {
			if(ganhador == 1) {
				espectador = 3;
			} else {
				espectador = 1;
			}
		} else {
			if(ganhador == 1) {
				espectador = 2;
			} else {
				espectador = 1;
			}
		}
	}
	puts("YES");
	return 0;
}