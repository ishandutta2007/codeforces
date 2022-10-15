#include <bits/stdc++.h>
using namespace std;

#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
vector<string> split(const string& s, char c) { vector<string> v; stringstream ss(s); string x; while (getline(ss, x, c)) v.push_back(move(x)); return v; }
void err(vector<string>::iterator it) {}
template<typename T, typename... Args> void err(vector<string>::iterator it, T a, Args... args) { cerr << it->substr((*it)[0] == ' ', it->length()) << " = " << a << '\n'; err(++it, args...); }

#define MAX 2000000013
#define MAXN 100013
int N;
int A[MAXN];
long long ans = 0;
map<int, int> m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	for (int lg = 0; lg <= 30; lg++) {
		int x = (1<<lg);
		m.clear();
		for (int i = 0; i < N; i++) {
			// error(x, A[i]);
			ans += m[x - A[i]];
			m[A[i]]++;
		}
	}

	cout << ans << endl;
	return 0;
}