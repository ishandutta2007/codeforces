#include <bits/stdc++.h>

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
typedef long double ld; 

const ld pi = acos(-1.0);
const ld eps = 1e-9;
const int INF = 1E9;        
const int MAXN = 200500;
                      
int n;
int a[MAXN], l[MAXN], r[MAXN];
int ans[MAXN];
vi st;

int main() {

	cin >> n;
	forn(i, n)
		cin >> a[i];
		
	st.pb(0);
	for (int i = 1; i < n; i++) {
		while (!st.empty() && a[st.back()] > a[i]) {
			r[st.back()] = i - 1;
			st.pop_back();
		}
		st.pb(i);  	}
	while (!st.empty()) {
		r[st.back()] = n - 1;
		st.pop_back();
	}

	st.pb(n - 1);
	for (int i = n - 2; i >= 0; i--) {
		while (!st.empty() && a[st.back()] > a[i]) {
			l[st.back()] = i + 1;
			st.pop_back();
		}
		st.pb(i);  	
	}
	
	while (!st.empty()) {
		l[st.back()] = 0;
		st.pop_back();
	}
	
	forn(i, n) {
		int len = r[i] - l[i] + 1;
		ans[len] = max(ans[len], a[i]);	
	}
	
	for (int i = n - 1; i >= 1; i--)
		ans[i] = max(ans[i], ans[i + 1]);
	for (int i = 1; i <= n; i++)
		cout << ans[i] << ' ';
	cout << '\n';
			return 0;
}