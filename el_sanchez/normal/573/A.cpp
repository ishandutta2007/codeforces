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
        
int n;
int a[MAXN];
vector<pii> f[MAXN];	

int main() {

	cin >> n;
	forn(i, n) {
		scanf("%d", &a[i]);
		while (a[i] % 2 == 0)
			a[i] /= 2;
		while (a[i] % 3 == 0)
			a[i] /= 3;
	}
		
	forn(i, n - 1)
		if (a[i] != a[i + 1]) {
			cout << "No";
			return 0;
		}
	cout << "Yes";
		
	return 0;
}