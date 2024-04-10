#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <ctime>
#include <random>
#include <cmath>
#include <bitset>
#include <iomanip>
#include <list>

using namespace std;

typedef long long ll;

vector <string> bad = {"don't even", "are you serious?", "worse", "terrible", "no way", "go die in a hole"};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	for (int i = 0; i < 4; ++i) {
		cout << i << endl;
		string s;
		getline(cin, s);
		for (auto t : bad) {
			if (s == t) {
				cout << "grumpy" << endl;
				return 0;
			}
		}
	}
	cout << "normal" << endl;
}