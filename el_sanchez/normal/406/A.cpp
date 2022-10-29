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
typedef double ld; 

const ld pi = acos(-1.0);
const ld eps = 1e-8;
const int INF = 1E9;		
const int MAXN = 1111;

int n, m, q, k, sum; 
int a[MAXN][MAXN];
int row[MAXN], col[MAXN];

int main() {

	scanf("%d", &n);
	forn(i, n)
		forn(j, n)
			scanf("%d", &a[i][j]);          

	sum = 0;
	forn(i, n)
		sum ^= a[i][i];
		
	scanf("%d", &m);
	forn(i, m) {
		scanf("%d", &q);
		if (q == 3)
			printf("%d", sum);
		else {
			scanf("%d", &k);
			k--;
			sum ^= 1;	
		}		}
			                   		
	return 0;
}