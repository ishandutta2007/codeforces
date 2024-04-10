#include <bits/stdc++.h>
using namespace std;

#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
vector<string> split(const string& s, char c) { vector<string> v; stringstream ss(s); string x; while (getline(ss, x, c)) v.push_back(move(x)); return v; }
void err(vector<string>::iterator it) {}
template<typename T, typename... Args> void err(vector<string>::iterator it, T a, Args... args) { cerr << it->substr((*it)[0] == ' ', it->length()) << " = " << a << '\n'; err(++it, args...); }

#define MAXN 103

char responses[MAXN];

char ask(int x) {
	cout << x << endl;
	string s;
	cin >> s;
	return responses[x] = s[0]; // 'y' or 'n' divide
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	ask(2);
	ask(3);
	ask(5);
	ask(7);

	int amt = 0;
	if (responses[2] == 'y') ++amt;
	if (responses[3] == 'y') ++amt;
	if (responses[5] == 'y') ++amt;
	if (responses[7] == 'y') ++amt;
	

	if (amt == 0) {
		// must be prime; 11^2 > 100
		cout << "prime" << endl;
		return 0;
	}

	if (amt > 1) {
		cout << "composite" << endl;
		return 0;
	}

	if (ask(4) == 'y' || ask(9) == 'y' || ask(25) == 'y' || ask(49) == 'y') {
		cout << "composite" << endl;
		return 0;
	}

	int otherprimes[] = {11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
	for (int x : otherprimes) {
		if (ask(x) == 'y') {
			cout << "composite" << endl;
			return 0;
		}
	}

	cout << "prime" << endl;
	return 0;
}