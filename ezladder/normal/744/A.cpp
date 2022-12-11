#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:256000000")
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <deque>
#include <bitset>
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <cassert>
  
using namespace std;
  
typedef long long ll;
#define mp make_pair
#define pub push_back
#define XX first
#define YY second
#define db long double
#define all(a) a.begin(), a.end()
#define y1 dsfgsdfgsdfgsdfgsdfgsdfg
#define y0 asdfasdf3rcdt234d5c23xd234dx43
const int INF = (int)1e9 + 7;
const ll LINF = (ll)9e18 + 7;
  
const ll P1 = 353251;
const ll P2 = 239017;
const ll MOD = 1e9 + 7;
const ll MOD1 = 1e9 + 7;
const ll MOD2 = 1e9 + 9;

/*
const int MAX_MEM = 1e8;
int mpos = 0;
char mem[MAX_MEM];
void * operator new ( size_t n ) {
    char *res = mem + mpos;
    mpos += n;
    return (void *)res;
}
void operator delete ( void * ) { }
*/

int n, m, k;
vector<int> g[1007];
bool was[1007];
bool color[1007];
int sz, rb;
bool f;
int pst = 0, pstr = 0;
vector<pair<int, int> > ha;

void dfs(int v) {
	was[v] = 1;
	sz++;
	if (color[v])
		f = 1;
	for (int i = 0; i < g[v].size(); i++) {
		rb++;
		int to = g[v][i];
		if (!was[to])
			dfs(to);
	}
}

const bool is_testing = 0;
int main() {
	srand('D' + 'E' + 'N' + 'I' + 'S' + 'S' + 'O' + 'N');
	//mt19937 rnd(time(NULL));
	//ios_base::sync_with_stdio(0); cin.tie(0);
	if (is_testing) {
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	} else {
		//freopen("just.in", "r", stdin);
		//freopen("just.out","w", stdout);
	}
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < k; i++) {
		int w;
		scanf("%d", &w);
		w--;
		color[w] = 1;
	}
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		a--; b--;
		g[a].pub(b);
		g[b].pub(a);
	}
	for (int i = 0; i < n; i++)
		if (!was[i]) {
			f = 0;
			sz = 0;
			rb = 0;
			dfs(i);
			rb /= 2;
			if (f) {
				ha.pub(mp(sz, rb));
			} else {
				pst += sz;
				pstr += rb;
			}
		}
	sort(all(ha));
	reverse(all(ha));
	ll ans = 0;
	for (int i = 1; i < ha.size(); i++) {
		ll sz = ha[i].XX;
		ll now = (sz * (sz - 1)) / 2;
		now -= ha[i].YY;
		ans += now;
	}
	ll sz = pst + ha[0].XX;
	ll now = (sz * (sz - 1)) / 2;
	now -= ha[0].YY + pstr;
	ans += now;
	cout << ans;
}