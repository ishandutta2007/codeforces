#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = a; i < b; ++i)
#define RFOR(i,a,b) for(int i = a; i >= b;--i)
#define REP(i, n) FOR(i, 0, n)
#define pii pair<int,int>
#define vi vector < int >
#define sz(a) (int)a.size()
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"; 
#define y1 jaksflkajsf
#define pii pair<int,int>
#define pli pair<ll,int>
#define ld long double
#define pb push_back
#define mp make_pair

const int INF = 1e9+5;
const int inf = 1e9;
const int N = 4e5;
const double PI = acos(-1.0);
const double eps = 1e-9;
const int MOD = 1e9 + 7;
string s;
map < string, int > book;
int it;
int n;
int p[N];
int val[N];
string str[N];
bool cmp(int a, int b) {
	return val[a] > val[b];
}
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d\n", &n);
	REP(i, n) {
		char st[15];
		scanf("%s", st);
		s = st;
		if (!book.count(s)) {
			book[s] = it++;
			str[it - 1] = s;
		}
		int id = book[s];
		val[id] = i;
	}
	REP(i, it) p[i] = i;
	sort(p, p + it, cmp);
	REP(i, it) 
		printf("%s\n", str[p[i]].c_str());
	return 0;
}