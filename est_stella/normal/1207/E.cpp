#include<bits/stdc++.h>
using namespace std;

int x;
int ans;

int main() {
	cout << "? ";
	for(int i=1; i<=100; i++) {
		cout << i << " ";
	}
	cout << endl << flush;

	cin >> x;
	if(x == -1) return 0;

	x >>= 7;
	x <<= 7;
	ans |= x;

	cout << "?" << " ";
	for(int i=1; i<=100; i++) {
		cout << (i<<7) << " ";
	}
	cout << endl << flush;

	cin >> x;
	if(x == -1) return 0;

	x &= 127;
	ans |= x;

	cout << "! ";
	cout << ans << endl << flush;
}