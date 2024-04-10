#pragma comment(linker, "/STACK:67108864")

#include <iostream>
#include <cstdio>
#include <vector>
#include <deque>
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

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define forab(i, k, n) for(int i = (int)(k); i < (int)(n); i++)
#define forba(i, n, k) for(int i = (int)(n) - 1; i >= (int)(k); i--)

#define vi vector<int>
#define pii pair<int, int>
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x)*(x))
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;

const long double pi = 3.1415926535897932384626433832795;
const long double eps = 0.000000001;
const int INF = 1E9;
const int MAXN = 100500;

string s, ss;
bool open;
int i;

void print() {
	cout << '<' << ss << '>' << '\n';
	ss = "";
}

int main() {

	//freopen("a.in", "r", stdin);
	//freopen("a.out", "w", stdout);
	
	getline(cin, s);
	open = 0;
	i = 0;
	while (i < s.size()) {
		if (s[i] == '"') {
			if (open) {
				print();
				open = 0;				
			} else
				open = 1;
		} else {
			if (s[i] == ' ') {
				if (open)
					ss += s[i];
				else if (ss != "")
					print();
			} else
				ss += s[i];
		}

		i++;
	}

	if (ss != "")
		print();

    return 0;
}