#pragma comment(linker, "/STACK:67108864")

#include <iostream>
#include <fstream> 
#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <cassert>
#include <complex>
#include <bitset>
#include <map>
#include <set>
#include <ctime>

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define forab(i, k, n) for(int i = (int)(k); i < (int)(n); i++)
#define forba(i, n, k) for(int i = (int)(n) - 1; i >= (int)(k); i--)

#define vi vector<int>
#define pii pair<int, int>
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x)*(x))
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;

const long double pi = 3.1415926535897932384626433832795;
const long double eps = 0.000000001;
const int INF = 1E9;
const int MAXN = 111;

int n, t, k, last;
set<int> s[2];
vi a, nxt, dead;

int main() {

	//freopen("a.in", "r", stdin);
	//freopen("a.out", "w", stdout);
	
	cin >> n;
	a.resize(n);
	nxt.resize(n);
	dead.resize(n);
	forn(i, n) {
		scanf("%d", &a[i]);
		nxt[i] = i + 1;
		dead[i] = 0;
	}
	nxt[n - 1] = -1;

	s[1].clear();
	s[0].clear();
	forn(i, n - 1)
		if (a[i] > a[i + 1])
			s[0].insert(i);

	int id = 0;
	t = 0;
	while (!s[id].empty()) {
		s[1 - id].clear();
		set<int>::iterator it = s[id].begin();
		last = *it;

		while (it != s[id].end()) {
			k = *it;
			if (!dead[k] && it != s[id].begin()) {
				if (nxt[last] != -1 && a[last] > a[nxt[last]])
					s[1 - id].insert(last);
				last = k;
			}
			//kill: k -> nxt[k]
			dead[nxt[k]] = 1;		
			nxt[last] = nxt[nxt[k]];
			it++;
		}
		if (nxt[last] != -1 && a[last] > a[nxt[last]] && s[1 - id].find(last) == s[1 - id].end())
			s[1 - id].insert(last);

		id = 1 - id;
		t++;
	}

	cout << t;

	return 0;
}