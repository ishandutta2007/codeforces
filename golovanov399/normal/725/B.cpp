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

	long long n;
	char c;
	scanf("%I64d%c", &n, &c);

	vector<int> sec = {3, 4, 5, 2, 1, 0};
	long long block = (n - 1) / 4;
	cout << block * 16 + (n - 1) % 2 * 7 + sec[c - 'a'] + 1 << "\n";

	return 0;
}