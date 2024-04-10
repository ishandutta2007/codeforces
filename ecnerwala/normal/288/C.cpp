#include<iostream>
using namespace std;

typedef long long ll;

const ll MAXN = 1000010;

int N;
int p[MAXN];

void go() {
	for(int s = 0; s < N;) {
		int n = N - s;
		int l = 0;
		while(1 << (l + 1) < n) l++;
		for(int i = 0; i < 1 << l; i++) {
			p[s + (1 << l) - 1 - i] = i + ((!!(i + (1 << l) < n)) << l);
		}
		s += 1 << l;
	}
}

int main() {
	cin >> N; N++;
	go();
	ll beauty = 0;
	for(int i = 0; i < N; i++) beauty += p[i] ^ i;
	cout << beauty << '\n';
	cout << p[0];
	for(int i = 1; i < N; i++) cout << ' ' << p[i];
	cout << '\n';
	return 0;
}