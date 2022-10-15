#include <bits/stdc++.h>
using namespace std;

#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
vector<string> split(const string& s, char c) { vector<string> v; stringstream ss(s); string x; while (getline(ss, x, c)) v.push_back(move(x)); return v; }
void err(vector<string>::iterator it) {}
template<typename T, typename... Args> void err(vector<string>::iterator it, T a, Args... args) { cerr << it->substr((*it)[0] == ' ', it->length()) << " = " << a << '\n'; err(++it, args...); }

#define MAXN 1013
int N, M;
int ufd[MAXN];

int find(int x) {
	if (ufd[x] == x) return x;
	return (ufd[x] = find(ufd[x]));
}

void join(int x, int y) {
	int x1 = find(x), y1 = find(y);
	ufd[y1] = x1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> M;
	if (M != N - 1) {
		cout << "no" << endl;
		return 0;
	}
	for (int i = 0; i < N; i++) {
		ufd[i] = i;
	}

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		join(a, b);
	}

	for (int i = 1; i < N; i++) {
		if (find(i) != find(0)) {
			cout << "no" << endl;
			return 0;
		}
	}

	cout << "yes" << endl;
	return 0;
}