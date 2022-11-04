#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, nn, x, c;
    cin >> n;
    vector<int> v1, v2;
    for (int i = 0; i < n; i++) {
	c = 0;
	cin >> nn >> x;
	v1.resize(nn);
	v2.resize(nn);
	for (int j = 0; j < nn; j++) {
	    cin >> v1[j];
	}
	for (int j = 0; j < nn; j++) {
	    cin >> v2[j];
	}
	reverse(v1.begin(), v1.end());
	for (int j = 0; j < nn; j++) {
	    if (v1[j] + v2[j] > x) {
		c = 1;
		break;
	    }
	}
	if (c == 0) {
	    cout << "Yes" << endl;
	} else {
	    cout << "No" << endl;
	}
    }
}