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
const ld eps = 1e-14;
const int INF = 1E9;		
const int MAXN = 100500;
const ll MOD = 1E9 + 9;
                       
int n;
pii a, cur2;
pair<int, pii> a1, a2;
map<pii, int> all;
int used[MAXN];
ll N[MAXN], ans;
set<pair<int, pii> > mi, mx;

int cnt(pii p) {
	if (all.find(p) == all.end())
		return INF;
	int c = 0;
	for (int i = -1; i <= 1; i++) {
		pii p2 = {p.X + i, p.Y - 1};
		if (all.find(p2) != all.end())
			c++;
	}
	return c;
}

void add(pii p) {
	mi.insert({all[p], p});
	mx.insert({-all[p], p});
}

void del(pii p) {
	if (all.find(p) == all.end())
		return;
		
	mi.erase({all[p], p});
	mx.erase({-all[p], p});
}

void rec(pii p) {
	pii np;
	for (np.X = p.X - 2; np.X <= p.X + 2; np.X++)
		for (np.Y = p.Y - 1; np.Y <= p.Y; np.Y++) {
			if (all.find(np) == all.end())
				continue;

			del(np);

			bool ok = 1;
			for (int i = -1; i <= 1; i++) {
				cur2 = {np.X + i, np.Y + 1};
				if (cnt(cur2) <= 1)
					ok = 0;
			}
			if (ok)
				add(np); 			
		}	  	
}

int main() {
                  
	cin >> n;
	
	N[0] = 1;
	for (int i = 1; i <= n; i++)
		N[i] = (N[i - 1] * n) % MOD;
		
	forn(i, n) {
		scanf("%d%d", &a.X, &a.Y);
		all[a] = i;
	}
	
	for (auto b: all) {
		pii cur = b.X;

		bool ok = 1;
		for (int i = -1; i <= 1; i++) {
			cur2 = {cur.X + i, cur.Y + 1};
			if (cnt(cur2) <= 1)
				ok = 0;
		}
		if (ok)
			add(b.X);
	}
	
	int step = 0, ptr = n - 1, k;
	while (ptr >= 0) {
		if (step) 
			a1 = *mi.begin();       
		else
			a1 = *mx.begin();        
		
		del(a1.Y);
		all.erase(a1.Y);

		//cout << a1.Y.X << ' ' << a1.Y.Y << '\n';
		
		k = abs(a1.X);
		ans = (ans + N[ptr] * k) % MOD;
		ptr--;

		rec(a1.Y);	
		
		step ^= 1;
	}             	
	
	cout << ans;
			
	return 0;
}