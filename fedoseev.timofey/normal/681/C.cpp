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
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;
    multiset <int> cur;
    vector <pair <string, int>> kek;
    for (int i = 0; i < n; ++i) {
    	string s;
    	cin >> s;
    	if (s == "removeMin") {
    		if (cur.empty()) {
    			kek.emplace_back("insert", 0);
    			cur.insert(1);
    		}
    		kek.emplace_back("removeMin", -1);
    		cur.erase(cur.begin());
       	}
       	else if (s == "insert") {
       		int a;
       		cin >> a;
       		cur.insert(a);
       		kek.emplace_back("insert", a);
       	}
       	else {
       		int a;
       		cin >> a;
       		while (!cur.empty() && (*cur.begin()) < a) {
       			kek.emplace_back("removeMin", -1);
       			cur.erase(cur.begin());
       		}
       		if (cur.empty() || (*cur.begin()) != a) {
       			kek.emplace_back("insert", a);
       			cur.insert(a);
       		}
       		kek.emplace_back("getMin", a);
       	}
    }
    cout << kek.size() << '\n';
    for (auto p : kek) {
    	if (p.first == "removeMin") cout << p.first << '\n';
    	else cout << p.first << ' ' << p.second << '\n';
    }
}