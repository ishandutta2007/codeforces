#include <bits/stdc++.h>
using namespace std;

#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
vector<string> split(const string& s, char c) { vector<string> v; stringstream ss(s); string x; while (getline(ss, x, c)) v.push_back(move(x)); return v; }
void err(vector<string>::iterator it) {}
template<typename T, typename... Args> void err(vector<string>::iterator it, T a, Args... args) { cerr << it->substr((*it)[0] == ' ', it->length()) << " = " << a << '\n'; err(++it, args...); }

int N;
string S;

inline bool isletter(char c) {
	return ('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z');
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> S;
	S = "_" + S + "_";
	N += 2;

	int longest = 0, number = 0;
	int start = -1;
	bool paren = false;
	for (int i = 0; i < N; i++) {
		char c = S[i];
		if (isletter(c)) {
			if (start == -1) {
				start = i;
			}
		}
		else {
			if (start != -1) {
				int len = i - start;
				start = -1;
				if (!paren) longest = max(longest, len);
				else number++;
			}
			if (c == '(') paren = true;
			else if (c == ')') paren = false;
		}
	}

	cout << longest << ' ' << number << endl;
	return 0;
}