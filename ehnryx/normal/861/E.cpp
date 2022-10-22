#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

//#define DEBUG
//#define USE_MAGIC_IO

#define ll long long
#define pii pair<int,int>
#define pdd pair<double,double>
#define ldouble long double
#define nl '\n'
const ll MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;

struct Test {
	string name;
	int type;
	Test(string name, int type) {
		this->name = name;
		this->type = type;
	}
	int to_int() {
		if (name[0] == '0') return -1;
		for (int i = 0; i < name.size(); i++) {
			if (isalpha(name[i]))
				return -1;
		}
		return stoi(name);
	}
};

int main() {
	ios::sync_with_stdio(0); 
	cin.tie(0); cout.tie(0);

	vector<string> examples, tests;
	stack<int> exdup, tdup;
	set<int> exempty, tempty;
	vector<Test> mess;
	string s;
	int type;
	int n;
	cin >> n;
	int ecnt = 0;
	for (int i = 0; i < n; i++) {
		cin >> s >> type;
		mess.push_back(Test(s, type));
		if (type == 1) ecnt++;
	}
	for (int i = 1; i <= ecnt; i++) 
		exempty.insert(i);
	for (int i = ecnt+1; i <= n; i++) 
		tempty.insert(i);
	// iterate through mess
	for (Test it: mess) {
		int id = it.to_int();
		if (it.type == 1) {
			if (id > ecnt && id <= n) {
				exdup.push(id);
				tempty.erase(id);
			} else if (id > 0 && id <= ecnt) {
				exempty.erase(id);
			} else {
				examples.push_back(it.name);
			}
		} else {
			if (id > 0 && id <= ecnt) {
				tdup.push(id);
				exempty.erase(id);
			} else if (id > ecnt && id <= n) {
				tempty.erase(id);
			} else {
				tests.push_back(it.name);
			}
		}
	}
	vector<string> ans;
	if (exempty.empty() && tempty.empty()) {
		if (!exdup.empty()) {
			ans.push_back("move " + to_string(exdup.top()) + " eugene");
			examples.push_back("eugene");
			tempty.insert(exdup.top());
			exdup.pop();
		} else if (!tdup.empty()) {
			ans.push_back("move " + to_string(tdup.top()) + " eugene");
			tests.push_back("eugene");
			exempty.insert(tdup.top());
			tdup.pop();
		}
	}
	while ((!exempty.empty() && !exdup.empty()) || (!tempty.empty() && !tdup.empty())) {
		while (!exempty.empty() && !exdup.empty()) {
			ans.push_back("move " + to_string(exdup.top()) + " " + to_string(*exempty.begin()));
			tempty.insert(exdup.top());
			exempty.erase(exempty.begin());
			exdup.pop();
		}
		while (!tempty.empty() && !tdup.empty()) {
			ans.push_back("move " + to_string(tdup.top()) + " " + to_string(*tempty.begin()));
			exempty.insert(tdup.top());
			tempty.erase(tempty.begin());
			tdup.pop();
		}
	}
	for (string s: examples) {
		ans.push_back("move " + s + " " + to_string(*exempty.begin()));
		exempty.erase(exempty.begin());
	}
	for (string s: tests) {
		ans.push_back("move " + s + " " + to_string(*tempty.begin()));
		tempty.erase(tempty.begin());
	}
	cout << ans.size() << nl;
	for (string s: ans) {
		cout << s << nl;
	}
	return 0;
}