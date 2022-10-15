#include <bits/stdc++.h>
using namespace std;

#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
vector<string> split(const string& s, char c) { vector<string> v; stringstream ss(s); string x; while (getline(ss, x, c)) v.push_back(move(x)); return v; }
void err(vector<string>::iterator it) {}
template<typename T, typename... Args> void err(vector<string>::iterator it, T a, Args... args) { cerr << it->substr((*it)[0] == ' ', it->length()) << " = " << a << '\n'; err(++it, args...); }

#define MAXN 100013
int N;
int A[2 * MAXN];
int idx;

void bad() {
	cout << "Error occurred" << endl;
	exit(0);
}

void dfs() {
	if (idx >= 2 * N - 1) bad();
	if (A[idx++] == 2) {
		dfs();
		dfs();
	}
}

void go() {
	if (A[idx++] == 2) {
		cout << "pair<";
		go();
		cout << ",";
		go();
		cout << ">";
	}
	else {
		cout << "int";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N;
	for (int i = 0; i < 2 * N - 1; i++) {
		string s; cin >> s;
		if (!cin) bad();
		if (s[0] == 'p') {
			A[i] = 2;
		}
		else {
			A[i] = 1;
		}
	}

	string extra;
	if (cin >> extra) bad();

	idx = 0;
	dfs();
	if (idx != 2 * N - 1) bad();

	idx = 0;
	go();

	cout << endl;
	return 0;
}