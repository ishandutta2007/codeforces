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
const int MAXN = 111;
    
int n, mx;
set<int> lib2, lib;
char c[MAXN];
int k[MAXN];    

int main() {
	
	scanf("%d\n", &n);
	forn(i, n) {
		scanf("%c %d\n", &c[i], &k[i]);
		if (c[i] == '+') {
			lib2.insert(k[i]);
		} else {
			if (lib2.find(k[i]) == lib2.end())
				lib.insert(k[i]);
			else
				lib2.erase(k[i]);	
		}				
	}

	mx = lib.size();
	forn(i, n) {
		if (c[i] == '+')
			lib.insert(k[i]);
		else
			lib.erase(k[i]);
		mx = max(mx, (int)lib.size());
	}
	cout << mx;
	
	return 0;
}