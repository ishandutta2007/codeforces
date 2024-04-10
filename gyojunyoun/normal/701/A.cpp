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
#define MAXN (105)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

vector<int> A[MAXN];
int N, Sum;

int main() {
	scanf("%d", &N);
	for(int i = 0; i < N; i++) {
		int c; scanf("%d", &c); Sum += c;
		A[c].pb(i+1);
	}
	Sum /= (N/2);;
	for(int i = 1; i <= 100;) {
		if(A[i].empty()) { i++; continue; }
		int tmp = A[i].back(); A[i].pop_back();
		printf("%d %d\n", tmp, A[Sum-i].back());
		A[Sum-i].pop_back();
	}
	return 0;
}