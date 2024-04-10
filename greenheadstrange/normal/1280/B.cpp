#include <bits/stdc++.h>
using namespace std;
#define maxn 100010
#define ll long long
#define db double
#define vi vector<int>
#define pb push_back
#define mod 998244353
#define fi first
#define pi pair<int, int>
#define se second
#define mp make_pair
ll ksm(ll a, ll b) {
   if (!b) return 1;
   ll ns = ksm(a, b >> 1);
   ns = ns * ns % mod;
   if (b & 1) ns = ns * a % mod;
   return ns;
}
// head
char inp[65][65];
int check(int a, int b) {
	if (inp[a][b] == 'A') return 1;
	return 0;
}
int cal(int a, int b, int c, int d) {
	int res = 0;
	for (int i = a; i <= b; i++)
		for (int j = c; j <= d; j++)
			res += check(i, j);
	return res;
}
int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int r, c;
		scanf("%d%d", &r, &c);
		bool fl[2] = {0, 0};
		for (int i = 1; i <= r; i++)
			scanf("%s", inp[i] + 1);
		int ans = 5;
		if (cal(1, r, 1, c) == r * c) 
			ans = 0;
		else {
			if (cal(1, 1, 1, c) == c || cal(r, r, 1, c) == c || cal(1, r, 1, 1) == r || cal(1, r, c, c) == r) 
				ans = 1;
			else {
				if (check(1, 1) || check(1, c) || check(r, 1) || check(r, c)) ans = 2;
				else {
					bool fl = 0;
					for (int i = 1; i <= r; i++)
						if (cal(i, i, 1, c) == c) fl = 1;
					for (int i = 1; i <= c; i++)
						if (cal(1, r, i, i) == r) fl = 1;
					if (fl) ans = 2;
					else if (cal(1, 1, 1, c) + cal(r, r, 1, c) + cal(1, r, 1, 1) + cal(1, r, c, c) != 0) ans = 3;
					else if (cal(1, r, 1, c)) ans = 4;
					else ans = -1;
				}
			}
		}
		if (ans == -1) printf("MORTAL\n");
		else cout << ans << endl;
	}
	return 0;
}