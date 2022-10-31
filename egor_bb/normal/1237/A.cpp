#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define sz(x) (int) ((x).size())
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define fornr(i, n) for (int i = (n) - 1; i >= 0; --i)
#define forab(i, a, b) for (int i = (a); (i) < (b); ++i)
#define all(c) (c).begin(), (c).end()
 
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int last = 0;
    forn(i, n) {
    	int x;
    	cin >> x;
    	if (x % 2 == 0) {
			cout << x / 2 << '\n';
		} else {
			if (x > 0) {
				if (!last) {
					cout << x / 2 << '\n';
				} else {
					cout << x / 2 + 1 << '\n';
				}
			} else {
				if (!last) {
					cout << x / 2 - 1 << '\n';
				} else {
					cout << x / 2 << '\n';
				}
			}
			last = 1 - last;
		}
    } 
    return 0;
}