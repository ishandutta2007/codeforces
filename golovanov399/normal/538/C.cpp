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

void panic(){
	puts("IMPOSSIBLE");
	exit(0);
}

int main(){

	int n = nxt(), m = nxt();

	int ans = 0;
	int D, H;
	for (int i = 0; i < m; i++){
		int d = nxt(), h = nxt();
		if (i == 0){
			ans = max(ans, h + d - 1);
		} else {
			if (abs(d - D) < abs(h - H))
				panic();
			ans = max(ans, (h + H + d - D) / 2);
		}
		D = d;
		H = h;
	}
	ans = max(ans, H + n - D);
	printf("%d\n", ans);

	return 0;
}