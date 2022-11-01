#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N, S;
	cin >> N >> S;
	if (N == 1) {
		if (S == 1) cout << "NO";
		else {
			cout << "YES" << endl;
			cout << S << endl;
			cout << S - 1 << endl;
		}
		return 0;
	}
	if (N * 2 > S) {
		cout << "NO";
		return 0;
	}
	cout << "YES" << endl;
	vector <int> a(N);
	a[0] = S - (N * 2);
	for (int i = 0; i < N; i++)
		a[i] += 2;
	for (int i = 0; i < N; i++)
		cout << a[i] << ' ';
	cout << endl;
	cout << S - 1;
	return 0;
}