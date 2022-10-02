#include <cstdio>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
#include <queue>
#include <set>


using namespace std;


set<char> s;


int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	char c;
	while (scanf("%c", &c) == 1) {
		if (c >= 'a' && c <= 'z') {
			s.insert(c);
		}
	}
	cout << s.size() << endl;
	return 0;
}