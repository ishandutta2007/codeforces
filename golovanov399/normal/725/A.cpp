#include <bits/stdc++.h>

#define itn int
#define LL long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(x) (x).begin(), (x).end()

#define sz(x) (int)((x).size())

using namespace std;

inline int nxt(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){

	int n = nxt();
	string s;
	cin >> s;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '<') {
			ans += 1;
		} else {
			break;
		}
	}
	reverse(all(s));
	for (int i = 0; i < n; i++) {
		if (s[i] == '>') {
			ans += 1;
		} else {
			break;
		}
	}

	printf("%d\n", ans);

	return 0;
}