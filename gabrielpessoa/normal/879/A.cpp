#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int SIZE = 1005;
const double PI = 3.14159265359;

int main() {
	int n, s, d;
	cin >> n;
	int atual = 0;
	for(int i = 0; i < n; i++) {
		cin >> s >> d;
		if(s <= atual) {
		atual = s + d* ((atual-s)/d + 1);
		} else {
			atual = s;
		}
		//printf("%d\n", atual);
	}
	cout << atual << endl;
	return 0;
}