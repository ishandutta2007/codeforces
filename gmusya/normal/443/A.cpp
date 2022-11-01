#include <iostream>
#include <vector>
#include <set>
#include <string>

using namespace std;

int main() {
	string s;
	getline(cin, s);
	set <char> x;
	for (int i = 1; i < s.size() - 1; i += 3) 
		x.insert(s[i]);
	cout << x.size();
	return 0;
}