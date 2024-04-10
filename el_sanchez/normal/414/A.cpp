#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cstring>
#include <stdlib.h>
#include <string>
#include <ctime>
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
const ld eps = 1e-7;
const int MAXN = 2222;   

int n, m;
                             
int main() {
	
	cin >> n >> m;
	if (n == 1 && m == 0) {
		cout << 1;
		return 0;
	}
	if ((n / 2) > m || n == 1) {
		cout << -1;
		return 0;
	}
	int nn = n / 2;
	int mm = m - (nn - 1);
	//cout << mm << endl;

	if (mm == 0)
		cout << n + 1 << ' ' << n + 2 << ' ';
	else {

	int p = n;
	p += mm - (p % mm);
	//cout << p << endl;
	//cout << mm << endl;

	printf("%d %d ", p, p + mm);
	}

	forn(i, nn * 2 - 2)
		printf("%d ", i + 1);
    if (n & 1)
    	printf("%d", nn * 2 - 1);
	                      
    return 0;
}