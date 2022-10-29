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

const long double pi = acos(-1.0);
const long double eps = 1e-6;
const int INF = 1E9;        
const int MAXN = 100500;

int n, ans, maxelem;
vi a;

int main() {

	cin >> n;
	a.resize(n);
	forn(i, n)
		cin >> a[i];

	sort(all(a));
	std::vector<int>::iterator it;
  	it = std::unique(a.begin(), a.end()); 
    a.resize(std::distance(a.begin(), it));
    
    n = a.size();
    /*
    forn(i, n)
    	cout << a[i] << ' ';
    cout << '\n';
    */
	maxelem = a[n - 1];
	
	ans = 0;	 
	forn(i, n) {
		int k = a[i];
		if (k == 0 || k == 1)
			continue;
			
		for (int j = 2 * k; j - k <= maxelem; j += k) {
			int pos = lower_bound(all(a), j) - a.begin();
			pos--;
			if (pos < 0 || pos >= n)
				continue;
			
			//cout << a[pos] << '\n';
			ans = max(ans, a[pos] % k); 
		}
	}
				
	cout << ans;
	
	return 0;
}