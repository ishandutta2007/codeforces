#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <map>          
#include <queue>
#include <cstring>
#include <algorithm>
#include <sstream>
#include <ctime>
#include <cmath>
#include <iomanip>
#include <cassert>
#include <unordered_map>
                   
using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++) 
#define ford(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define forab(i, a, b) for (int i = int(a); i < int(b); i++)

#define sqr(x) ((x)*(x))
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define X first
#define Y second

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;
typedef double ld;
                 
const int INF = 1E9;    
const ld eps = 1e-9;
const ld pi = acos(-1.0);
const int MAXN = 111;                         

int n;
vector<ll> a, sum;
ll ans, k;

int main() {

	cin >> n;
	a.resize(n);
	forn(i, n) 
		cin >> a[i];
	sort(all(a));

	if (n == 1) {
		cout << a[0];
		return 0;
	}
	
	k = 2;
	ans = 0;
	forn(i, n) {
		ans += k * a[i];
		if (i != n - 2)
			k++;			
	}
		
	cout << ans;
	
	return 0;
}