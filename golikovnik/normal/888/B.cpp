#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define fi first
#define se second

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	string moves;
	cin >> moves;
	int l = count(moves.begin(), moves.end(), 'L');
	int r = count(moves.begin(), moves.end(), 'R');
	int u = count(moves.begin(), moves.end(), 'U');
	int d = count(moves.begin(), moves.end(), 'D');
	cout << n - abs(l - r) - abs(u - d);
	return 0;
}