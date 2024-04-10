#include<iostream>
#include<string>
using namespace std;
int n;
int t[55];
string s[55];
int main() {
	int i;
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> t[i] >> s[i];
	}
	int wd = 10000;
	for (i = 0; i < n; i++) {
		if (wd == 10000 && s[i] != "South")break;
		if (wd == -10000 && s[i] != "North")break;
		if (s[i] == "North") {
			wd += t[i];
		}
		if (s[i] == "South") {
			wd -= t[i];
		}
		if (wd > 10000 || wd < -10000)break;
	}
	if (i == n&&wd == 10000)puts("YES");
	else puts("NO");
	return 0;
}