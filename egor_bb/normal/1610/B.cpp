#include <bits/stdc++.h> 
 
using namespace std;
 
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define sz(x) (int) ((x).size()) 
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define fornr(i, n) for (int i = (n) - 1; i >= 0; --i)
#define forab(i, a, b) for (int i = (a); i < (b); ++i)
#define all(c) (c).begin(), (c).end() 
 
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

bool checkPalindrome(vi &a, int l, int r, int x) {
	while(l < r) {
		if (a[l] == x) l++;
		else if (a[r] == x) r--;
		else if (a[l] != a[r]) {
			return false;
		} else {
			l++;
			r--;
		}
	}
	return true;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		forn(i, n) {
			cin >> a[i];
		}
		int l = 0, r = n - 1;
		while(l < r) {
			if (a[l] == a[r]) {
				l++, r--;
			} else {
				break;
			}
		}
		if (l >= r) {
			cout << "YES\n";
		} else if (checkPalindrome(a, l, r, a[l]) || checkPalindrome(a, l, r, a[r])) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
	return 0;
}