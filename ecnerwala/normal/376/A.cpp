#include<iostream>
#include<string>

using namespace std;

typedef long long ll;

int main() {
	string s;
	cin >> s;
	int center = 0;
	while(s[center] != '^') center++;
	ll l = 0;
	for(int i = 1; i <= center; i++) {
		char c = s[center - i];
		if(c == '=') continue;
		else l += i * (c - '0');
	} 
	for(int i = 1; i + center < s.size(); i++) {
		char c = s[center + i];
		if(c == '=') continue;
		else l -= i * (c - '0');
	}
	if(l == 0) cout << "balance\n";
	else if(l > 0) cout << "left\n";
	else cout << "right\n";
	return 0;
}