#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector <bool> used(16384);
	cout << "? ";
	int cnt = 0;
	for (int i = 0; i < 16384; i++) {
		if ((i & 127) == 127) {
			cout << i << " ";
			used[i] = true;
			cnt++;
		}
		if (cnt == 100)
			break;
	}
	cout << endl;
	cout.flush();
	int a;
	cin >> a;
	cout << "? ";
	for (int i = 0; i < 16384; i++) {
		if (used[i])
			continue;
		if ((i & 16256) == 16256) {
			cout << i << " ";
			cnt++;
		}
		if (cnt == 200)
			break;
	}
	cout << endl;
	cout.flush();
	int b;
	cin >> b;
	cout << "! " << ((a & 127) xor 127) + ((b & 16256) xor 16256) << endl;
	return 0;
}