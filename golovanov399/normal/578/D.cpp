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

const int N = 111111;
char s[N];
int a[N];

int main(){

	itn n = nxt(), m = nxt();
	scanf("\n%s", s);

	long long cnt = 0;
	for (int i = 1; i < n; i++){
		if (s[i] != s[i - 1])
			cnt += 1ll * n * (m - 1);
	}

	for (int i = 0; i < n; i++){
		if (i == 0 || i == 1)
			a[i] = 1;
		else {
			if (s[i] == s[i - 2])
				a[i] = a[i - 2] + 1;
			else
				a[i] = 1;
		}
	}

	long long ans = cnt;
	cnt = 0;
	for (int i = 1; i < n; i++){
		if (s[i] != s[i - 1]){
			if (a[i] <= a[i - 1])
				cnt += a[i] * 2 - 1;
			else
				cnt += a[i - 1] * 2;
		}
	}
	ans -= cnt;

	ans += 1ll * n * (m - 1);
	cout << ans << "\n";

	return 0;
}