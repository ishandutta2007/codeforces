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

	long long s, x;
	cin >> s >> x;
	long long t = s ^ x;
	if (t & 1){
		puts("0");
		return 0;
	}
	t >>= 1;

	long long ans = 1;

	char k = 0;
	for (long long i = 1; i <= s || i <= x; i *= 2){
		if (t & i){
			if (x & i){
				if (k)
					ans *= 2;
				else
					ans *= 0;
			}
		} else {
			if (x & i){
				if (!k)
					ans *= 2;
				else
					ans *= 0;
			}
		}
		if (t & i)
			k = 1;
		else
			k = 0;
	}
	if (s == x)
		ans -= 2;

	cout << ans << "\n";

	return 0;
}