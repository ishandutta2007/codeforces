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
typedef long double ld; 

const long double pi = acos(-1.0);
const long double eps = 1e-6;
const int INF = 1E9;        
const ll LINF = 1E18;        
const int MAXN = 2111;
                     
string s[6];

int main() {

	s[0] = "+------------------------+";
	s[1] = "|#.#.#.#.#.#.#.#.#.#.#.|D|)";
	s[2] = "|#.#.#.#.#.#.#.#.#.#.#.|.|";
	s[3] = "|#.......................|";
	s[4] = "|#.#.#.#.#.#.#.#.#.#.#.|.|)";
	s[5] = "+------------------------+";
	
	int k;
	cin >> k;
	forn(i, s[0].size()) {
		if (k == 0)
			break;
		forn(j, 6) {
			if (s[j][i] == '#') {
				s[j][i] = 'O';
				k--;
			}
			if (k == 0)
				break;			}
	}

	forn(i, 6)
		cout << s[i] << '\n';
		  		
	return 0;
}