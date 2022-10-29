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
    
int n, k;
int a[MAXN];
ll L[MAXN], R[MAXN], X, ans;
map<int, int> lib;

int main() {
	
	scanf("%d%d", &n, &k);
	forn(i, n)
		scanf("%d", &a[i]);
	
	lib.clear();
	
	forn(i, n) {
		L[i] = 0;
		if (a[i] % k == 0) {
			X = a[i] / k;
			if (lib.find(X) != lib.end())
				L[i] = lib[X];
		}
		lib[a[i]]++;
	}
	
	lib.clear();
	
	ford(i, n) {
		R[i] = 0;
		X = 1ll * a[i] * k;
		if (abs(X) <= INF && lib.find(X) != lib.end())
			R[i] = lib[X];
		lib[a[i]]++;
	}
	
	ans = 0;
	
	forn(i, n)
		ans += L[i] * R[i];
	cout << ans;
	
	return 0;
}