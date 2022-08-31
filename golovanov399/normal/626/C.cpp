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

	int n = nxt(), m = nxt();
	if (n < m){
		cout << 3 * m << "\n";
	} else if (n > 3 * m){
		cout << 2 * n << "\n";
	} else {
		int s = n + m;
		cout << (s / 4) * 6 + (vector<int>({0, 2, 3, 4})[s % 4]) << "\n";
	}

	return 0;
}