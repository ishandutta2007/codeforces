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
#define pii pair<long long, long long>
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x)*(x))
#define X first
#define Y second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld; 

const long double pi = acos(-1.0);
const long double eps = 1e-6;
const char c[] = {'D', 'U', 'L', 'R'};
const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};
const int INF = 1E9;        
const int MAXN = 111;  
                          
int n, pos;
ll k, nn, csum, cm, cval;
vi a;

int main() {

	cin >> n >> k;
	a.resize(n);
	forn(i, n)
		cin >> a[i];
	
	csum = 0;
	nn = n;
	pos = 1;
	forn(i, n) {
		cval = csum - 1ll * (nn - pos) * (pos - 1) * a[i];
		if (cval < k) {
			cout << i + 1 << '\n';	
			nn--;
		} else {
			csum += 1ll * a[i] * (pos - 1);
			pos++;
		}	      		
	}
	
	return 0;
}