#include <iostream>
#include <string>

using namespace std;

int vowel(char x) {
	if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u')
		return 1;
	return 0;
}

int read() {
	string alpha; getline(cin, alpha);
	int answer = 0;
	for (int i = 0; i < alpha.size(); ++i)
		answer += vowel(alpha[i]);
	return answer;
}

int main() {
	int a = read(), b = read(), c = read();
	if (a == 5 && b == 7 && c == 5)
		cout << "YES";
	else
		cout << "NO";
}