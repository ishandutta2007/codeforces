#include <iostream>
#include <string>

using namespace std;

int main() {
	string s;
	cin >> s;
	int leftAB = -1;
	int rightAB = s.size();
	int leftBA = -1;
	int rightBA = s.size();
	int bleftAB, brightAB, bleftBA, brightBA;
	for (int i = 0; i < s.size() - 1; i++) 
		if (s[i] == 'A' && s[i + 1] == 'B') {
			leftAB = i;
			bleftAB = i + 1;
			break;
		}
	for (int i = s.size() - 1; i > 0; i--)
		if (s[i] == 'B' && s[i - 1] == 'A') {
			rightAB = i - 1;
			brightAB = i;
			break;
		}
	for (int i = 0; i < s.size() - 1; i++)
		if (s[i] == 'B' && s[i + 1] == 'A') {
			leftBA = i + 1;
			bleftBA = i;
			break;
		}
	for (int i = s.size() - 1; i > 0; i--)
		if (s[i] == 'A' && s[i - 1] == 'B') {
			rightBA = i;
			brightBA = i - 1;
			break;
		}
	if (leftAB == -1 || leftBA == -1) {
		cout << "NO";
		return 0;
	}
	if ((leftAB != leftBA && bleftAB != bleftBA) || (leftAB != rightBA && bleftAB != brightBA) || (rightAB != leftBA && brightAB != bleftBA) || (rightAB != rightBA && brightAB != brightBA))
		cout << "YES";
	else
		cout << "NO";
	return 0;
}