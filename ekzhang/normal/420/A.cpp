#include <bits/stdc++.h>
using namespace std;

#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
vector<string> split(const string& s, char c) { vector<string> v; stringstream ss(s); string x; while (getline(ss, x, c)) v.push_back(move(x)); return v; }
void err(vector<string>::iterator it) {}
template<typename T, typename... Args> void err(vector<string>::iterator it, T a, Args... args) { cerr << it->substr((*it)[0] == ' ', it->length()) << " = " << a << '\n'; err(++it, args...); }

char mirror[26] = {'A', 0, 0, 0, 0, 0, 0, 'H', 'I', 0, 0, 0, 'M', 0, 'O',
						0, 0, 0, 0, 'T', 'U', 'V', 'W', 'X', 'Y', 0};

#define MAXN 100013

int N;
string s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> s;
	N = s.size();
	for (int i = 0; i < N; i++) {
		if (!mirror[s[i] - 'A'] || mirror[s[i] - 'A'] != s[N - 1 - i]) {
			cout << "NO" << endl;
			return 0;
		}
	}

	cout << "YES" << endl;
	return 0;
}