#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <deque>
#include <set>
#define pb push_back
#define sz(V) ((int)(V).size())
#define allv(V) ((V).begin()),((V).end())
#define befv(V) ((V)[(sz(V)-2)])
#define MAXN (100005)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

bool SX[MAXN], SY[MAXN];
int SXn, SYn;
ll Ans;
int N, M;

int main() {
	scanf("%d%d", &N, &M);
	Ans = (ll)N*N;
	for(int y, x; M--;) {
		scanf("%d%d", &y, &x);
		if(SY[y] && SX[x]) Ans++;
		if(!SY[y]) {
			Ans -= N-SXn-1;
		}
		if(!SX[x]) {
			Ans -= N-SYn-1;
		}
		if(!SY[y]) { SY[y] = true; SYn++; }
		if(!SX[x]) { SX[x] = true; SXn++; }
		Ans--;
		cout << Ans << " ";
	}
	cout << "\n";
	return 0;
}