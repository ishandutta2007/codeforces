#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define End return 0; }
#define of ios::sync_with_stdio(0); cin.tie(0);
#define story int main() {
#define The

The story of THE_HARDEST_PROBLEM_EVER__JUST_LOOK_AT_THOSE_WRONG_SUBMISSIONS:

int ans = 0;
int count = 0;
int n;
string s;
cin >> n;
getline(cin, s);
getline(cin, s);
for (int i = 0; i < n; i++) {
	if ('A' <= s[i] && s[i] <= 'Z')
		count++;
	if (isspace(s[i])) {
		ans = max(count, ans);
		count = 0;
	}
}
ans = max(count, ans);
cout << ans << endl;

The End