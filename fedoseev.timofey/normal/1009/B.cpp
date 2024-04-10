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

int main() {
    ios_base::sync_with_stdio(false); cout.setf(ios::fixed); cout.precision(20); cout.tie(0); cin.tie(0);
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    string s;
    cin >> s;
    int cnt = 0;
    int n = s.size();
    int j = -1;
    for (int i = 0; i < n; ++i) {
    	if (s[i] == '0') ++cnt;
    	if (s[i] == '2') {
    		j = i;
    		break;
    	}
    }
    for (int i = 0; i < cnt; ++i) cout << '0';
    cnt = 0;
	for (int i = 0; i < n; ++i) if (s[i] == '1') ++cnt;
	for (int i = 0; i < cnt; ++i) cout << '1';
	if (j != -1) {
		for (int i = j; i < n; ++i) {
			if (s[i] != '1') {
				cout << s[i];
			}
		}
	}
}