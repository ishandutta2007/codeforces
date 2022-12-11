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

int n, t, k;
int a[2 * 100007];
vector<int> g[2 * 100007];
vector<int> g2[2 * 100007];
vector<int> q[2 * 100007];
vector<int> q2[2 * 100007];
int kk = 0;

void dfs(int v, int pred) {
	bool f = 1;
	for (int i = 0; i < g[v].size(); i++) {
		int to = g[v][i];
		if (to != pred) {
			dfs(to, v);
			f = 0;
		}
	}
	kk += f;
}

void dfs2(int v, int pred) {
	bool f = 1;
	for (int i = 0; i < g2[v].size(); i++) {
		int to = g2[v][i];
		if (to != pred) {
			dfs2(to, v);
			f = 0;
		}
	}
	kk += f;
}

void dfs3(int v, int pred) {
	bool f = 1;
	for (int i = 0; i < g2[v].size(); i++) {
		int to = g2[v][i];
		if (to != pred) {
			printf("%d %d\n", v, to);
			dfs3(to, v);
			f = 0;
		}
	}
	kk += f;
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
	scanf("%d %d %d", &n, &t, &k);
	for (int i = 0; i < t; i++)
		scanf("%d", &a[i]);
	int now = 2;
	q[0].pub(1);
	for (int i = 0; i < t; i++) {
		for (int j = 0; j < a[i]; j++) {
			pair<int, int> d = mp(now, q[i].back());
			g[d.XX].pub(d.YY);
			g[d.YY].pub(d.XX);
			if (q[i].size() > 1)
				q[i].pop_back();
			q[i + 1].pub(now);
			now++;
		}
	}
	dfs(1, 0);
	if (kk > k)
		cout << -1, exit(0);
	kk = k - kk;
	q2[0].pub(1);
	now = 2;
	for (int i = 0; i < t; i++) {
		int now2 = min(min(a[i], (i == 0 ? 1 : a[i - 1])) - 1, kk);
		now2 = max(now2, 0);
		//cout << "==" << kk << ' ' << now2 << endl;
		kk -= now2;
		int dd = max(0, (i == 0 ? 1 : a[i - 1]) - a[i]) + now2;
		for (int j = 0; j < a[i]; j++) {
			pair<int, int> d = mp(now, q2[i].back());
			//cout << d.XX << ' ' << d.YY << endl;
			g2[d.XX].pub(d.YY);
			g2[d.YY].pub(d.XX);
			if (q2[i].size() > 1 + dd)
				q2[i].pop_back();
			q2[i + 1].pub(now);
			now++;
		}
	}
	kk = 0;
	dfs2(1, 0);
	if (kk != k)
		cout << -1, exit(0);
	cout << n << "\n";
	dfs3(1, 0);
}