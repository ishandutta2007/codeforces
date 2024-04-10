#include <bits/stdc++.h>
using namespace std;

#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
vector<string> split(const string& s, char c) { vector<string> v; stringstream ss(s); string x; while (getline(ss, x, c)) v.push_back(move(x)); return v; }
void err(vector<string>::iterator it) {}
template<typename T, typename... Args> void err(vector<string>::iterator it, T a, Args... args) { cerr << it->substr((*it)[0] == ' ', it->length()) << " = " << a << '\n'; err(++it, args...); }

string s;

string change(string ipt) {
	vector<string> v = split(ipt, '.');
	if (v.size() == 1) {
		return ipt + "0";
	} 
	if (v[1].size() == 1) {
		return v[0] + v[1];
	}
	else {
		string ret = v[0];
		ret += v[1][0];
		ret += '.';
		ret += v[1].substr(1);
		return ret;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> s;
	vector<string> v = split(s, 'e');
	string x = v[0];
	int po = stoi(v[1]);
	while (po > 0) {
		x = change(x);
		po--;
	}

	while (x.size() > 1 && x[0] == '0') {
		x = x.substr(1);
	}
	if (x[0] == '.') {
		x = "0" + x;
	}
	if (x.find('.') != -1) {
		while (x[x.size() - 1] == '0') {
			x = x.substr(0, x.size() - 1);
		}
	}
	if (x[x.size() - 1] == '.') {
		x = x.substr(0, x.size() - 1);
	}

	cout << x << endl;
	return 0;
}