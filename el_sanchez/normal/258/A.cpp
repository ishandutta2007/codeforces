#pragma comment(linker, "/STACK:67108864")
 
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <cassert>
#include <map>
#include <set>
 
#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define forab(i, k, n) for(int i = (int)(k); i < (int)(n); i++)
#define forba(i, n, k) for(int i = (int)(n) - 1; i >= (int)(k); i--)
 
#define vi vector<int>
#define pii pair<int, int>
#define all(x) (x).begin(), (x).end()
#define ff first
#define ss second
 
using namespace std;
 
typedef long long ll;
 
const long double pi = 3.1415926535897932384626433832795;
const long double eps = 1e-9;
const int INF = 1e9;
const ll LINF = 1e18;
const int MAXN = 333;

string s;

int main() {
 
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
 
	cin >> s;
	for (int i = 0; i < s.size() - 1; i++) {
		if (s[i] == '0') {
			forab(j, i + 1, s.size())
				cout << s[j];
			return 0;
		}
		cout << s[i];
	}

    return 0;
}