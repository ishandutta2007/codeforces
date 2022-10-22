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
#define MAXN (200005)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int A[MAXN];
int N;

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
	for(int i = 1; i*2 <= N; i++) {
		if(i&1) swap(A[i], A[N-i+1]);
	}
	for(int i = 1; i <= N; i++) printf("%d ", A[i]);
	printf("\n");
	return 0;
}