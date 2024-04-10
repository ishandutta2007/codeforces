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
#include <cctype>
#include <ctime>
#include <cmath>
#include <iomanip>
#include <cassert>
                   
using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++) 
#define ford(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define forab(i, a, b) for (int i = int(a); i < int(b); i++)

#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define X first
#define Y second

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long ll;
typedef long double ld;

const int INF = 1E9;   
const ld eps = 1e-6;
const ld pi = acos(-1.0);
const int MAXN = 2222;   
const ll MOD = 1E9 + 7;

int n, m, k;
string s[MAXN];
int ans[10 * MAXN];    

int main() {
         
	cin >> n >> m >> k;
	forn(i, n)
		cin >> s[i];
	forn(i, m)
		ans[i] = 0;

    forn(i, n)
    	forn(j, m) {
    		if (s[i][j] == 'R') {
    			ans[j + i]++;
    		} else if (s[i][j] == 'L') {
    			if (j >= i)
    				ans[j - i]++;
    		} else if (s[i][j] == 'U')
    			ans[j] += !(i & 1);
    		else if (s[i][j] == 'D' && i == 0)
    			ans[j] += n;
    	}

    forn(i, m)
    	cout << ans[i] << ' ';

	return 0;
}