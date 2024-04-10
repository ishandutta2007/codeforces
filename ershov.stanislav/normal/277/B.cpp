#include <iostream>
#include <vector>

using namespace std;

int n, m;

int main() {
	cin >> n >> m;
	if (m==3) {
		switch(n) {
		case 3: cout << "0 0\n3 0\n0 3"; break;
		case 4: cout << "0 0\n3 0\n0 3\n 1 1"; break;
		case 5:
		case 6:
			cout << "-1"; break;
		}
		return 0;
	}
	for (int i=0; i<m; i++) cout << i-m << ' ' << i*i << endl;
	for (int i=1; i<=n-m; i++) cout << i << ' ' << -(n-m-i)*(n-m-i)-1 << endl;
	return 0;
}