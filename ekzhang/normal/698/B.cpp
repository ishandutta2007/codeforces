#include <bits/stdc++.h>
using namespace std;

#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
vector<string> split(const string& s, char c) { vector<string> v; stringstream ss(s); string x; while (getline(ss, x, c)) v.push_back(move(x)); return v; }
void err(vector<string>::iterator it) {}
template<typename T, typename... Args> void err(vector<string>::iterator it, T a, Args... args) { cerr << it->substr((*it)[0] == ' ', it->length()) << " = " << a << '\n'; err(++it, args...); }

#define MAXN 200013
int N;
int parent[MAXN];
int ufd[MAXN];
char label[MAXN];
int root = -1;
int ans = 0;

int f(int x) {
	if (ufd[x] == x) return x;
	return (ufd[x] = f(ufd[x]));
}

void u(int p, int c) {
	int x = f(p);
	int y = f(c);
	if (x == y) {
		label[x] = 'c';
	}
	ufd[y] = x;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N;
	for (int i = 0; i < N; i++) {
		label[i] = (char) 0;
		ufd[i] = i;
	}
	for (int i = 0; i < N; i++) {
		cin >> parent[i];
		parent[i]--;
		if (i == parent[i]) {
			root = i;
			label[i] = 't';
		}
		else {
			u(parent[i], i);
		}
	}

	if (root == -1) {
		root = f(0);
		parent[root] = root;
		ans++;
	}

	for (int i = 0; i < N; i++) {
		// assert(label[f(i)]);
		int x = f(i);
		if (x != root && parent[x] != root) {
			ans++;
			parent[x] = root;
		}
	}

	cout << ans << endl;
	for (int i = 0; i < N; i++) {
		cout << parent[i] + 1 << ' ';
	}
	cout << endl;
	return 0;
}