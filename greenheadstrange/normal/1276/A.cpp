#include <bits/stdc++.h>
#define ll long long
#define maxn 150010 /*rem*/
#define mod 998244353
#define db double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
ll ksm(ll a, ll b) {
   if (!b) return 1;
   ll ns = ksm(a, b >> 1);
   ns = ns * ns % mod;
   if (b & 1) ns = ns * a % mod;
   return ns;
}
char inp[maxn];
int res[maxn];
bool check(int pl, int tp) {
	if (tp == 0) return inp[pl] == 'o' && inp[pl + 1] == 'n' && inp[pl + 2] == 'e';
	else return inp[pl] == 't' && inp[pl + 1] == 'w' && inp[pl + 2] == 'o';
}
bool ct(int a) {
	if (a <= 1) return 0;
	return check(a - 2, 1) && check(a, 0);
}
int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		scanf("%s", inp);
		int l = strlen(inp);
		inp[l] = inp[l + 1] = inp[l + 2] = 's';
		int ans = 0;
		for (int i = 1; i < l - 1; i++) {
			bool fl = 0;
			if (i && (check(i - 1, 0) || check(i - 1, 1))) {
				if (!ct(i - 1) && !ct(i + 1)) fl = 1;
			}
			else if (ct(i)) fl = 1;
			if (fl) 
				res[ans++] = i + 1;
		}
		printf("%d\n", ans);
		for (int i = 0; i < ans; i++)
			printf("%d ", res[i]);
		printf("\n");
	}
	return 0;
}