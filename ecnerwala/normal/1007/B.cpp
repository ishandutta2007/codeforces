#include<bits/stdc++.h>
using namespace std;

const int MAXV = 2e5;
const int V = 1.2e5;
int sigma[MAXV];

int p2(int n) {
	return n * (n-1);
}

int c2(int n) {
	return n * (n-1) / 2;
}

int c3(int n) {
	return n * (n-1) * (n-2) / 6;
}

int g3(int n) {
	return c3(n+2);
}

int g2(int n) {
	return c2(n+1);
}

int go(int A, int B, int C) {
	int AB = __gcd(A,B);
	int BC = __gcd(B,C);
	int CA = __gcd(C,A);
	int ABC = __gcd(AB,C);

	int sA = sigma[A] - sigma[AB] - sigma[CA] + sigma[ABC];
	int sB = sigma[B] - sigma[BC] - sigma[AB] + sigma[ABC];
	int sC = sigma[C] - sigma[CA] - sigma[BC] + sigma[ABC];
	int sAB = sigma[AB] - sigma[ABC];
	int sBC = sigma[BC] - sigma[ABC];
	int sAC = sigma[CA] - sigma[ABC];
	int sABC = sigma[ABC];

	int res = 0;
res += sA * sB * sC;
res += sA * sB * sAC;
res += sA * sB * sBC;
res += sA * sB * sABC;
res += sA * sAB * sC;
res += sA * sAB * sAC;
res += sA * sAB * sBC;
res += sA * sAB * sABC;
res += sA * sC * sBC;
res += sA * sC * sABC;
res += sA * sAC * sBC;
res += sA * sAC * sABC;
res += sA * g2(sBC);
res += sA * sBC * sABC;
res += sA * g2(sABC);
res += sB * sAB * sC;
res += sB * sAB * sAC;
res += sB * sAB * sBC;
res += sB * sAB * sABC;
res += sB * sC * sAC;
res += sB * sC * sABC;
res += sB * g2(sAC);
res += sB * sAC * sBC;
res += sB * sAC * sABC;
res += sB * sBC * sABC;
res += sB * g2(sABC);
res += g2(sAB) * sC;
res += g2(sAB) * sAC;
res += g2(sAB) * sBC;
res += g2(sAB) * sABC;
res += sAB * sC * sAC;
res += sAB * sC * sBC;
res += sAB * sC * sABC;
res += sAB * g2(sAC);
res += sAB * sAC * sBC;
res += sAB * sAC * sABC;
res += sAB * g2(sBC);
res += sAB * sBC * sABC;
res += sAB * g2(sABC);
res += sC * sAC * sBC;
res += sC * sAC * sABC;
res += sC * sBC * sABC;
res += sC * g2(sABC);
res += g2(sAC) * sBC;
res += g2(sAC) * sABC;
res += sAC * g2(sBC);
res += sAC * sBC * sABC;
res += sAC * g2(sABC);
res += g2(sBC) * sABC;
res += sBC * g2(sABC);
res += g3(sABC);

	return res;
}

int main() {
	for (int i = 1; i <= V; i++) {
		for (int j = i; j <= V; j += i) {
			sigma[j] ++;
		}
	}

	int T; scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		int A, B, C; scanf("%d %d %d", &A, &B, &C);
		assert(1 <= A && A <= V);
		assert(1 <= B && B <= V);
		assert(1 <= C && C <= V);
		printf("%d\n", go(A,B,C));

	}

	return 0;
}