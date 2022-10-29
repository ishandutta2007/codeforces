#pragma comment(linker, "/STACK:67108864")
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
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

int n, z, nz, q, w, sum;
int answer, cur;
vi a;

int main() {

	//freopen("a.in", "r", stdin);
	//freopen("a.out", "w", stdout);
	
	cin >> n;
	a.resize(2 * n);
	forn(i, 2 * n) {
		scanf("%d.%d", &q, &w);
		if (w == 0)
			z++;
		else {
			sum -= w;
			nz++;
		}			
	}

	answer = n * 1000 + sum;
	for (int th = 0; th <= n; th++) {
		if (z >= n - th) {
			cur = th * 1000 + sum;
			if (abs(cur) < abs(answer))
				answer = cur;
		}
	}
	answer = abs(answer);
	printf("%d.%03d", answer / 1000, answer % 1000);
	
	return 0;
}