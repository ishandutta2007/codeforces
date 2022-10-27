#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, h;
	cin >> n >> h;
	for(int i = 1; i < n; i++){
		cout << setprecision(30) << sqrt(1.0*i/n)*h << ' ';
	}
	cout << '\n';

	return 0;
}