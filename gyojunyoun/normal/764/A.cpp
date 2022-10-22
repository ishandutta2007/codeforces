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

int N, M, Z;
int Ans;

int main() {
	scanf("%d%d%d", &N, &M, &Z);
	for(int i = 1; i <= Z; i++) {
		if(0 == i % N && 0 == i % M) Ans++;
	}
	printf("%d\n", Ans);
	return 0;
}