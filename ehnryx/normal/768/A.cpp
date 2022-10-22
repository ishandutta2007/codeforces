#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ll total, mincount, maxcount, min, max, temp;
	cin >> total;
	cin >> temp; min = max = temp; mincount = maxcount = 1;
	for (int i = 1; i < total; i++) {
		cin >> temp;
		if (temp < min) {
			min = temp; mincount = 0;
		}
		if (temp > max) {
			max = temp; maxcount = 0;
		}
		if (temp == min)
			mincount++;
		if (temp == max)
			maxcount++;
	}	
	if (mincount + maxcount >= total)
		cout << 0 << endl;
	else 
		cout << total - mincount - maxcount << endl;
	return 0;
}