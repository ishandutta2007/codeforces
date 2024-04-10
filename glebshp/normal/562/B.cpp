#include <bits/stdc++.h>

using namespace std;

#define forn(i,n) for (int i = 0; i < int(n); ++i)
#define ford(i,n) for (int i = int(n) - 1; i >= 0; ++i)
#define all(a) a.begin(), a.end()
#define sz(a) int(a.size())
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define ve vector
#define pa pair

typedef long double ld;
typedef long long ll;
typedef unsigned char uc;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef ve<int> vi;
typedef pa<int, int> pii;
typedef pa<int, ll> pil;
typedef pa<ll, int> pli;
typedef pa<ll, ll> pll;

template<typename A, typename B> bool umx (A &a, B b) {if (a < b) {a = b; return 1;} return 0;}
template<typename A, typename B> bool umn (A &a, B b) {if (b < a) {a = b; return 1;} return 0;}

const int N = 1000000;
int a[N + 1];
int d[N + 1];

int main () {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	memset(a, 0, sizeof a);
	int n;
	cin >> n;
	forn (i, n) {
		int x;
		scanf("%d", &x);
		a[x]++;
	}
	for (int i = N; i >= 1; --i) {
		d[i] = a[i];
		for (int j = 2 * i; j <= N; j += i) {
			umx(d[i], a[i] + d[j]);
		}
	}
	cout << d[1] << endl;
	return 0;
}