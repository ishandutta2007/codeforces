#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
#define A first
#define B second

const int MAXN = 30;
int N;
int A[MAXN];

int gcd(int a, int b) {
	return a ? gcd(b % a, a) : b;
}

int main() {
	cin >> N;
	for(int i = 0; i < N; i++) cin >> A[i];
	int g = A[0];
	for(int i = 1; i < N; i++) g = gcd(g, A[i]);
	for(int i = 0; i < N; i++) A[i] /= g;
	int cnt = 0;
	for(int i = 0; i < N; i++) cnt += A[i] % 2;
	assert(cnt); // otherwise, divide by gcd again
	if(cnt == 1) cout << g << '\n';
	else {
		if(g % 2 == 0) {
			cout << g << '\n';
			g /= 2;
			for(int i = 0; i < N; i++) A[i] *= 2;
		}  else {
			cout << 0 << '\n';
		}
	}
	string s;
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < A[i] / 2; j++) {
			s += char('a' + i);
		}
	}
	string t = s;
	reverse(t.begin(), t.end());
	s += t;
	for(int i = 0; i < N; i++) {
		if(A[i] % 2 == 1) s += char('a' + i);
	}
	for(int i = 0; i < g; i++) cout << s; cout << '\n';
	return 0;
}