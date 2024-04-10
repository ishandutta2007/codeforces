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
const int MAXN = 100500;
    
int n, k, last;
ll sum[2];
vi s[2], cs;

bool operator<(vi a, vi b) {
	for (int i = 0; i < min(a.size(), b.size()); i++)
		if (a[i] < b[i])
			return 1;
		else if (a[i] > b[i])
			return 0;
	if (a.size() < b.size())
		return 1;
	return 0;
}

bool operator>(vi a, vi b) {
	for (int i = 0; i < min(a.size(), b.size()); i++)
		if (a[i] > b[i])
			return 1;
		else if (a[i] < b[i])
			return 0;
	if (a.size() > b.size())
		return 1;
	return 0;
}
int main() {

	cin >> n;
	forn(i, n) {
		cin >> k;
		last = (k > 0 ? 0 : 1);
		k = abs(k);
		s[last].pb(k);
		sum[last] += k;
	}				
	
	if (sum[0] < sum[1])
		cout << "second";
	else if (sum[0] > sum[1])
		cout << "first";
	else if (s[0] < s[1])
		cout << "second";
	else if (s[0] > s[1])
		cout << "first";
	else 
		cout << (last == 0 ? "first" : "second");
		
	return 0;
}