#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <deque>
#include <cassert>
#define For(i, a, b) for (int i = a; i < b; ++i)
#define Out(i, a, b) for (int i = a - 1; i >= b; --i)
#define pb push_back
#define x first
#define y second
#define files(FileName) read(FileName); write(FileName)
#define read(FileName) freopen((FileName + ".in").c_str(), "r", stdin)
#define write(FileName) freopen((FileName + ".in").c_str(), "w", stdout)
using namespace std;
template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { if (x < y) x = y; }

const string FileName = "input";
const int INF = 2e9;
const int MAXN = 1 << 18;
typedef pair <int, int> point;
typedef long double base;

int n, k;
int id = 0;
vector <string> res;
vector <string> arr;

int main() {
	srand(time(0));
	ios::sync_with_stdio(0);
	//read(FileName);
	for (int i = 0; i < 26; ++i) {
		for (int j = 0; j < 26; ++j) {
			string s = "";
			s += 'A' + i;
			s += 'a' + j;
			res.pb(s);
		}
	}
	cin >> n >> k;
	for (int i = 0; i < k - 1; ++i) {
		arr.pb(res[id++]);
	}
	for (int i = k - 1; i < n; ++i) {
		string ans;
		cin >> ans;
		if (ans == "NO") {
			arr.pb(arr[(int)arr.size() - k + 1]);
		} else {
			arr.pb(res[id++]);
		}
	}
	for (string i: arr) {
		cout << i << ' ';
	}
}  

/*

AAAAA 2121212
*/