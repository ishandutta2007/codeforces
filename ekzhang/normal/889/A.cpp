#include <bits/stdc++.h>
using namespace std;

#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
vector<string> split(const string& s, char c) { vector<string> v; stringstream ss(s); string x; while (getline(ss, x, c)) v.push_back(move(x)); return v; }
void err(vector<string>::iterator it) {}
template<typename T, typename... Args> void err(vector<string>::iterator it, T a, Args... args) { cerr << it->substr((*it)[0] == ' ', it->length()) << " = " << a << '\n'; err(++it, args...); }

#define MAXN 200013
int N;
int A[MAXN];
bool ok[MAXN];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N;
	ok[0] = true;
	int ans = 1;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
		if (ok[A[i]]) {
			ok[A[i]] = false;
		}
		else {
			++ans;
		}
		ok[i] = true;
	}

	cout << ans << endl;
	return 0;
}