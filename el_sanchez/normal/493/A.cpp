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
const int MAXN = 100500;
    
string s[2], id, card;
int n, k;
int t, num;
map<pii, int> lib;

int main() {

	cin >> s[0] >> s[1];
	cin >> n;
	forn(i, n) {
		cin >> t >> id >> num >> card;
		if (id == "h")
			k = 0;
		else
			k = 1;	
		if (true) {
			if (card == "y")
				lib[mp(k, num)]++;
			else
				lib[mp(k, num)] += 2;
				
			if (lib[mp(k, num)] >= 2 && lib[mp(k, num)] < INF) {
				lib[mp(k, num)] = INF;	
				cout << s[k] << ' ' << num <<  ' ' << t << '\n';
			}
		}
	}		
		
	return 0;
}