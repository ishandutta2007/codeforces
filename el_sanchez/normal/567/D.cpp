//#define _GLIBCXX_DEBUG
//#include <bits/stdc++.h>

#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <complex>
#include <map>
#include <set>
#include <cassert>
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
#define db(x) cout << #x << " = " << x << endl

using namespace std;

typedef long long ll;
typedef double ld; 

const ld pi = acos(-1.0);
const ld eps = 1e-9;
const int INF = 1E9;		
const int MAXN = 211111;
    
int n, k, a, m, L, M, R, curMax;
set<pii> segments;

int countNum(int len) {
	if (len < a)
		return 0;
	return (len - a) / (a + 1) + 1;
}

int main() {
	
	scanf("%d%d%d", &n, &k, &a);
	
	segments.insert({n - 1, n});
	curMax = countNum(n);
	
	//cout << curMax << '\n';
	
	scanf("%d", &m);
	forn(i, m) {
		scanf("%d", &M);
		M--;
		
		auto cur = *segments.lower_bound({M, -INF});
		
		curMax -= countNum(cur.Y);
	
		R = cur.X;
		L = cur.X - cur.Y + 1;
		
		if (M - L > 0) {
			pii cur1 = {M - 1, M - L}; //[L, M-1], len = (M - 1) - L + 1
			curMax += countNum(cur1.Y);
			segments.insert(cur1);
		}
		
		if (R - M > 0) {
			pii cur2 = {R, R - M}; //[M+1, R], len = R - (M + 1) + 1
			curMax += countNum(cur2.Y);
			segments.insert(cur2);
		}

		//db(curMax);
		
		if (curMax < k) {
			cout << i + 1;
			return 0;
		}		
	}
	
	cout << -1;
	
	return 0;
}