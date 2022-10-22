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

struct Eugene {
	unordered_map<string,int> count;
	void add(const string& s) {
		unordered_set<string> toadd;
		for (int len = 1; len <= 10; len++) {
			for (int i = 0; i+len < 10; i++) {
				toadd.insert(s.substr(i,len));
			}
		}
		for (string s: toadd) {
			count[s]++;
		}
	}
	string check(const string& s) {
		for (int len = 1; len <= 10; len++) {
			for (int i = 0; i+len < 10; i++) {
				if (count[s.substr(i,len)] == 1)
					return s.substr(i,len);
			}
		}
	}
};

int main() {
	ios::sync_with_stdio(0); 
	cin.tie(0); cout.tie(0);

	vector<string> memo;
	string number;
	Eugene book;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> number;
		memo.push_back(number);
		book.add(number);
	}
	for (int i = 0; i < n; i++) {
		cout << book.check(memo[i]) << nl;
	}

	return 0;
}