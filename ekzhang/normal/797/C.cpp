#include <bits/stdc++.h>
using namespace std;

#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
vector<string> split(const string& s, char c) { vector<string> v; stringstream ss(s); string x; while (getline(ss, x, c)) v.push_back(move(x)); return move(v); }
void err(vector<string>::iterator it) {}
template<typename T, typename... Args> void err(vector<string>::iterator it, T a, Args... args) { cerr << it->substr((*it)[0] == ' ', it->length()) << " = " << a << '\n'; err(++it, args...); }

string str;
vector<char> ans;
multiset<char> r;
stack<char> s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> str;
	int N = str.size();

	for (char c : str) {
		r.insert(c);
	}

	int idx = 0;
	for (int i = 0; i < N; i++) {
		if (r.empty() || (s.size() && s.top() <= *r.begin())) {
			ans.push_back(s.top());
			s.pop();
		}
		else {
			char c = *r.begin();
			while (str[idx] != c) {
				s.push(str[idx]);
				r.erase(r.find(str[idx]));
				idx++;
			}
			r.erase(r.find(str[idx]));
			idx++;
			ans.push_back(c);
		}
	}

	for (char c : ans) {
		cout << c;
	}
	cout << endl;
	return 0;
}