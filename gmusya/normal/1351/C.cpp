#include <iostream>
#include <vector>
#include <set>
#include <string>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		string str;
		cin >> str;
		set <pair <pair <int, int>, pair <int, int>>> s;
		int oldx = 0, oldy = 0;
		for (int i = 0; i < str.size(); i++) {
			int newx = oldx, newy = oldy;
			if (str[i] == 'N') newy++;
			if (str[i] == 'S') newy--;
			if (str[i] == 'W') newx--;
			if (str[i] == 'E') newx++;
			pair <int, int> tmp1 = { oldx, oldy };
			pair <int, int> tmp2 = { newx, newy };
			if (tmp1 > tmp2) swap(tmp1, tmp2);
			s.insert({ tmp1, tmp2 });
			oldx = newx, oldy = newy;
		}
		int time = (s.size() * 5) + (str.size() - s.size());
		cout << time << '\n';
	}
	return 0;
}