#include<bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;
int N;
pii A, B, C;

int quadrant(pii p) {
	int x = p.first, y = p.second;
	assert(x != 0);
	assert(y != 0);
	assert(x + y != 0);
	assert(x - y != 0);
	int r = 0;
	if (x < 0) r |= 8;
	if (y < 0) r |= 4;
	//if (x + y < 0) r |= 2;
	//if (x - y < 0) r |= 1;
	return r;
}

int quadrant(pii orig, pii p) {
	p.first -= orig.first;
	p.second -= orig.second;
	return quadrant(p);
}

int main() {
	cin >> N;
	cin >> A.first >> A.second;
	cin >> B.first >> B.second;
	cin >> C.first >> C.second;
	if (quadrant(A, B) == quadrant(A, C)) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}

	return 0;
}