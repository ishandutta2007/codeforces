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
const int MAXN = 100500;
        
int n, ans;
int a[MAXN];
int minL[MAXN], minR[MAXN], curmin, h;

int main() {

	cin >> n;
	forn(i, n)
		cin >> a[i];
		
	ans = 0;
	curmin = 0;
	for (int i = 1; i < n; i++) {
		curmin++;

		h = a[i] - 1;
		if (a[i - 1] < a[i])
			h = a[i - 1];
		curmin = min(curmin, h);
		minL[i] = curmin;	
	}

	curmin = 0;
	for (int i = n - 2; i >= 0; i--) {
		curmin++;

		h = a[i] - 1;
		if (a[i + 1] < a[i])
			h = a[i + 1];
		curmin = min(curmin, h);
		minR[i] = curmin;	
	}

	for (int i = 1; i < n - 1; i++)
		ans = max(ans, min(minL[i], minR[i]));
	cout << ans + 1;

	return 0;
}