#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define forab(i, k, n) for (int i = (int)(k); i < (int)(n); i++)
#define forba(i, n, k) for (int i = (int)(n) - 1; i >= (int)(k); i--)

#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x)*(x))
#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define db(x) cout << #x << " = " << x << endl

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;
typedef double ld; 

const ld pi = acos(-1.0);
const ld eps = 1e-9;
const int INF = 1E9;
const int MAXN = 200500;
const int ALPH = 27;

struct node {
	int L, len, link;
	int go[ALPH];

	node(int _L = 0, int _len = 0) {
		L = _L;
		len = _len;
		link = 0;
		memset(go, 0, sizeof(go));
	}
};

int n;
char s[MAXN];
int sz;
node a[MAXN];
int curV, curPos;

int addNode(int L, int len) {
	a[sz] = node(L, len);
	return sz++;	
}

void goDown() {
	while (curPos > a[a[curV].go[s[n - curPos] - 'a']].len) {
		curV = a[curV].go[s[n - curPos] - 'a'];
		curPos -= a[curV].len;
	}
}

void extend(char c) {
	s[n++] = c;
	curPos++;

	int last = 0;
	while (curPos > 0) {
		goDown();
		
		int edge = s[n - curPos] - 'a';
		int &v = a[curV].go[edge];
		char d = s[a[v].L + curPos - 1];
		
		if (v == 0) {
			v = addNode(n - curPos, INF);
			a[last].link = curV;
			last = 0;	
		} else if (c == d) {
			a[last].link = curV;
			return;	
		} else {
			int u = addNode(a[v].L, curPos - 1);
			a[u].go[c - 'a'] = addNode(n - 1, INF);
			a[u].go[d - 'a'] = v;

			a[v].L += curPos - 1;
			if (a[v].len != INF)
				a[v].len -= curPos - 1;

			v = u;

			a[last].link = u;
			last = u;	
		}
		
		if (curV == 0)
			curPos--;
		else
			curV = a[curV].link;
	}
}

void initSuffixTree() {
	n = 0;
	sz = 1;
	a[0] = node(0, INF);	
	curV = curPos = 0;
}

string S;
ll ans;
int sumLen = 0;
int cnt[MAXN];

void dfs(int v) {
	//cout << v << ": [" << a[v].L << ".." << a[v].L + a[v].len - 1 << "]\n";
	bool leaf = 1;
	
	forn(i, ALPH) {
		int w = a[v].go[i];	
		if (w != 0) {
			//cout << v << " -> " << w << '\n';
			leaf = 0;
			dfs(w);		
			
			ans += 1ll * a[w].len * cnt[w] * (cnt[w] + 1) / 2;
//			sumLen += a[w].len * cnt[w];
			
		    cnt[v] += cnt[w];
		}
	}
	
	if (leaf)
		cnt[v] = 1;
}

int main() {

	initSuffixTree();
	cin >> S;
	forn(i, S.size())
		extend(S[i]);
	extend('a' + ALPH - 1);
	
	forn(i, sz)
		a[i].len = min(a[i].len, (int)S.size() - a[i].L);	
		
	ans = 0;
	dfs(0);
	cout << ans << '\n';
//	cout << sumLen << '\n';
	
	return 0;
}