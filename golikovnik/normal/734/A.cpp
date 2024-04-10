#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define sz(x) (int) x.size()
#define X first
#define Y second
#define endl '\n'

typedef long long ll;
typedef long double ld;
typedef double D;

template<typename T = int> inline T read() {
	T x;
	cin >> x;
	return x;
}
template<typename T> inline void uax(T &a, T b) {a = max(a, b);}
template<typename T> inline void uin(T &a, T b) {a = min(a, b);}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n = read();
	int cntA = 0, cntB = 0;
	char c;
	while (cin >> c) {
		if (c == 'A') {
			++cntA;
		} else {
			++cntB;
		}
	}
	cout << (cntA > cntB ? "Anton" : (cntA == cntB) ? "Friendship" : "Danik") << endl;
	return 0;
}