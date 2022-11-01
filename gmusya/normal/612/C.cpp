#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

int main() {
	string s;
	cin >> s;
	stack <char> c;
	int cnt = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(' || s[i] == '[' || s[i] == '{' || s[i] == '<') {
			c.push(s[i]);
			continue;
		}
		if (c.empty()) {
			cout << "Impossible";
			return 0;
		}
		char x = c.top();
		c.pop();
		cnt++;
		if ((x == '(' && s[i] == ')') || (x == '[' && s[i] == ']') || (x == '{' && s[i] == '}') || (x == '<' && s[i] == '>'))
			cnt--;
	}
	if (!c.empty()) {
		cout << "Impossible";
		return 0;
	}
	cout << cnt;
	return 0;
}