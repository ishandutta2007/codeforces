#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define A first
#define B second

int gcd(int a, int b) { return a ? gcd(b % a, a) : b; }

const int MAXN = 2e5;
int N;
int A[MAXN];

map<int, ll> dp;
map<int, ll> res;
int main() {
	ios_base::sync_with_stdio(0);
	cin >> N;
	for(int i = 0; i < N; i++) {
		int v; cin >> v;
		map<int, ll> ndp;
		ndp[v] += 1;
		res[v] += 1;
		for(auto it : dp) {
			ndp[gcd(it.A, v)] += it.B;
			res[gcd(it.A, v)] += it.B;
		}
		dp = ndp;
	}
	int Q; cin >> Q;
	for(int i = 0; i < Q; i++) {
		int v; cin >> v;
		cout << res[v] << '\n';
	}
	return 0;
}