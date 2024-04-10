#include <iostream>
#include <vector>
#include <set>
#include <string>

using namespace std;

int main() {
	set <string> normal;
	normal.insert("great"), normal.insert("great!");
	normal.insert("don't think so"), normal.insert("dont think so");
	normal.insert("don't touch me"), normal.insert("dont touch me"), normal.insert("don't touch me!"), normal.insert("dont touch me!");
	normal.insert("not bad");
	normal.insert("cool");

	set <string> grumpy;
	grumpy.insert("are you serious?"), grumpy.insert("are you serious");
	grumpy.insert("don't even"), grumpy.insert("dont even");
	grumpy.insert("worse");
	grumpy.insert("no way");
	grumpy.insert("go die in a hole");
	grumpy.insert("terrible");

	int cnt = 0;
	for (int i = 0; i < 10; i++) {
		cout << i << endl;
		cout.flush();
		string s;
		getline(cin, s);
		if (normal.find(s) != normal.end()) {
			cout << "normal";
			return 0;
		}
		if (grumpy.find(s) != grumpy.end()) {
			cout << "grumpy";
			return 0;
		}
		if (s == "no") cnt++;
		if (cnt > 3) {
			cout << "normal";
			return 0;
		}
	}
	cout << "normal";
	return 0;
}