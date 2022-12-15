#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

const int SIZE = 105;

string s[4];

int main(){
	int n, k;
	cin >> n >> k;
	for(int i = 0; i < 4; i++) {
		s[i] = string(n, '.');
	}
	if(k % 2) {
		s[1][n/2] = '#';
		k--;
		for(int i = 1; i <= (n - 2)/2 && k; i++) {
			s[1][n/2+i] = '#';
			s[1][n/2-i] = '#';
			k -= 2;
		}
		for(int i = 1; i <= (n - 2)/2 && k; i++) {
			s[2][n/2+i] = '#';
			s[2][n/2-i] = '#';
			k -= 2;
		}
	} else {
		for(int i = 1; i <= k/2; i++) {
			s[1][i] = '#';
			s[2][i] = '#';
		}
	}
	cout << "YES\n";
	for(int i = 0; i < 4; i++) cout << s[i] << '\n';
	return 0;
}