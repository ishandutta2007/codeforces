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

const long double pi = acos(-1.0);
const long double eps = 1e-6;
const int INF = 1E9;        
const int MAXN = 100500;

inline int gcd(int a, int b) {
	if (a == 0)
		return b;
	if (b == 0)
		return a;
	if (a < b)
		return gcd(a, b % a);
	return gcd(b, a % b);
}

int n, m;
int a[MAXN], sz, last, last2;
pii lvl[33], lvl2[33];
pii q[MAXN * 33];
ll ans[MAXN * 3];
pii w[MAXN * 3];

void add(int g, int pos) {
	lvl2[++last2] = mp(g, pos);
}

int main() {

	scanf("%d", &n);
	forn(i, n) 
		scanf("%d", &a[i]);
		
	lvl[0] = mp(a[n - 1], n - 1);
	last = 0;
	q[sz++] = mp(a[n - 1], 1);

	//cout << lvl[0].X << ' ' << lvl[0].Y << '\n';
	//cout << gcd(6, 3) << '\n';
	
	for (int i = n - 2; i >= 0; i--) {
		last2 = -1;
		add(a[i], i);
		
		if (gcd(a[i], a[i + 1]) != a[i]) {
			//cout << "!\n"; 
			add(gcd(a[i], a[i + 1]), i + 1);
		}

		for (int j = 0; j <= last; j++) {
			if (gcd(lvl2[last2].X, a[lvl[j].Y]) == lvl2[last2].X)
				continue;
			add(gcd(lvl2[last2].X, a[lvl[j].Y]), lvl[j].Y);
		}

		last = last2;
		forn(j, last + 1)
			lvl[j] = lvl2[j];			
		/*		
		cout << i << ":\n";
		forn(i, last + 1)
			cout << lvl[i].X << ' ' << lvl[i].Y << '\n';
		*/	
		for (int j = 0; j < last; j++)
			q[sz++] = mp(lvl[j].X, lvl[j + 1].Y - lvl[j].Y);
		q[sz++] = mp(lvl[last].X, n - lvl[last].Y);		
	}
	
	scanf("%d", &m);
	forn(i, m) {
		scanf("%d", &w[i].X);
		w[i].Y = i;		
	}	
	
	sort(q, q + sz);
	q[sz].X = q[sz - 1].X + 1;
	//forn(i, sz)
	//	cout << q[i].X << ' ' << q[i].Y << '\n';
		
	sort(w, w + m);
	
	int ptrq = 0, ptrw = 0;
	while (ptrq < sz && ptrw < m) {
		int ptrqr = ptrq, ptrwr;
		ll sum = q[ptrq].Y;
		while (ptrqr + 1 < sz && q[ptrqr + 1].X == q[ptrqr].X) {
			ptrqr++; 
			sum += q[ptrqr].Y;
		}	
		
		ptrwr = ptrw;
		while (ptrwr + 1 < m && w[ptrwr + 1].X == w[ptrwr].X) {
			ptrwr++; 
		}
		
		if (q[ptrq].X == w[ptrw].X) {
			for (int i = ptrw; i <= ptrwr; i++)
				ans[w[i].Y] = sum;
			ptrw = ptrwr + 1;
			ptrq = ptrqr + 1;
		} else if (q[ptrq].X < w[ptrw].X)
			ptrq = ptrqr + 1;
		else
			ptrw = ptrwr + 1;  	
	
	}
	
	forn(i, m)
		printf("%I64d\n", ans[i]);
		
		
	return 0;
}