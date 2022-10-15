#include <bits/stdc++.h>
using namespace std;

#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
vector<string> split(const string& s, char c) { vector<string> v; stringstream ss(s); string x; while (getline(ss, x, c)) v.push_back(move(x)); return v; }
void err(vector<string>::iterator it) {}
template<typename T, typename... Args> void err(vector<string>::iterator it, T a, Args... args) { cerr << it->substr((*it)[0] == ' ', it->length()) << " = " << a << '\n'; err(++it, args...); }

#define MAXN 113

int R, C;
string A[MAXN];
bool visited[MAXN][MAXN];

void dfs(int i, int j) {
	if (i < 0 || i >= R || j < 0 || j >= C ||
			A[i][j] == '.' || visited[i][j]) {
		return;
	}
	
	visited[i][j] = true;
	dfs(i - 1, j);
	dfs(i + 1, j);
	dfs(i, j - 1);
	dfs(i, j + 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		cin >> A[i];
	}

	int ans = 0;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (A[i][j] != '.' && !visited[i][j]) {
				ans++;
				dfs(i, j);
			}
		}
	}

	cout << ans << endl;
	return 0;
}