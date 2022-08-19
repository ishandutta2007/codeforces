#include<bits/stdc++.h>
using namespace std;

int max(int a, int b, int c) {
	return max(max(a,b), c);
}
int min(int a, int b, int c) {
	return min(min(a,b), c);
}

int med(int a, int b, int c) {
	return a + b + c - max(a,b,c) - min(a,b,c);
}

pair<int, int> A[3];
int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	for (int i = 0; i < 3; i++) {
		cin >> A[i].first >> A[i].second;
	}
	sort(A, A + 3);
	// sort them by the x coordinate
	int maxy = max(A[0].second, A[1].second, A[2].second);
	int miny = min(A[0].second, A[1].second, A[2].second);
	cout << (maxy - miny + 1) + (A[2].first - A[0].first) << '\n';
	for (int y = miny; y <= maxy; y++) {
		cout << A[1].first << ' ' << y << '\n';
	}
	for (int x = A[0].first; x < A[1].first; x++) {
		cout << x << ' ' << A[0].second << '\n';
	}
	for (int x = A[2].first; x > A[1].first; x--) {
		cout << x << ' ' << A[2].second << '\n';
	}

	return 0;
}