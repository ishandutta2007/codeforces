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
    
int n, m;
ld ans, cur, cnk, ch, ch2;

int main() {
	       
	cin >> n >> m;

	ans = 0;	
	for (int k = 0; k <= min(m - 1, n - 1); k++) { //
		cur = 0;
		
		//chances
		cnk = 1;
		for (int i = 1; i <= k; i++)
			cnk *= ld(m - i) / (k - i + 1);
		for (int i = 1; i <= n - 1 - k; i++)
			cnk *= ld((n - 1) * m - i + 1) / (n - 1 - k - i + 1);
             
		ch = 1;
		for (int i = 1; i <= n - 1; i++)
			ch *= ld(n - 1 - i + 1) / (n * m - i);
		
		cur = cnk * ch * (k + 1) / n;
		
		//cout << cur << endl;
		
		ans += cur;
	}
	
	cout.precision(15);
	//ans *= n;
	cout << ans;
	
	return 0;
}