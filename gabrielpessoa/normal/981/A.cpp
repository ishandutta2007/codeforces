#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int ms = 1e4+5;

bool isPalindrome(string &s, int i, int j) {
	if(i >= j) return true;
	return s[i] == s[j] && isPalindrome(s, i + 1, j - 1);
}

int main(){
	string s;
	int best = 0;
	cin >> s;
	for(int i = 0; i < s.size(); i++) {
		for(int j = i; j < s.size(); j++) {
			if(!isPalindrome(s, i, j)) {
				best = max(best, j - i + 1);
			}
		}
	}
	cout << best << endl;
	return 0;
}