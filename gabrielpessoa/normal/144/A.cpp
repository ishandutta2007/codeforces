#include <bits/stdc++.h>
using namespace std;

const int SIZE = 105;

int arr[SIZE];

int main() {
	int n;
	int maiorPos = -1, menorPos = -1, maior = 0, menor = 200;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		if(x > maior) {
			maior = x;
			maiorPos = i;
		}
		if(x <= menor) {
			menor = x;
			menorPos = i;
		}
	}
	if(menorPos < maiorPos) {
		menorPos++;
	}
	//printf("%d %d\n", maiorPos, menorPos);
	printf("%d\n", maiorPos + (n - 1 - menorPos));
}