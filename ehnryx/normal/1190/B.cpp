#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

#define For(i,n) for (int i=0; i<n; i++)
#define FOR(i,a,b) for (int i=a; i<=b; i++)
#define Down(i,n) for (int i=n-1; i>=0; i--)
#define DOWN(i,a,b) for (int i=b; i>=a; i--)

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ld,ld> pdd;
typedef complex<ld> pt;
typedef vector<pt> pol;
typedef vector<int> vi;

const char nl = '\n';
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-10;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const string First = "sjfnb";
const string Second = "cslnb";

const int N = 1e5+1;
int a[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);

	int n;
	cin >> n;

	For(i,n) {
		cin >> a[i];
	}
	sort(a, a+n);

	if (a[n-1] == 0) {
		cout << Second << nl;
		return 0;
	}

	if (n == 1) {
		if (a[0]%2 == 1) {
			cout << First << nl;
		} else {
			cout << Second << nl;
		}
		return 0;
	}

	bool bad = false;
	int cnt = 0;
	For(i,n-1) {
		if (a[i] == a[i+1]) {
			if (i>0 && a[i-1] == a[i]-1) bad = true;
			if (a[i] == 0) bad = true;
			cnt++;
		}
	}
	if (cnt>1) bad = true;

	ll par = 0;
	For(i,n) {
		par += a[i]-i;
	}
	if (par%2 == 0) bad = true;

	if (bad) {
		cout << Second << nl;
	} else {
		cout << First << nl;
	}

	return 0;
}