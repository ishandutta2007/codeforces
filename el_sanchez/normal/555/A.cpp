#include <bits/stdc++.h>
#include <iostream>
#include <string>

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define forab(i, k, n) for (int i = (int)(k); i < (int)(n); i++)
#define forba(i, n, k) for (int i = (int)(n) - 1; i >= (int)(k); i--)

#define vi vector<int>
#define pii pair<int, int>
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x)*(x))
#define X first
#define Y second                    
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef double ld; 

const ld pi = acos(-1.0);
const ld eps = 1e-9;
const int INF = 1E9;
const int MAXN = 100500;
    
int n, k, l, ans;
vi a[MAXN];

int main() {

	cin >> n >> k;
	ans = n - 1;
	forn(i, k) {
		scanf("%d", &l);
		a[i].resize(l);
		forn(j, l) {
			scanf("%d", &a[i][j]);
			if (j != 0)
				ans++;
		}
	}
	
	forn(i, k) {
		if (a[i][0] == 1) {
			forab(j, 1, a[i].size()) {
				if (a[i][j] == j + 1)
					ans -= 2;
				else
					break;	
			}
		}		}    
	cout << ans;
	
	return 0;
}