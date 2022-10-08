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

const int size = 1000 * 1000 + 100;

int lcp(const string& s1, const string& s2) {
	int len1 = s1.size();
	int len2 = s2.size();
	
	int ans = 0;
	while (ans < min(len1, len2)) {
		if (s1[ans] == s2[ans]) {
			ans++;
		} else {
			break;
		}
	}
	
	return ans;
}

int par[size];
set <int> myset[size];
int curlevel;
int n;
char buf[size];

vector <pair <int, int> > ans;
int ansval = 0;

int getpar(int v) {
	if (v != par[v])
		par[v] = getpar(par[v]);
	return par[v];
}

void join(int v, int u) {
	v = getpar(v);
	u = getpar(u);
	
	if (myset[v].size() < myset[u].size()) {
		swap(v, u);
	}
	par[u] = v;
	
	for (set <int>::iterator it = myset[u].begin(); it != myset[u].end(); ++it) {
		myset[v].insert(*it);
	}
	
	myset[u].clear();
	while (!myset[v].empty()) {
		if (*myset[v].begin() < n && *myset[v].rbegin() >= n) {
			ans.pb(mp(*myset[v].begin(), *myset[v].rbegin()));
			
			myset[v].erase(*myset[v].begin());
			myset[v].erase(*myset[v].rbegin());
			
			ansval += curlevel;
		} else {
			break;
		}
	}
}

int main () {
/*
	freopen("input.txt", "w", stdout);
	int n = 100 * 1000;
	int len = 4;
	printf("%d\n", n);
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < 4; k++)
				printf("%c", char('a' + rand() % 26));
			printf("\n");
		}
	}
	
	return 0;
*/
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	scanf("%d", &n);
	
	vector <pair <string, int> > names;
	
	for (int i = 0; i < n; i++) {
		scanf("%s", buf);
		names.pb(mp(string(buf), i));
	}
	for (int i = 0; i < n; i++) {
		scanf("%s", buf);
		names.pb(mp(string(buf), i + n));
	}
	
	sort(names.begin(), names.end());
	
	vector <pair <int, int> > joins;
	for (int i = 0; i < (int) names.size() - 1; i++) {
		joins.pb(mp(lcp(names[i].fs, names[i + 1].fs), i));
	}
	
	for (int i = 0; i < 2 * n; i++) {
		myset[i].insert(i);
		par[i] = i;
	}
	
	
	sort(joins.rbegin(), joins.rend());
	
	curlevel = size;
	
	for (int i = 0; i < (int) joins.size(); i++) {
		curlevel = joins[i].fs;
		join(names[joins[i].sc].sc, names[joins[i].sc + 1].sc);
	}
	
	printf("%d\n", ansval);
	
//	assert((int) ans.size() == n);
	
	for (int i = 0; i < n; i++)
		printf("%d %d\n", ans[i].fs + 1, ans[i].sc - n + 1);
	
	return 0;
}