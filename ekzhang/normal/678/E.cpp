#include <bits/stdc++.h>
using namespace std;

#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
vector<string> split(const string& s, char c) { vector<string> v; stringstream ss(s); string x; while (getline(ss, x, c)) v.push_back(move(x)); return v; }
void err(vector<string>::iterator it) {}
template<typename T, typename... Args> void err(vector<string>::iterator it, T a, Args... args) { cerr << it->substr((*it)[0] == ' ', it->length()) << " = " << a << '\n'; err(++it, args...); }

// lol hax
// #define double long double

#define MAXN 18
#define MAXMASK (1<<MAXN)

int N;
double P[MAXN][MAXN];
double win[MAXMASK];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N;
	for (int i = 0; i < N; i++)	{
		for (int j = 0; j < N; j++) {
			cin >> P[i][j];
		}
	}

	int lim = 1<<(N-1);
	for (int mask = 0; mask < lim; mask++) {
		win[mask] = -1; // lol
	}
	
	win[0] = 1; // if guy is only person, he win!
	for (int i = 1; i < N; i++) {
		win[1<<(i-1)] = P[0][i];
	}

	// O(n^2 * 2^n) bitmask dp
	for (int mask = 1; mask < lim; mask++) {
		if (win[mask] != -1) continue;

		for (int i = 0; i < N - 1; i++) {
			if (!(mask & (1 << i))) continue;
			for (int j = i + 1; j < N - 1; j++) {
				if (!(mask & (1 << j))) continue;

				win[mask] = max(win[mask], P[i + 1][j + 1] * win[mask ^ (1<<j)] +
						P[j + 1][i + 1] * win[mask ^ (1<<i)]);
			}
		}
	}

	cout << win[lim - 1] << endl;
	return 0;
}