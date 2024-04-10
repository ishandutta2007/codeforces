#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	vector <int> p(19);
	p[0] = 2;
	p[1] = 3;
	p[2] = 5;
	p[3] = 7;
	p[4] = 11;
	p[5] = 13;
	p[6] = 17;
	p[7] = 19;
	p[8] = 23;
	p[9] = 29;
	p[10] = 31;
	p[11] = 37;
	p[12] = 41;
	p[13] = 43;
	p[14] = 47;
	p[15] = 4;
	p[16] = 9;
	p[17] = 25;
	p[18] = 49;
	int cnt = 0;
	for (int i = 0; i < 19; i++) {
		cout << p[i] << endl;
		cout.flush();
		string s;
		cin >> s;
		cnt += (s == "yes");
	}
	if (cnt > 1) cout << "composite";
	else cout << "prime";
	return 0;
}