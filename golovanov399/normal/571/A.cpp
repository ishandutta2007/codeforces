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

	int a = nxt(), b = nxt(), c = nxt(), l = nxt();
	long long ans = 0;
	for (int i = 0; i < 3; i++){

		int m = max(a + b - c, 0);
		if (m <= l){
			int n = l - m;
			for (int j = 0; j <= n; j++){
				ans += 1ll * (min(j, l + c - a - b - j) + 1) * (min(j, l + c - a - b - j) + 2) / 2;
			}
		}
		
		swap(a, b);
		swap(b, c);
	}
	long long v = 0;
	for (int i = 0; i <= l; i++){
		v += 1ll * (i + 1) * (i + 2) / 2;
	}
	cout << v - ans << "\n";

	return 0;
}