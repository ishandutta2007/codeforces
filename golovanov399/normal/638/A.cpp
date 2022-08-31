#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define x first
#define y second
#define itn int

using namespace std;

inline int nxt(){
	int x;
	scanf("%d", &x);
	return x;
}

void solve(){
	int n = nxt(), a = nxt();
	if (a % 2 == 1)
		cout << a / 2 + 1 << "\n";
	else
		cout << n / 2 - a / 2 + 1 << "\n";
}

int main(){

	solve();

	return 0;
}