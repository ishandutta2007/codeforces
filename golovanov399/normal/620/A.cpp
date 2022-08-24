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

	int x = nxt(), y = nxt();
	long long xx = nxt(), yy = nxt();
	xx -= x;
	yy -= y;
	cout << max(abs(xx), abs(yy)) << "\n";

	return 0;
}