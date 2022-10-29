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
#define db(x) cout << #x << " = " << x << endl

using namespace std;

typedef long long ll;
typedef long double ld; 

const ld pi = acos(-1.0);
const ld eps = 1e-8;
const int INF = 1E9;		
const int MAXN = 4444;

struct child {
	int v, d, p, id;

	child() {};	
};

int n;
child a[MAXN];
int died[MAXN];
queue<int> q;
vi ans;

int main() {
	
	cin >> n;
	forn(i, n) {
		scanf("%d%d%d", &a[i].v, &a[i].d, &a[i].p);
		a[i].id = i;
		died[i] = 0;
	}
	
	for (int i = 0; i < n; i++) {
		if (died[i])
			continue;
			
		ans.pb(a[i].id);

		int dec = a[i].v;
		for (int j = i + 1; j < n && dec > 0; j++) {
			if (died[j])
				continue;

			a[j].p -= dec;
			if (a[j].p < 0) {
				died[j] = 1;
				q.push(j);
			}
			dec--;
		}
		
		while (!q.empty()) {
			int id = q.front();
			q.pop();
			
			dec = a[id].d;
			for (int j = id + 1; j < n && dec > 0; j++) {
				if (died[j])
					continue;

				a[j].p -= dec;
				if (a[j].p < 0) {
					died[j] = 1;
					q.push(j);
				}
			}	
		}
	}
	
	cout << ans.size() << '\n';
	forn(i, ans.size())
		printf("%d ", ans[i] + 1);	

	return 0;
}