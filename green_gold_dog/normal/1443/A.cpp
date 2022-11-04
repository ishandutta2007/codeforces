#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long a, b;
    cin >> a;
    for (int i = 0; i < a; i++) {
	cin >> b;
	if (b == 3) {
	    cout << "4 6 10";
	} else {
	    for (int j = b*2; j < b*4; j += 2) {
		cout << j << ' ';
	    }
	}
	cout << "\n";
    }
}