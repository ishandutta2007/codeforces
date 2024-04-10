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

int val(long long x) {
	int res = 0;
	int cur = 1;
	while (x > 0) {
		if (x % 2)
			res += cur;
		cur *= 2;
		x /= 10;
	}
	return res;
}

int sval(const string& s) {
	int res = 0;
	for (char c : s) {
		res = res * 2 + c - '0';
	}
	return res;
}

int main(){

	cin.sync_with_stdio(0);
	cout.sync_with_stdio(0);

	map<int, int> M;
	int t;
	cin >> t;
	while (t--) {
		char c;
		cin >> c;
		if (c == '+') {
			long long x;
			cin >> x;
			M[val(x)]++;
		} else
		if (c == '-') {
			long long x;
			cin >> x;
			M[val(x)]--;
		} else {
			string s;
			cin >> s;
			cout << M[sval(s)] << "\n";
		}
	}

	return 0;
}