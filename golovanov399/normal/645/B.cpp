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

	int n = nxt(), k = nxt();
	long long ans = 0;
	int cur = 2 * (n - 2) + 1;
	for (int i = 0; i < k && i < n / 2; i++){
		ans += cur;
		cur -= 4;
	}

	cout << ans << "\n";

	return 0;
}