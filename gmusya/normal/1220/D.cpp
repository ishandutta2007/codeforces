#include <iostream>
#include <vector>
#include <math.h>

using namespace std;
long long int n;
vector <long long int> a;
vector <long long int> answer;

void rec(vector <long long int> &c, long long int n) {
	vector <long long int> d;
	if (c.size() > 0) {
		long long int z = 0;
		for (long long int i = 0; i < n; i++) {
			if (c[i] % 2 == 0) d.push_back(c[i] / 2);
			else z++;
		}
		answer.push_back(z);
		rec(d, n - z);
	}
}

int main() {
	cin >> n;
	a.resize(n);
	for (long long int i = 0; i < n; i++) cin >> a[i];
	rec(a, n);
	long long int shag = 0;
	for (long long int i = 0; i < answer.size(); i++) if (answer[i] > answer[shag]) shag = i;
	long long int z = pow(2, shag);
	cout << n - answer[shag] << endl;
	for (long long int i = 0; i < n; i++) if (a[i] % z != 0 || a[i] % (2 * z) == 0) cout << a[i] << " ";
	return 0;
}