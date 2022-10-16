/*input
3 3
1 2
1 3
2 1
*/
#include <bits/stdc++.h>

using namespace std;

long long pow(const long long &x, const unsigned long long &l, const unsigned long long &m) {
	if (l == 0) return 1;
	else if (l == 1) return x % m;
	else if (l == 2) return (x * x) % m;

	return ((pow(pow(x, l >> 1, m), 2, m) % m) * (l & 1ll ? x % m : 1ll)) % m;
}

const int long long MOD = 1000000007;
#define modd(x) (((x)%MOD + MOD)%MOD)

bool apl[100000] = {};
vector<int> gra[100000];
long long din[3][100000][11] = {};
int k, x;
int n, m;

void dfs(int v) {
	apl[v] = true;
	// 0 - >didz
	// 1 - <didz
	// 2 - didz

	din[0][v][0] = m - k - 1;
	din[1][v][0] = k;
	din[2][v][0] = 1;

	for (auto && x : gra[v]) {
		if (!apl[x]) {
			dfs(x);

			long long nauj[3][11] = {};

			for (int i = 0; i <= 10; i++) {
				for (int j = 0; j + i <= 10; j++) {
					//
					nauj[0][i + j] += modd(din[0][v][i] * modd(din[0][x][j] + din[1][x][j]));
					nauj[1][i + j] += modd(din[1][v][i] * modd(din[0][x][j] + din[1][x][j] + din[2][x][j]));
					nauj[2][i + j] += modd(din[2][v][i] * din[1][x][j]);
				}
			}

			for (int i = 0; i < 3; i++) {
				for (int j = 0; j <= 10; j++)
					din[i][v][j] = modd(nauj[i][j]);
			}
		}
	}

	for (int j = 10; j > 0; j--)
		din[2][v][j] = din[2][v][j - 1];

	din[2][v][0] = 0;
}

int main () {
	cin >> n >> m;
	long long ats = 0;
	//long long ats = pow(m - 1, n, MOD);


	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		gra[a].push_back(b);
		gra[b].push_back(a);
	}

	cin >> k >> x;
	k--;
	int st = 0;
	dfs(st);

	for (int i = 0; i <= x; i++) {
		ats += din[0][st][i];
		ats += din[1][st][i];
		ats += din[2][st][i];
		ats = modd(ats);
	}

	/*
		for (int i = 0; i <= x; i++) {
			cout << din[0][0][i] << endl;
			cout << din[1][0][i] << endl;
			cout << din[2][0][i] << endl;
		}
		cout << endl;

		for (int i = 0; i <= x; i++) {
			cout << din[0][2][i] << endl;
			cout << din[1][2][i] << endl;
			cout << din[2][2][i] << endl;
		}
		cout << endl;

		for (int i = 0; i <= x; i++) {
			cout << din[0][1][i] << endl;
			cout << din[1][1][i] << endl;
			cout << din[2][1][i] << endl;
		}
		cout << endl;*/

	cout << modd(ats);


	return 0;
}