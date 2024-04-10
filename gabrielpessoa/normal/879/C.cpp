#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int SIZE = 500005;
const double PI = 3.14159265359;

#define x 3
#define nx 2

int val;
char op[2];

int estado[10];

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 0; i < 10; i++) {
		estado[i] = x;
	}
	for(int i = 0; i < n; i++) {
		scanf("%s %d", op, &val);
		//printf("%s %d\n", op, val);
		if(op[0] == '|') {
			for(int bit = 0; bit < 10; bit++) {
				if(val & 1) {
					estado[bit] = 1;
				}
				val = val >> 1;
			}
		} else if(op[0] == '&') {
			for(int bit = 0; bit < 10; bit++) {
				if(!(val & 1)) {
					estado[bit] = 0;
				}
				val = val >> 1;
			}
		} else {
			//printf("%d\n", val);
			for(int bit = 0; bit < 10; bit++) {
				if(val & 1) {
					//printf("BIT %d: invertido\n", bit);
					if(estado[bit] == 0 || estado[bit] == nx) {
						estado[bit]++;
					} else {
						estado[bit]--;
					}
				}
				val = val >> 1;
			}
		}
	}
	printf("3\n");
	int valXOR = 0;
	int valAND = 1023;
	int valOR = 0;
	for(int bit = 0; bit < 10; bit++) {
		if(estado[bit] == nx) {
			//printf("Bit invertido na respota: %d\n", bit);
			valXOR += 1 << bit;
		} else if(estado[bit] == 1) {
			valOR += 1 << bit;
		} else if(estado[bit] == 0) {
			valAND -= 1 << bit;
		}
	}
	printf("^ %d\n& %d\n| %d\n", valXOR, valAND, valOR);	
	return 0;
}