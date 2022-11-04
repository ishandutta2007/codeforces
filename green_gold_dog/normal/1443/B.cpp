#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long a, b, c, szn, n, sum;
    cin >> a;
    string str;
    for (int i = 0; i < a; i++) {
	cin >> b >> c;
	cin >> str;
	sum = 0;
	for (int i = 0; i < str.size(); i++) {
	    if (str[i] == '1') {
		n = i + 1;
		sum = b;
		break;
	    }
	}
	szn = 0;
	for (int i = n; i < str.size(); i++) {
	    if (str[i] == '1') {
		sum += min(szn * c, b);
		szn = 0;
	    } else {
		szn += 1;
	    }
	}
	cout << sum << endl;
    }
}