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

int m[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main(){

	vector<string> ms = {"monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"};
	string s, t;
	cin >> s >> t;
	int x = find(all(ms), s) - ms.begin();
	int y = find(all(ms), t) - ms.begin();
	for (int i = 0; i < 11; i++) {
		if ((m[i] + x) % 7 == y) {
			puts("YES");
			return 0;
		}
	}

	puts("NO");

	return 0;
}