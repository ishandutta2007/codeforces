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
const int MAXN = 222;
                 
ll a, b, x1, y1, x2, y2;
ll tmp;

int main() {

	cin >> a >> b;
	for (x1 = 1; x1 < a; x1++) {
		for (x2 = 1; x2 < b; x2++) {
			y1 = a * a - x1 * x1;
			tmp = sqrt(1.0 * y1);
			while (tmp * tmp < y1) tmp++;
			while (tmp * tmp > y1) tmp--;
			if (tmp * tmp != y1)
				continue;
			y1 = tmp;
			
			y2 = b * b - x2 * x2;
			tmp = sqrt(1.0 * y2);
			while (tmp * tmp < y2) tmp++;
			while (tmp * tmp > y2) tmp--;
			if (tmp * tmp != y2)
				continue;
			y2 = tmp;
			
			if (y1 == y2)
				continue;
				
			if (-x1 * x2 + y1 * y2 != 0)
				continue;
			
			cout << "YES\n";
			printf("%I64d %I64d\n%I64d %I64d\n%I64d %I64d\n", 0ll, 0ll, -x1, y1, x2, y2);
			return 0;
		}	
	}
	
	cout << "NO";
                
	                       		
	return 0;
}