#include <iostream>

using namespace std;

typedef long long ll;

ll a[111111], w, h, n, m, h1, h2;

int main() {
	cin >> n;
	for (int i=0; i<n; i++) cin >> a[i];
	cin >> m;
	for (int i=0; i<m; i++) {
		cin >> w >> h;
		h1=max(h1+h2, a[w-1]);
		h2=h;
		cout << h1 << ' ';
	}
	return 0;
}