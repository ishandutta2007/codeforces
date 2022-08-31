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

	int a, b, c;
	cin >> a >> b >> c;
	vector<char> ok(11111);
	ok[0] = 1;
	for (int i = 1; i <= c; i++){
		if (i >= a)
			ok[i] |= ok[i - a];
		if (i >= b)
			ok[i] |= ok[i - b];
	}

	if (ok[c])
		cout << "Yes\n";
	else
		cout << "No\n";

	return 0;
}