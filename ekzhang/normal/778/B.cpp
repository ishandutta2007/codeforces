#include <bits/stdc++.h>
using namespace std;

#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
vector<string> split(const string& s, char c) { vector<string> v; stringstream ss(s); string x; while (getline(ss, x, c)) v.push_back(move(x)); return v; }
void err(vector<string>::iterator it) {}
template<typename T, typename... Args> void err(vector<string>::iterator it, T a, Args... args) { cerr << it->substr((*it)[0] == ' ', it->length()) << " = " << a << '\n'; err(++it, args...); }

#define MAXN 5013
int N, M;
bool isv[MAXN];
string con[MAXN];
pair<char, pair<int, int> > var[MAXN];
map<string, int> ntoi;

int compute(int b, bool v) {
	bool vals[MAXN];
	for (int i = 0; i < N; i++) {
		if (!isv[i])
			vals[i] = con[i][b] - '0';
	}
	vals[N] = v;
	for (int i = 0; i < N; i++) {
		if (!isv[i]) continue;

		char op = var[i].first;
		int x = var[i].second.first, y = var[i].second.second;
		if (op == 'O') vals[i] = vals[x] | vals[y];
		if (op == 'X') vals[i] = vals[x] ^ vals[y];
		if (op == 'A') vals[i] = vals[x] & vals[y];
	}
	int ret = 0;
	for (int i = 0; i < N; i++) {
		ret += vals[i];
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> M;
	string line;
	getline(cin, line);
	ntoi["?"] = N;
	for (int i = 0; i < N; i++) {
		getline(cin, line);
		vector<string> v = split(line, ' ');
		ntoi[v[0]] = i;
		if (v.size() == 3) {
			con[i] = v[2];
		}
		else {
			isv[i] = true;
			var[i] = {v[3][0], {ntoi[v[2]], ntoi[v[4]]}};
		}
	}

	string mi(M, '0'), ma(M, '0');
	for (int b = 0; b < M; b++) {
		int c0 = compute(b, 0);
		int c1 = compute(b, 1);
		if (c1 > c0) {
			ma[b] = '1';
		}
		if (c1 < c0) {
			mi[b] = '1';
		}
	}

	cout << mi << endl << ma << endl;
	return 0;
}