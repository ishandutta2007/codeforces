#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

//#define DEBUG
//#define USE_MAGIC_IO

#define ll long long
#define pii pair<int,int>
#define pdd pair<double,double>
#define ldouble long double
#define nl '\n'
const ll MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;

int main() {
	ios::sync_with_stdio(0); 
	cin.tie(0); cout.tie(0);

	char type = '\0';
	bool kill;
	vector<char> ans;
	char s[3001];
	scanf("%s", s);
	int count = 0;
	for (int i = 0; s[i] != '\0'; i++) {
		if (s[i] != 'a' && s[i] != 'e' && s[i] != 'o' && s[i] != 'i' && s[i] != 'u') {
			if (!count) {
				type = s[i];
				kill = false;
			} else {
				if (type != s[i])
					kill = true;
			}
			count++;
		}
		else 
			count = 0;
		if (count > 2) {
			if (kill) {
				ans.push_back(' ');
				count = 1;
				type = s[i];
				kill = false;
			}
		}
		ans.push_back(s[i]);
	}
	for (char c: ans) {
		cout << c;
	} cout << endl;

	return 0;
}