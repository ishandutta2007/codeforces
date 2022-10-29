#include <list>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cfloat>
#include <numeric>
 
using namespace std;
 
const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
 
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int, int> pii;
 
#define sz(c) int((c).size())
#define all(c) (c).begin(), (c).end()
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define FORD(i,a,b) for (int i = int(b)-1; i >= (a); i--)
#define FORIT(i,c) for (__typeof__((c).begin()) i = (c).begin(); i != (c).end(); i++)
 
ull A, B; 
 
int main() {
	cin >> A >> B;
	if (A < B) {
		cout << -1 << endl;
	} else {
		ull v = A-B;
		if (v % 2) {
			cout << -1 << endl;
		} else {
			v /= 2;
			if (B&v) {
				cout << -1 << endl;
			} else {
				cout << v << ' ' << v+B << endl;
			}
		}
	}
	return 0;
}