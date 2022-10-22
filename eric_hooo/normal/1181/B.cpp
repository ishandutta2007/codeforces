#include <bits/stdc++.h>
using namespace std;

string s;

void chmin(string &a, string b){
	if (a == "") a = b;
	else {
		if (a.length() > b.length() || a.length() == b.length() && a > b) a = b;
	}
}

int c[100010];

string add(string a, string b){
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	memset(c, 0, sizeof(c));
	int len1 = a.length();
	int len2 = b.length();
	int len = max(len1, len2);
	for (int i = 0; i < len; i++){
		if (i < len1) c[i] += a[i] - '0';
		if (i < len2) c[i] += b[i] - '0';
		if (c[i] >= 10) c[i] -= 10, c[i + 1]++;
	}
	bool pd = 0;
	string ans = "";
	for (int i = len; i >= 0; i--){
		if (!pd && c[i] == 0 && i != 0) continue;
		ans += char(c[i] + '0');
		pd = 1;
	}
	return ans;
}

string ans;
int n;

void check(int tmp){
	int pos = tmp;
	while (pos < n && s[pos] == '0') pos++;
	if (pos != n) chmin(ans, add(s.substr(0, pos), s.substr(pos, n - pos)));
	pos = tmp;
	while (pos >= 0 && s[pos] == '0') pos--;
	if (pos != -1) chmin(ans, add(s.substr(0, pos), s.substr(pos, n - pos)));
}

int main(){
	cin >> n;
	cin >> s;
	if (n & 1) check(n / 2), check(n / 2 + 1);
	else check(n / 2);
	cout << ans << endl;
	return 0;
}