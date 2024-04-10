#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <ctime>
#include <random>
#include <cmath>
#include <bitset>
#include <iomanip>
#include <list>
#include <unordered_set>
#include <unordered_map>
#include <cassert>

using namespace std;

typedef long long ll;
typedef long double ld;

int query(int x, int y) {
	cout << x << ' ' << y << endl;
	string s;
	cin >> s;
	if (s == "white") return 1;
	else return 2;
}

const int Inf = 1e9;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;
    int minx = 0;
    int maxx = 1e9;
    int cnt = 0;
    int kek = query(0, 1);
    for (int i = 1; i < n; ++i) {
    	int cx;
    	if (((minx + maxx) % 2) == 0) {
    		cx = (minx + maxx) / 2;
    	}
    	else if (cnt % 2) {
    		cx = (minx + maxx) / 2;
    		++cnt;
    	}
    	else {
    		cx = (minx + maxx + 1) / 2;
    		++cnt;
    	}
    	if (query(cx, 1) == kek) {
    		minx = cx;
    	}
    	else {
    		maxx = cx;
    	}
    }
    int ansx;
    if (((minx + maxx) % 2) == 0) {
    	ansx = (minx + maxx) / 2;
    }
    else if (cnt % 2) {
    	ansx = (minx + maxx) / 2;
    }
    else {
    	ansx = (minx + maxx + 1) / 2;
    }
    if (ansx != minx && ansx != maxx) {
    	cout << "0 0 " << ansx << ' ' << 1 << endl;
	}
	else {
		cout << minx << ' ' << 0 << ' ' << maxx << ' ' << 2 << endl;
	}
}