#include <iostream>
#include <sstream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <cstdio>
#include <cmath>
#include <map>
#include <set>
#include <unordered_set>


using namespace std;



int n;
int a[200001];
multiset<int> s[3];
map<int, vector<int> > m;
map<int, int> m1;


int main() {	
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		s[a % 3].insert(a);
		m[a].push_back(i);
	}
	int t = 0;
	vector<int> ans;
	int k = 0;
	for (int i = 0; i < n; i++) {
		if (s[t].empty()) {
			cout << "Impossible" << endl;
			return 0;
		}
		if (i == 0) {
			if (s[t].find(0) == s[t].end()) {
				cout << "Impossible" << endl;
				return 0;
			}
			s[t].erase(s[t].find(0));
			ans.push_back(0);
		} else {
			//cout << ans.back() << endl;
			if (s[t].find(ans.back() + 1) != s[t].end()) {
				//cout << i + 1 << endl;
				ans.push_back(ans.back() + 1);
				s[t].erase(s[t].find(ans.back()));
			} else {
				if (*(s[t].begin()) > ans.back()) {
					cout << "Impossible" << endl;
					return 0;
				}
				int l = 1;
				int r = (ans.back() + 1 - *(s[t].begin())) / 3;
				while (l != r) {
					int m = (l + r) / 2;
					if (s[t].lower_bound(ans.back() + 1 - m * 3) != s[t].end() && *(s[t].lower_bound(ans.back() + 1 - m * 3)) < ans.back()) {
						r = m;
					} else {
						l = m + 1;
					}
				}
				if ((i + 1) / 3 - k >= l) {
					k += l;
					//cout << ans.back() - l * 3 << endl;
					//cout << i + 1 << endl;
					ans.push_back(ans.back() + 1 - l * 3);
					//cout << ans.back() - l * 3 << endl;
					s[t].erase(s[t].find(ans.back()));
				} else {
					cout << "Impossible" << endl;
					return 0;
				}
			}
		}
		//cout << "opa" << endl;
		t++;
		t %= 3;
	}
	cout << "Possible" << endl;
	for (int i = 0; i < n; i++) {
		cout << m[ans[i]][m1[ans[i]]] + 1 << ' ';
		m1[ans[i]]++;
	}
	cout << endl;
	return 0;
}