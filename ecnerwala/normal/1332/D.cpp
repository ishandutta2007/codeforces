#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int K; cin >> K;
	cout << 2 << ' ' << 3 << '\n';
	cout << (1<<17)+K << ' ' << (1<<17) << ' ' << 0 << '\n';
	cout << K << ' ' << (1<<17)+K << ' ' << K << '\n';

	return 0;
}