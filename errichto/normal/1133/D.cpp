#include <bits/stdc++.h>
using namespace std;



int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	assert(__gcd(6, 0) == 6);
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for(int i = 0; i < n; ++i) {
		cin >> b[i];
	}
	int answer = 0;
	map<pair<int,int>, int> freq;
	for(int i = 0; i < n; ++i) {
		if(a[i] == 0) {
			if(b[i] == 0) {
				answer++;
			}
		}
		else {
			int g = __gcd(abs(a[i]), abs(b[i]));
			a[i] /= g;
			b[i] /= g;
			if(a[i] < 0) {
				a[i] *= -1;
				b[i] *= -1;
			}
			assert(a[i] > 0 && __gcd(a[i], abs(b[i])) == 1);
			// x / y is irreducible if y > 0 and (abs(x), y) are coprime
			++freq[{-b[i], a[i]}];
			// double x = (double) -b[i] / a[i];   -7 / 2    
			// ++freq[x];
		}
	}
	int most_freq = 0;
	for(pair<pair<int,int>,int> p : freq) {
		most_freq = max(most_freq, p.second);
	}
	cout << most_freq + answer << "\n";
}




// cannonical representation

// asdqaa -> aaadqs

// ....