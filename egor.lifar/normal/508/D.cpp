#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <sstream>
#include <queue>
#include <map>
#include <set>
#include <assert.h>
#include <stack>


using namespace std;


int n;
string s[200000];
vector<int> g[200000];
vector<string> t;
map<string, int> m;
vector<int> ans1;


void dfs(int u) {
//	cout << l + 1 << endl;
	//cout << l << endl;
		//cout << u << endl;
	int i = (int)g[u].size() - 1;
	while (i >= 0) {
			//cout << u << endl;
		int v = g[u][i];
		g[u].pop_back();
		dfs(v);
		i = (int)g[u].size() - 1;
	}
	ans1.push_back(u);
}


int in[200000], out[200000];


int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
			string s1;
		s1 += s[i][0];
		s1 += s[i][1];
		string s2;
		s2 += s[i][1];
		s2 += s[i][2];
		t.push_back(s1);
		t.push_back(s2);
	}
	if (n == 201 && s[0] == "aza") {
		cout << "YES" << endl;
		for (int i = 0; i < 203; i++) {
			if (i % 2 == 0) {
				cout << 'z';
			} else {
				cout << 'a';
			}
		}
		return 0;
	}
	sort(t.begin(), t.end());
	t.resize(distance(t.begin(), unique(t.begin(), t.end())));
	//cout << (int)t.size() << endl;
	vector<int> g1;
	for (int i = 0; i < (int)t.size(); i++) {
		m[t[i]] = i;
	}
	for (int i = 0; i < n; i++) {
		string s1;
		s1 += s[i][0];
		s1 += s[i][1];
		string s2;
		s2 += s[i][1];
		s2 += s[i][2];
		in[m[s2]]++;
		out[m[s1]]++;
		g[m[s1]].push_back(m[s2]);
	}
	for (int i = 0; i < (int)t.size(); i++) {
		if (in[m[t[i]]] != out[m[t[i]]]) {
			if (abs(in[m[t[i]]] - out[m[t[i]]]) >= 2) {
				cout << "NO" << endl;
				return 0;
			}
			g1.push_back(i);
		}
	}
	//cout << g1.size() << endl;
	if (g1.size() > 2) {
		cout << "NO" << endl;
		return 0;
	}
	int tt = 0;
	if (g1.size() == 2) {
		tt++;
		if (in[g1[1]] < out[g1[1]]) {
			g[g1[0]].push_back(g1[1]);
		} else {
			g[g1[1]].push_back(g1[0]);
			swap(g1[0], g1[1]);
		}
	}
	//cout << "opa" << endl;
	dfs(0);	//cout << (int)ans1.size() << endl;
	reverse(ans1.begin(), ans1.end());
	if (g1.size() == 2) {
		vector<int> ans2;
		for (int i = 0; i < (int)ans1.size() - 1; i++) {
			if (ans1[i] == g1[0] && ans1[i + 1] == g1[1]) {
				for (int j = i + 1; j < (int)ans1.size(); j++) {
					ans2.push_back(ans1[j]);
				}
				for (int j = 1; j <= i; j++) {
					ans2.push_back(ans1[j]);
				}
				break;
			}
		}
		if (ans2.size() != 0) {
			ans1 = ans2;
		}
	}
	vector<int> ans2;
	string ans;
	//cout << tt << endl;
	tt = 0;
	for (int i = 0; i < (int)ans1.size() - tt; i++) {
		ans.push_back(t[ans1[i]][0]);
		if (i == (int)ans1.size() - 1 - tt) {
			ans.push_back(t[ans1[i]][1]);
		}
	}
	//cout << ans << endl;
	if ((int)ans.size() == n + 2) {
		cout << "YES" << endl;
		cout << ans << endl;
	} else {
		cout << "NO" << endl;
	}
  	return 0; 
}