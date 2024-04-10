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
#include <cfloat>

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
const ld eps = 1e-8;
const int INF = 1E9;		
const int MAXN = 111111;
const int MAXK = 20;

int n, winner, s, t;
int current[2], sets[2];
int a[MAXN];
int nxt[2][MAXN][MAXK];
vector<pii> ans;

int jump(int id, int v, int k) {
	for (int i = MAXK - 1; i >= 0; i--)
		if ((1 << i) <= k) {
			//cout << v << "->" << nxt[id][v][i] << '\n';
			k -= (1 << i);
			v = nxt[id][v][i];
		}
	return v;	
}

int main() {

	cin >> n;      
	forn(i, n) {
		cin >> a[i];
		a[i]--;
	}

	nxt[0][n][0] = nxt[1][n][0]	= n;
	nxt[0][n - 1][0] = nxt[1][n - 1][0]	= n;
	ford(i, n - 1) {
		nxt[a[i + 1]][i][0] = i + 1;
		nxt[a[i + 1] ^ 1][i][0] = nxt[a[i + 1] ^ 1][i + 1][0];	
	}
	/*
	for (int id = 0; id < 2; id++, cout << '\n')
		forn(i, n)
			cout << nxt[id][i][0] << ' ';
	*/	
	forab(i, 1, MAXK)
		forn(j, n + 1)
			forn(k, 2)
				nxt[k][j][i] = nxt[k][nxt[k][j][i - 1]][i - 1];
	
	current[0] = current[1] = 0;
	forn(i, n) {
		current[a[i]]++;
		if (current[0] == current[1])
			continue;
		if (current[0] < current[1])
			winner = 1;
		else
			winner = 0;

		if (a[i] != winner)
			continue;

		t = current[winner];
		sets[winner] = 1;
		sets[winner ^ 1] = 0;

		//cout << current[0] << ' ' << current[1] << ' ' << winner << '\n';
		
		int pos = i;
		bool f = 1;
		
		//cout << pos << '\n';
		while (f && pos < n - 1) {
			int npos[2];
			forn(j, 2)
				npos[j] = jump(j, pos, t);

			int id = 0;
			if (npos[id] > npos[id ^ 1])
				id ^= 1;
			if (npos[id] == n) {
				f = 0;
				break;
			}
			
			//cout << npos[0] << ' ' << npos[1] << '\n';
			
			sets[id]++;
			pos = npos[id];
		}
		
		if (f && sets[a[n - 1]] > sets[a[n - 1] ^ 1])
			ans.pb(mp(sets[a[n - 1]], t));
	}
	
	sort(all(ans));
	cout << ans.size() << '\n';
	forn(i, ans.size())
		cout << ans[i].X << ' ' << ans[i].Y << '\n';
		
	return 0;
}