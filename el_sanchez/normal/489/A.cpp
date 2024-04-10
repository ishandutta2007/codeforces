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
const ld eps = 1e-12;
const int INF = 1E9;		
const int MAXN = 5555;

int n;
vi a;
vector<pii> ans;

int main() {
                  
	cin >> n;
	a.resize(n);
	forn(i, n)
		cin >> a[i];
		
	for (int i = 0; i < n - 1; i++) {
		int id = i;
		for (int j = i + 1; j < n; j++)
			if (a[id] > a[j])
				id = j;
		ans.pb(mp(i, id));
		swap(a[i], a[id]);		
	}
	
	//forn(i, n)
	//	cout << a[i] << '\n';
		
	cout << ans.size() << '\n';
	forn(i, ans.size())
		cout << ans[i].X << ' ' << ans[i].Y << '\n';
	
	return 0;
}