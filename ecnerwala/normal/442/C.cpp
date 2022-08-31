#include<bits/stdc++.h>

using namespace std;

const int MAXN = 6e5;

int N;
int A[MAXN];

int prv[MAXN];
int nxt[MAXN];

typedef pair<int, int> pii;
pii vals[MAXN];

long long res = 0;

void print() {
	for(int i = 0; i < N; i = nxt[i]) {
		cerr << i << ' ' << A[i] << '\n';
	}
	cerr << res << '\n';
}


int remove(int i) {
	int p = prv[i];
	int n = nxt[i];
	nxt[p] = n;
	prv[n] = p;
	int v = min(A[p], A[n]);
	if(v == 0) v = A[i];
	res += v;
	return v;
}

int main() {
	cin >> N;
	N += 2;
	A[0] = 0;
	A[N - 1] = 0;
	for(int i = 1; i < N - 1; i++) {
		cin >> A[i];
	}
	for(int i = 0; i < N; i++) {
		prv[i] = i - 1;
		nxt[i] = i + 1;
	}

	int S = 0;
	for(int i = 1; i < N - 1; i++) {
		vals[S++] = pii(A[i], i);
	}
	sort(vals, vals + S);
	for(int i = 0; i < S - 2; i++) {
		int v = vals[i].second;
		remove(v);
	}


	cout << res << '\n';
	return 0;
}