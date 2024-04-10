#include <bits/stdc++.h>
using namespace std;

#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
vector<string> split(const string& s, char c) { vector<string> v; stringstream ss(s); string x; while (getline(ss, x, c)) v.push_back(move(x)); return move(v); }
void err(vector<string>::iterator it) {}
template<typename T, typename... Args> void err(vector<string>::iterator it, T a, Args... args) { cerr << it->substr((*it)[0] == ' ', it->length()) << " = " << a << '\n'; err(++it, args...); }

#define MAXN 1000013
int N;
string s1, s2;
int amt[4];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> s1 >> s2;
	for (int i = 0; i < 2 * N; i++) {
		amt[2 * (s1[i] - '0') + (s2[i] - '0')]++;
	}

	int f = 0, s = 0;
	if (amt[3] % 2) {
		amt[1]--;
	}

	if (amt[2] > amt[1]) {
		cout << "First";
	}
	else if (amt[1] > amt[2] + 1) {
		cout << "Second";
	}
	else {
		cout << "Draw";
	}

	cout << endl;
	return 0;
}