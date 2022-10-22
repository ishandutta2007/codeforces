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
#define INF (2147483647)
#define MAXN (100005)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int A[MAXN];
int C[55], Cn, Sn;
int N, Ans = INF;

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) {
		char c; scanf(" %c", &c);
		if('a' <= c && c <= 'z') {
			A[i] = c - 'a';
		} else {
			A[i] = c - 'A' + 26;
		}
	}
	for(int i = 1; i <= N; i++) C[A[i]] = 1;
	for(int i = 0; i < 52; i++) if(C[i]) Sn++;
	for(int i = 0; i < 52; i++) C[i] = 0;
	for(int i = 1, j = 0; i <= N && j <= N;) {
		for(; j <= N && Cn < Sn;) {
			j++; if(N < j) break;
			C[A[j]]++; if(1 == C[A[j]]) Cn++;
		}
		if(Sn == Cn) Ans = min(Ans, j-i+1);
		C[A[i]]--; if(0 == C[A[i]]) Cn--;
		i++;
	}
	printf("%d\n", Ans);
	return 0;
}