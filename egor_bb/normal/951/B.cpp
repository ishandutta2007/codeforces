#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define fst first
#define sc second
#define snd second
#define sz(X) (int)(X).size()
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define fornr(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define forab(i, a, b) for(int i = int(a); i < int(b); i++)
#define all(X) X.begin(), X.end()

typedef long long ll;
typedef pair<int,int> pii;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef double dbl;
typedef long double ld;
typedef vector<int> vi;

const int MAX_N = 105;

int a[MAX_N][MAX_N], goo[MAX_N][MAX_N];
int n, m;
	
bool y_asc(const pii &np1, const pii &np2) {
	if (np1.sc == np2.sc)
		return np1.fs < np2.fs;
	return np1.sc < np2.sc;
}

struct Move {
	int x_1, y_1, x_2, y_2;
	Move() {}
	Move(int _x_1, int _y_1, int _x_2, int _y_2): x_1(_x_1), y_1(_y_1), x_2(_x_2), y_2(_y_2) {}
};

void mmove(int x_1, int y_1, int x_2, int y_2, vector<Move> &mmoves) {
	a[x_2][y_2] = a[x_1][y_1];
	a[x_1][y_1] = 0;
	mmoves.pb(Move(x_1, y_1, x_2, y_2));
}

void go(int x_1, int y_1, int x_2, int y_2, vector<Move> &mmoves) {
	if (x_1 <= x_2) {
		for (int i = x_1; i < x_2; i++)
			mmove(i, y_1, i + 1, y_1, mmoves);
	} else {
		for (int i = x_1; i > x_2; i--)
			mmove(i, y_1, i - 1, y_1, mmoves);
	}
	if (y_1 <= y_2) {
		for (int i = y_1; i < y_2; i++)
			mmove(x_2, i, x_2, i + 1, mmoves);
	} else {
		for (int i = y_1; i > y_2; i--)
			mmove(x_2, i, x_2, i - 1, mmoves);
	}
}

pair<vector<Move>, vi> get(vector<pii> st) {
	vector<Move> ans;
	int cur = 1;
	forn (i, n)
		forn (j, n)
			a[i][j] = 0;
	for (auto np : st)
		a[np.fs][np.sc] = cur++;
	sort(all(st), y_asc);
	sort(st.begin(), st.end());
	for (auto &np : st) {
		int x = np.fs, y = np.sc, ind = -1;
		for (int j = y - 1; j >= -1; j--)
			if (j == -1 || a[x][j] != 0) {
				ind = j;
				break;
			} 
		//f("%d %d %d %d\n", x, y, x, ind + 1);
		go(x, y, x, ind + 1, ans);
	}
	vi v2;
	vector<pii> v1;
	forn (x, n) {
		forab (y, 1, n)
			if (a[x][y])
				v1.pb(mp(x, y));
		if (!a[x][0])
			v2.pb(x);
	}
	forn (i, sz(v1)) {
		goo[v1[i].fs][v1[i].sc] = v2[i];
	}
	sort(all(v1), y_asc);
	reverse(all(v1));
	for (auto np : v1) {
		if (np.sc == n - 1) {
			go(np.fs, np.sc, goo[np.fs][np.sc], 0, ans);
		} else {
			mmove(np.fs, np.sc, np.fs, np.sc + 1, ans);
			go(np.fs, np.sc + 1, goo[np.fs][np.sc], 0, ans);	
		}
	}
	vi v3;
	forn (i, n) {
		if (a[i][0]) {
			int ind = -1;
			for (int j = i - 1; j >= -1; j--)
				if (j == -1 || a[j][0] != 0) {
					ind = j;
					break;
				} 
			go(i, 0, ind + 1, 0, ans);	
			//printf("%d %d %d %d\n", x, y, x, ind + 1);
		}
	}
	vi indices;
	forn (i, m)
		indices.pb(a[i][0]);
	return mp(ans, indices);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
		
	scanf("%d%d", &n, &m);
	vector<pii> start(m), fin(m);
	forn (i, m) {
		scanf("%d%d", &start[i].fs, &start[i].sc);
		start[i].fs--, start[i].sc--;
	}	
	forn (i, m) {
		scanf("%d%d", &fin[i].fs, &fin[i].sc);
		fin[i].fs--, fin[i].sc--;
	}	
	auto res1 = get(start);
	vector<Move> ans = res1.fs;
	auto res2 = get(fin);

	vi pos1 = res1.sc;
	vi pos2 = res2.sc;
	if (n == 2 && m == 2 && pos1[0] != pos2[0]) {
		ans.pb(Move(0, 0, 0, 1));			
		ans.pb(Move(1, 0, 0, 0));			
		ans.pb(Move(0, 1, 1, 1));			
		ans.pb(Move(1, 1, 1, 0));			
	} else {
		forn (i, m) {
			forn (j, m)
				if (pos1[j] == pos2[i]) {
					if (i == j)
						continue;
					ans.pb(Move(i, 0, i, 1));
					ans.pb(Move(i, 1, i, 2));
					ans.pb(Move(j, 0, j, 1));
					go(i, 2, j, 2, ans);
					go(j, 1, i, 1, ans);
					go(j, 2, j, 0, ans);
					go(i, 1, i, 0, ans);
					swap(pos1[j], pos1[i]);
				}
		}
	}

	vector<Move> ans2 = res2.fs;
	reverse(all(ans2));
	for (auto np : ans2)
		ans.pb(Move(np.x_2, np.y_2, np.x_1, np.y_1));

	printf("%d\n", sz(ans));
	for (auto &mov : ans)
		printf("%d %d %d %d\n", mov.x_1 + 1, mov.y_1 + 1, mov.x_2 + 1, mov.y_2 + 1);
		
	return 0;
}