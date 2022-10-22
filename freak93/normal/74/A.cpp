#include <iostream>
#include <string>

using namespace std;

int main() {
	int N; cin >> N;
	int maxv = -10000;
	string answer = "";
	for (int i = 0; i < N; ++i) {
		string s; int p, m, a, b, c, d, e; cin >> s >> p >> m >> a >> b >> c >> d >> e;
		b = p * 100 - m * 50 + a + b + c + d + e;
		if (b > maxv)
			maxv = b, answer = s;
	}
	cout << answer;
}