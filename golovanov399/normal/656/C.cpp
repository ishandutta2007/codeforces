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

	string s;
	cin >> s;
	int res = 0;
	for (char c : s){
		int q = ('@' < c && '[' > c);
		int w = ('`' < c && '{' > c);
		int e = 0;
		if (c >= 'a' && c <= 'z')
			e = c - 'a' + 1;
		if (c >= 'A' && c <= 'Z')
			e = c - 'A' + 1;
		res += e * (q - w);
	}

	cout << res << "\n";

	return 0;
}