#pragma comment(linker, "/STACK:67108864")

#include <iostream>
#include <cstdio>
#include <vector>
#include <deque>
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
const int MAXN = 1111;

int n, k[2], l;
string s[2];

int main() {

	//freopen("a.in", "r", stdin);
	//freopen("a.out", "w", stdout);
	
	scanf("%d\n", &n);
	n *= 2;
	forn(i, 2)
		cin >> s[i];

	l = 0;
	forn(i, n) {
		if (s[0][i] == '0' && s[1][i] == '1')
			k[1]++;
		if (s[0][i] == '1' && s[1][i] == '0')
			k[0]++;
		if (s[0][i] == '1' && s[1][i] == '1')
			l++;
	}

	if (l % 2 == 0) {
		if (k[0] > k[1])
			cout << "First";
		else if (k[0] == k[1] || k[0] == k[1] - 1)
			cout << "Draw";
		else
			cout << "Second";
	} else {
		if (k[0] >= k[1])
			cout << "First";
		else if (k[0] == k[1] - 1 || k[0] == k[1] - 2)
			cout << "Draw";
		else
			cout << "Second";
	}

    return 0;
}