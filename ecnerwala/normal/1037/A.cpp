#include<bits/stdc++.h>
using namespace std;

int main() {
	int N; cin >> N;
	int r = 0;
	while (N >= (1ll << r)) r++;
	cout << r << '\n';
	return 0;
}