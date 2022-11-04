#include <bits/stdc++.h>
using namespace std;
int main() {
    long long n, a, b, c, d, s1, s2;
    cin >> n;
    for (int i = 0; i < n; i++) {
	cin >> a >> b >> c >> d;
	s1 = a+b;
	s2 = c+d;
	cout << max(s1, s2) << endl;
    }
}