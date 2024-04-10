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

template <class T> struct min_stack : public stack<T> {
  stack<T> mins; // vals stored in stack inherited from the STL stack
  int mins_top() { return (mins.empty() ? INF : mins.top()); }
  void push(int x) { mins.push(min(x, mins_top())); stack<T>::push(x); }
  int pop() { mins.pop(); int x=stack<T>::top(); stack<T>::pop(); return x; }
  int minimum() { return mins_top(); } };
// Has all standard queue operations, as well as a minimum function, which gives
// the minimum element in the queue in O(1) time. Similar for min_stack above.
// Application: Sliding window RMQs
template <class T> struct min_queue { min_stack<T> in, out;
  void refill() { if (out.empty()) while (!in.empty()) out.push(in.pop()); }
  void push(int x) { in.push(x); }
  int pop() { refill(); return out.pop(); }
  int front() { refill(); return out.top(); }
  bool empty() { return in.empty() && out.empty(); }
  int minimum() { return min(in.minimum(), out.minimum()); }
};

const int N = 3000+1;
int g[N][N], h[N][N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);

	int n, m, a, b;
	cin >> n >> m >> a >> b;

	int x, y, z;
	cin >> g[0][0] >> x >> y >> z;
	For(i,n) {
		For(j,m) {
			if (j>0) {
				g[i][j] = ((ll)g[i][j-1]*x + y) % z;
			} else if (i>0) {
				g[i][j] = ((ll)g[i-1][m-1]*x + y) % z;
			}
		}
	}

	For(i,n) {
		min_queue<int> cur;
		For(j,b) {
			cur.push(g[i][j]);
		}
		h[i][0] = cur.minimum();
		For(j,m-b) {
			cur.pop();
			cur.push(g[i][j+b]);
			h[i][j+1] = cur.minimum();
		}
	}

	ll ans = 0;
	For(j,m-b+1) {
		min_queue<int> cur;
		For(i,a) {
			cur.push(h[i][j]);
		}
		ans += cur.minimum();
		For(i,n-a) {
			cur.pop();
			cur.push(h[i+a][j]);
			ans += cur.minimum();
		}
	}
	cout << ans << nl;

	return 0;
}