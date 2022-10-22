#include <bits/stdc++.h>
using namespace std;

int main() {
	int prev = 0;
	int n, state, temp, uni;
	cin >> n;
	state = 0;
	uni = true;
	while (n--) {
		cin >> temp;
		if (temp > prev && state != 0) {
			uni = false;
			break;
		}
		else if (temp == prev && state != 1) {
			if (state < 1)
				state = 1;
			else {
				uni = false;
				break;
			}
		}
		else if (temp < prev && state != 2) {
			if (state < 2)
				state = 2;
			else {
				uni = false;
				break;
			}
		}
		prev = temp;
	}
	if (uni) 
		cout << "YES" << endl;
	else 
		cout << "NO" << endl;
	return 0;
}