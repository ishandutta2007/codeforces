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
#include <stack>
#include <deque>
#include <cassert>


using namespace std;


int n;



int main() {
	cin >> n;
	multiset<int> s;
	vector<pair<string, int> > ans;
	for (int i = 0; i < n; i++) {
		string ss;
		cin >> ss;	
		if (ss == "removeMin") {
			if (s.empty()) {
				ans.push_back(make_pair("insert", 1));
			} else {
				s.erase(s.find(*s.begin()));
			}
			ans.push_back(make_pair("removeMin", -1));
			continue;
		} 
		if (ss == "getMin") {
			int a;
			scanf("%d", &a);
			while (!s.empty() && *s.begin() < a) {
				ans.push_back(make_pair("removeMin", -1));
				s.erase(s.find(*s.begin()));
			}
			if (s.empty() || *s.begin() > a) {
				ans.push_back(make_pair("insert", a));
				s.insert(a);
			}
			ans.push_back(make_pair("getMin", a));
			continue;
		}
		int a;
		scanf("%d", &a);
		s.insert(a);
		ans.push_back(make_pair("insert", a));
	}
	cout << (int)ans.size() << endl;
	for (int i = 0; i < (int)ans.size(); i++) {
		string s = ans[i].first;
		int b = ans[i].second;
		if (s == "insert" || s == "getMin") {
			cout << s << ' ' << b << endl;
		} else {
			cout << s << endl;
		}
 	}
    return 0;
}