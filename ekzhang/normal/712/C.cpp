#include <bits/stdc++.h>
using namespace std;

#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
vector<string> split(const string& s, char c) { vector<string> v; stringstream ss(s); string x; while (getline(ss, x, c)) v.push_back(move(x)); return v; }
void err(vector<string>::iterator it) {}
template<typename T, typename... Args> void err(vector<string>::iterator it, T a, Args... args) { cerr << it->substr((*it)[0] == ' ', it->length()) << " = " << a << '\n'; err(++it, args...); }

int X;
int Y[3];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> X >> Y[0];
	Y[1] = Y[2] = Y[0];

	int ans = 0;
	while (Y[2] < X) {
		Y[0] = Y[1];
		Y[1] = Y[2];
		Y[2] = Y[0] + Y[1] - 1;
		ans++;
	}

	cout << ans + 2 << endl;
	return 0;
}