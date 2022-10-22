#include <string>
#include <iostream>

using namespace std;

string s;
int k, i;

int main() {
	cin >> s;
	for (i = 0; i < (int) s.size(); ++i)
		if (s[i] >= 'a' && s[i] <= 'z')
			++k;
	if (k >= s.size() - k)
		for (i = 0; i < (int) s.size(); ++i)
			if (s[i] >= 'A' && s[i] <= 'Z')
				s[i] += 'a' - 'A';
			else;
	else
        for (i = 0; i < (int) s.size(); ++i)
			if (s[i] >= 'a' && s[i] <= 'z')
				s[i] -= 'a' - 'A';
			else;  
	cout << s;
}