#include <bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin >> s;
	int len = s.length();
	s += char(1), s += char(1), s += char(1);
	bool pd = 1;
	putchar(s[0]);
	for (int i = 1; i < len; i++){
		if (i != len - 3 && s[i] == 'd' && s[i + 1] == 'o' && s[i + 2] == 't'){
			putchar('.'), i += 2;
			continue;
		}
		if (pd && s[i] == 'a' && s[i + 1] == 't'){
			putchar('@'), i++, pd = 0;
			continue;
		}
		putchar(s[i]);
	}
	putchar('\n');
	return 0;
}