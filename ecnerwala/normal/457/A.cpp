#include<bits/stdc++.h>

using namespace std;

vector<int> normalize(string s) {
	vector<int> res;
	for(int i = 0; i < int(s.size()); i++) {
		int d = int(s.size()) - i - 1;
		int v = s[i] - '0';
		if(v) {
			while(!res.empty() && res.back() == d + 1) {
				res.pop_back();
				d += 2;
			}
			res.push_back(d);
		}
	}
	return res;
}

int main() {
	string a, b;
	cin >> a >> b;
	vector<int> x, y; 
	x = normalize(a), y = normalize(b);
	if(x < y) {
		cout << '<' << '\n';
	} else if(x == y) {
		cout << '=' << '\n';
	} else {
		cout << '>' << '\n';
	}
	return 0;
}