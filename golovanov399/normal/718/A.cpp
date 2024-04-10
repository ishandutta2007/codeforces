#include <bits/stdc++.h>

#define itn int
#define LL long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(x) (x).begin(), (x).end()

using namespace std;

inline int nxt(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){

	int n = nxt(), t = nxt();
	string s;
	cin >> s;
	int i = 0;
	while (s[i] != '.') {
		i++;
	}
	i++;
	while (i < n && s[i] <= '4') {
		i++;
	}
	if (i == n) {
		cout << s << "\n";
		return 0;
	}
	int end = n;
	while (t) {
		if (s[i] <= '4') {
			break;
		}
		t--;
		end = i;
		i--;
		while (s[i] != '.') {
			s[i]++;
			if (s[i] == '9' + 1) {
				end = i;
				i--;
			} else {
				break;
			}
		}
		if (s[i] == '.') {
			end = i;
			i--;
			while (i >= 0) {
				s[i]++;
				if (s[i] == '9' + 1) {
					s[i] = '0';
					i--;
				} else {
					break;
				}
			}
			if (i < 0) {
				s = '1' + s;
				end++;
			}
			break;
		}
	}

	cout << s.substr(0, end) << "\n";

	return 0;
}