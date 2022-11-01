#include <iostream>
#include <vector>
#include <string>

using namespace std;

int min(int a, int b) {
	int k = a;
	if (k > b) k = b;
	return k;
}
vector <int> a;
vector <bool> answer;
string s;

int main() {
	cin >> s;
	int n = s.size();
	a.resize(n);
	answer.resize(n);
	a[0] = s[0] - 'a';
	for (int i = 1; i < n; i++) a[i] = min(a[i - 1], s[i] - 'a');
	answer[0] = 0;
	for (int i = 1; i < n; i++) if (s[i] - 'a' > a[i - 1]) answer[i] = 1;
	for (int i = 0; i < n; i++) {
		if (answer[i]) cout << "Ann" << endl;
		else cout << "Mike" << endl;
	}
	return 0;
}