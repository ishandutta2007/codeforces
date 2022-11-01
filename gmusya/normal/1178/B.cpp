#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	string s;
	cin >> s;
	vector <long long int> a;
	long long int k = 0;
	for (long long int i = 0; i < s.size(); i++) {
		if (s[i] == 'o') {
			a.push_back(k);
			k = 0;
		}
		if (s[i] == 'v') {
			k++;
		}
	}
	a.push_back(k);
	for (long long int i = 0; i < a.size(); i++) if (a[i] > 0) a[i]--;
	vector <long long int> b(a.size());
	b[0] = a[0];
	long long int sum = 0;
	for (long long int i = 1; i < a.size(); i++) b[i] = b[i - 1] + a[i];
	for (long long int i = 0; i < b.size(); i++) sum += (b[b.size() - 1] - b[i]) * b[i];
	cout << sum;
	return 0;
}