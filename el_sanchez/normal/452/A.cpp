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
typedef long double ld;

const int INF = 1E9;    
const ld eps = 1e-9;
const ld pi = acos(-1.0);
const int MAXN = 111;
    
const string lib[] = {"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};
                  
int n;
string s;

int main() {

	cin >> n;
	cin >> s;               
	forn(i, 8) {
		bool ok = 1;
		if (n != lib[i].size())
			continue;
		forn(j, n)
			if (s[j] != '.' && s[j] != lib[i][j]) {
				ok = 0;
				break;
			}
		if (ok) {
			cout << lib[i];
			return 0;
		}		
	}

	return 0;
}