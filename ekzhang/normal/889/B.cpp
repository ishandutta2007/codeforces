#include <bits/stdc++.h>
using namespace std;

#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
vector<string> split(const string& s, char c) { vector<string> v; stringstream ss(s); string x; while (getline(ss, x, c)) v.push_back(move(x)); return v; }
void err(vector<string>::iterator it) {}
template<typename T, typename... Args> void err(vector<string>::iterator it, T a, Args... args)
{ cerr << it->substr((*it)[0] == ' ', it->length()) << " = " << a << '\n'; err(++it, args...); }

#define MAXN 100013
#define INF MAXN
int N;
string S;
map<int, int> G[26];
int dist[26];
bool visited[MAXN];
vector<string> stuff;

void bad() {
	cout << "NO" << endl;
	exit(0);
}

void add(char c1, char c2, int d) {
	int a = c1 - 'a';
	int b = c2 - 'a';
	if (G[a].count(b) && G[a][b] != d) {
		bad();
	}
	G[a][b] = d;
	G[b][a] = -d;
}

void dfs(int n) {
	visited[n] = true;
	for (pair<int, int> p : G[n]) {
		int v = p.first;
		if (dist[v] == INF) {
			dist[v] = dist[n] + p.second;
			dfs(v);
		}
		else {
			if (dist[v] != dist[n] + p.second) {
				bad();
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> S;
		for (int j = 0; j < S.size(); j++) {
			add(S[0], S[j], j);
		}
	}

	for (int i = 0; i < 26; i++) {
		// not seen in any string
		if (G[i].empty()) continue;

		// done
		if (visited[i]) continue;

		for (int j = 0; j < 26; j++) {
			dist[j] = INF;
		}
		dist[i] = 0;
		dfs(i);

		int mindist = 0;
		int maxdist = 0;
		for (int j = 0; j < 26; j++) {
			if (dist[j] != INF) {
				mindist = min(mindist, dist[j]);
				maxdist = max(maxdist, dist[j]);
			}
		}
		string s(maxdist - mindist + 1, ' ');
		for (int j = 0; j < 26; j++) {
			if (dist[j] != INF) {
				if (s[dist[j] - mindist] != ' ') bad();
				s[dist[j] - mindist] = 'a' + j;
			}
		}
		stuff.push_back(s);
	}

	sort(stuff.begin(), stuff.end());

	string ans = "";
	for (string s : stuff) {
		ans += s;
	}

	cout << ans << endl;
	return 0;
}