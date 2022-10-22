#include <bits/stdc++.h>
using namespace std;

int main() {
	int curr = 0;
	string stone, instr;
	cin >> stone >> instr;
	for (int i = 0; i < instr.size(); i++) {
		if (instr[i] == stone[curr])
			curr++;
	}
	cout << curr+1 << endl;
	return 0;
}