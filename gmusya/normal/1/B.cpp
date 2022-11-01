#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	while (n--) {
		string s;
		cin >> s;
		int cnt = 0;
		int type;
		if (s[0] != 'R')
			type = 1;
		else {
			if (s[1] >= 'A' && s[1] <= 'Z')
				type = 1;
			else {
				type = 1;
				for (int i = 2; i < s.size(); i++)
					if (s[i] == 'C')
						type = 2;
			}
		}
		if (type == 1) {
			int stolb = 0, strok = 0, i = 0;
			for (i = 0; i < s.size() && s[i] >= 'A' && s[i] <= 'Z'; i++) {
				stolb = stolb * 26 + s[i] - 'A' + 1;
			}
			for (; i < s.size(); i++)
				strok = strok * 10 + s[i] - '0';
			cout << "R" << strok << "C" << stolb << endl;
		}
		if (type == 2) {
			int stolb = 0, strok = 0, i = 0;
			for (i = 1; i < s.size() && s[i] >= '0' && s[i] <= '9'; i++)
				stolb = stolb * 10 + s[i] - '0';
			i++;
			for (; i < s.size(); i++)
				strok = strok * 10 + s[i] - '0';
			vector <char> ans;
			while (strok > 0) {
				strok--;
				ans.push_back(strok % 26 + 'A');
				strok /= 26;
			}
			reverse(ans.begin(), ans.end());
			for (auto now : ans)
				cout << now;
			cout << stolb << endl;
		}
	}
	return 0;
}