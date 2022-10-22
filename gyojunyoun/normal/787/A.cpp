#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <deque>
#define pb push_back
#define sz(V) ((int)(V).size())
#define allv(V) ((V).begin()),((V).end())
#define befv(V) ((V)[(sz(V)-2)])
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int A, B, C, D;
// B+ka, D+kC

int main() {
	scanf("%d%d%d%d", &A, &B, &C, &D);
	for(int i = 0; i < 8000000; i++) {
		if(B == D) { printf("%d\n", B); return 0; }
		if(B < D) B += A;
		else D += C;
	}
	puts("-1");
	return 0;
}