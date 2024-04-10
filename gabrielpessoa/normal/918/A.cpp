#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef pair<ii, int> iii;
typedef pair<ll, ll> llll;

const int SIZE  = 1005;
const int MOD = 1E6;
const int DELTA = 1E5+2;
const double PI = atan(1)*4;
const double EPS = 8e-5;
const int INF = 0x3f3f3f3f;

int fib[SIZE];
bool isFib[SIZE];

int main() {
	fib[0] = 0;
	fib[1] = 1;
	for(int i = 2; i < SIZE; i++) {
		fib[i] = fib[i-1] + fib[i-2];
	}
	for(int i = 0; i < SIZE; i++) {
		if(fib[i] >= SIZE) break;
		isFib[fib[i]] = true;
	}
	int n;
	string s;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		if(isFib[i]) {
			s.push_back('O');
		} else {
			s.push_back('o');
		}
	}
	cout << s << endl;
	return 0;
}