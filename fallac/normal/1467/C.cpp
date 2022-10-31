#include <bits/stdc++.h>
using namespace std;
typedef long long int lld;
#define MAX 303030
int main(void) {
	lld N1, N2, N3;
	cin >> N1 >> N2 >> N3;
	lld i;
	lld m1, m2, m3;
	m1 = m2 = m3 = 1000000001;
	lld s1, s2, s3;
	s1 = s2 = s3 = 0;
	lld a;
	for (i = 1; i <= N1; i++) {
		cin >> a;
		m1 = min(a, m1);
		s1 += a;
	}
	for (i = 1; i <= N2; i++) {
		cin >> a;
		m2 = min(a, m2);
		s2 += a;
	}
	for (i = 1; i <= N3; i++) {
		cin >> a;
		m3 = min(a, m3);
		s3 += a;
	}
	lld ans;
	s1 -= m1;
	s2 -= m2;
	s3 -= m3;
	lld s = s1 + s2 + s3 + m1 + m2 + m3;
	ans = s - 2 * (m1 + s1);
	ans = max(ans, s - 2 * (m2 + s2));
	ans = max(ans, s - 2 * (m3 + s3));
	ans = max(ans, s - 2 * (m1 + m2));
	ans = max(ans, s - 2 * (m2 + m3));
	ans = max(ans, s - 2 * (m3 + m1));
	cout << ans << endl;
}