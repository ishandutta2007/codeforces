#include<bits/stdc++.h>
using namespace std;

int main() {
	int N;
	cin >> N;
	if(N % 2 == 0) {
		cout << "white\n";
		cout << 1 << ' ' << 2 << '\n';
	} else {
		cout << "black\n";
	}
	return 0;
}