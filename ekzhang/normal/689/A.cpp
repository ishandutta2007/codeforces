#include <bits/stdc++.h>
using namespace std;

#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
vector<string> split(const string& s, char c) { vector<string> v; stringstream ss(s); string x; while (getline(ss, x, c)) v.push_back(move(x)); return v; }
void err(vector<string>::iterator it) {}
template<typename T, typename... Args> void err(vector<string>::iterator it, T a, Args... args) { cerr << it->substr((*it)[0] == ' ', it->length()) << " = " << a << '\n'; err(++it, args...); }

int N;
int col[10] = {2, 1, 2, 3, 1, 2, 3, 1, 2, 3};
int row[10] = {4, 1, 1, 1, 2, 2, 2, 3, 3, 3};
bool data[6][6];

void yes() {
	cout << "YES" << endl;
}

void no() {
	cout << "NO" << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N;
	int maxcol = 0, maxrow = 0, mincol = 5, minrow = 5;
	string s;
	cin >> s;
	for (int i = 0; i < N; i++) {
		int r = row[s[i] - '0'];
		int c = col[s[i] - '0'];
		maxcol = max(maxcol, c);
		mincol = min(mincol, c);
		maxrow = max(maxrow, r);
		minrow = min(minrow, r);
		data[r][c] = true;
	}

	if (minrow != 1) { // can just shift up
		no(); return 0;
	}
	if (maxrow == 4) {
		yes(); return 0;
	}
	if (mincol != 1 || maxcol != 3 || maxrow != 3) {
		no(); return 0;
	}
	if (data[3][1] || data[3][3]) {
		yes(); return 0;
	}
	no(); return 0;

	cout.flush();
	return 0;
}