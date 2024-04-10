#include <bits/stdc++.h>

#define itn int
#define LL long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(x) (x).begin(), (x).end()

using namespace std;

inline int nxt(){
	int x;
	scanf("%d", &x);
	return x;
}

int anti_c(long long x){
	long long l = 1, r = 1000000000;
	while (r > l + 1){
		long long m = (l + r) / 2;
		if (m * (m - 1) / 2 > x)
			r = m;
		else
			l = m;
	}
	if (l * (l - 1) / 2 == x)
		return l;
	else
		return -1;
}

void panic(){
	puts("Impossible");
	exit(0);
}

int main(){

	long long a00 = nxt(), a01 = nxt(), a10 = nxt(), a11 = nxt();
	int n = anti_c(a00 + a01 + a10 + a11);
	int c0 = anti_c(a00);
	int c1 = anti_c(a11);
	if (n == -1 || c0 == -1 || c1 == -1)
		panic();

	if (a00 == 0 || a11 == 0){
		if (a00 == 0 && a11 == 0){
			if (a01 == 0 && a10 == 0){
				cout.sync_with_stdio(0);
				if (a00){
					cout << string(c0, '0') << "\n";
				} else {
					cout << string(c1, '1') << "\n";
				}
				return 0;
			} else
			if (a01 == 0 && a10 == 1){
				cout << "10\n";
				return 0;
			} else if (a01 == 1 && a10 == 0){
				cout << "01\n";
				return 0;
			} else {
				panic();
			}
		} else
		if (a00 == 0){
			if (a01 == 0 && a10 == 0){
				cout.sync_with_stdio(0);
				cout << string(c1, '1') << "\n";
				return 0;
			} else {
				if (a10 + a01 == c1){
					cout.sync_with_stdio(0);
					cout << string(a10, '1') << "0" << string(a01, '1') << "\n";
					return 0;
				} else {
					panic();
				}
			}
		} else
		if (a11 == 0){
			if (a01 == 0 && a10 == 0){
				cout.sync_with_stdio(0);
				cout << string(c0, '0') << "\n";
				return 0;
			} else {
				if (a10 + a01 == c0){
					cout.sync_with_stdio(0);
					cout << string(a01, '0') << "1" << string(a10, '0') << "\n";
					return 0;
				} else {
					panic();
				}
			}
		} else {
			assert(false);
		}
	}

	if (c0 + c1 != n){
		panic();
	}

	string s = "";
	cout.sync_with_stdio(0);
	if (a10 == 0){
		for (int i = 0; i < c0; i++)
			s += '0';
		for (int i = 0; i < c1; i++)
			s += '1';
		cout << s << "\n";
		return 0;
	} else if (a01 == 0){
		for (int i = 0; i < c1; i++)
			s += '1';
		for (int i = 0; i < c0; i++)
			s += '0';
		cout << s << "\n";
		return 0;
	}
	int x = a01 / c1;
	int b = a01 % c1;
	for (int i = 0; i < x; i++)
		s += '0';
	for (int i = 0; i < c1 - b; i++)
		s += '1';
	s += '0';
	for (int i = 0; i < b; i++)
		s += '1';
	for (int i = 0; i < c0 - x - 1; i++)
		s += '0';
	cout << s << "\n";

	return 0;
}