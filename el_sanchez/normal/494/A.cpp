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

int n, bal, k;
string s, ss;
int pos[MAXN];
vi a;

int main() {

	cin >> s;
	n = s.size();
	forn(i, n) {
		if (s[i] == '(')
			bal++;
		else if (s[i] == ')')
			bal--;
		else {
			pos[i] = 1;
			a.pb(i);
		}		}
	
	if (bal < a.size()) {
		cout << -1;
		return 0;
	}	
	
	k = bal - a.size();
	
	ss = "";
	forn(i, n) {
		if (s[i] != '#')
			ss += s[i];
		else {
			if (i == a.back()) {
				forn(i, k + 1)
					ss += ')';
			} else
				ss += ')';			}
	}

	bal = 0;	
	forn(i, ss.size()) {
		if (ss[i] == '(')
			bal++;
		else {
			bal--;
			if (bal < 0) {
				cout << -1;
				return 0;
			}
		}
	}
	//assert(bal == 0);
	
	forn(i, a.size() - 1)
		cout << 1 << '\n';
	cout << k + 1 << '\n';
	
	return 0;
}