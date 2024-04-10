#include <iostream>

using namespace std;

int main() {
	int noCnt = 0;
	for (int i = 0; i < 10; i++) {
		cout << i << endl;
		string s; getline(cin, s);
		if (s == "no") {
			noCnt++;
		}
		if (
			noCnt == 4 || 
			s == "cool" || s == "not bad" || s == "great!" ||
			s == "don\'t think so" || s == "don\'t touch me!"
		) {
			cout << "normal" << endl;
			return 0;
		}
		if (
			s == "terrible" || s == "worse" || s == "no way" ||
			s == "are you serious?" || s == "go die in a hole" ||
			s == "don\'t even"
		) {
			cout << "grumpy" << endl;
			return 0;
		}
	}
	cout << "grumpy" << endl;
	return 0;
}