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
typedef double ld; 

const ld pi = acos(-1.0);
const ld eps = 1e-8;
const int INF = 1E6;
const int MAXN = 200500;      
const int MAXK = 262144; 

struct tree {
	int t[2 * MAXK + 3];
	
	tree() {
		memset(t, 0, sizeof(t));	
	};

	void fill(int n) {
		memset(t, 0, sizeof(t));	
		for (int i = 0; i < n; i++)
        	t[MAXK + i] = 1;
  		for (int i = MAXK - 1; i >= 1; i--)
        	t[i] = t[i * 2] + t[i * 2 + 1];		
	}
	
	void update(int i, int value) {
		int v = MAXK + i;
		t[v] = value;
		while (v > 1) {
			v /= 2;
			t[v] = t[2 * v] + t[2 * v + 1];
		}
	}

	int get(int v, int l, int r, int lx, int rx) {
		if ((r < lx) || (rx < l))
			return 0;
		if ((lx <= l) && (r <= rx))
			return t[v];
		return get(2 * v, l, (l + r) / 2, lx, rx) + get(2 * v + 1, (l + r) / 2 + 1, r, lx, rx);
	}
	
	int get(int l, int r) {
		return get(1, 1, MAXK, l, r); 	
	}
	
	int find(int v, int l, int r, int x) {
		if (l == r)
			return l;
		if (x < t[v * 2])
			return find(v * 2, l, (l + r) / 2, x);
		return find(v * 2 + 1, (l + r) / 2 + 1, r, x - t[v * 2]);
	}
	
	int find(int x) {
		return find(1, 1, MAXK, x);	
	}
};

int n;
int p[2][MAXN], a[MAXN];
int pos[3][MAXN];
tree t[3];

int main() {

	//forn(i, 3)
	//	t[i] = tree();
		
	scanf("%d", &n);
	forn(i, 2)
		forn(j, n)
			scanf("%d", &p[i][j]);

	forn(i, 3)            
		t[i].fill(n);
		
	forn(i, 2)
		forn(j, n) {
			int sum = t[i].get(1, p[i][j]);
			pos[i][j] = sum;
			t[i].update(p[i][j], 0);
		}
			
	int rest = 0;
	for (int i = n - 1; i >= 0; i--) {
		int sum = pos[0][i] + pos[1][i] + rest;
		rest = sum / (n - i);
		sum %= (n - i);
		pos[2][i] = sum;	
	}

	forn(i, n) {
		//cout << pos[2][i] << '\n';
		a[i] = t[2].find(pos[2][i]) - 1;
		t[2].update(a[i], 0);	
	}
	
	forn(i, n)
		printf("%d ", a[i]);
			
	return 0;
}