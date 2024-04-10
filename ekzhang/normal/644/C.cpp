#include <bits/stdc++.h>
using namespace std;

#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
vector<string> split(const string& s, char c) { vector<string> v; stringstream ss(s); string x; while (getline(ss, x, c)) v.push_back(move(x)); return v; }
void err(vector<string>::iterator it) {}
template<typename T, typename... Args> void err(vector<string>::iterator it, T a, Args... args) { cerr << it->substr((*it)[0] == ' ', it->length()) << " = " << a << '\n'; err(++it, args...); }

#define MAXN 100005
int N;
map<string, set<string>> ipt;
map<string, vector<string>> aux;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		int f = s.find('/', 7);
		if (f != string::npos) {
			ipt[s.substr(0, f)].insert(s.substr(f));
		}
		else {
			ipt[s].insert("");
		}
	}

	for (auto x : ipt) {
		string auxi = "";
		for (string s : x.second) {
			auxi += s;
			auxi += ',';
		}
		aux[auxi].push_back(x.first);
	}

	vector<string> ans;
	for (auto x : aux) {
		if (x.second.size() > 1) {
			ans.push_back(x.first);
		}
	}

	cout << ans.size() << '\n';
	for (string s : ans) {
		for (string x : aux[s]) {
			cout << x << ' ';
		}
		cout << '\n';
	}

	cout.flush();
	return 0;
}