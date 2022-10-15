#include <iostream>

using namespace std;

inline void farm(int offs) {
	cout << 'X' << string(256 * 5 - 2, '.') << 'X' << endl;
	cout << string(256 * 5, '.') << endl;
	for (int i = 0; i < 256; i++) {
		if (i < offs) {
			cout << "..X..";
		} else {
			cout << ".....";
		}
	}
	cout << endl;
	cout << 'X' << string(256 * 5 - 2, '.') << 'X' << endl;
	cout << 'X' << string(256 * 5 - 1, '.') << endl;
	cout << string(256 * 5, '.') << endl;
	
}

int main() {
	string s; cin >> s;
	uint8_t kur = 0;
	for (char c: s) {
		farm((uint8_t)((uint8_t)kur - c));
		kur = c;
	}
	return 0;
}