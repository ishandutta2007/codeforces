#include <bits/stdc++.h>

#define itn int
#define LL long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(x) (x).begin(), (x).end()

using namespace std;

inline int nxt(){
	int x;
	scanf("%d", &x);
	return x;
}

void solve(){
	int n = nxt(), k = nxt();
	string a[3];
	for (int i = 0; i < 3; i++)
		cin >> a[i];
	string dts = "";
	for (int i = 0; i < 500; i++)
		dts += ".";
	for (int i = 0; i < 3; i++)
		a[i] += dts;
	int ind = 0;
	while (a[ind][0] != 's')
		ind++;
	a[ind][0] = '.';
	int m = 3 * (n - 1);
	char ok[3][a[0].length()];
	for (int i = 0; i < 3; i++){
		ok[i][m] = (a[i][m] == '.');
	}
	for (int i = m - 3; i >= 0; i -= 3){
		for (int j = 0; j < 3; j++){
			ok[j][i] = 0;
			for (int ij = 0; ij < 3; ij++){
				if (abs(ij - j) < 2){
					ok[j][i] |= (a[ij][i + 1] == '.' && a[ij][i + 2] == '.' && a[ij][i + 3] == '.' && ok[ij][i + 3]);
				}
			}
			ok[j][i] &= (a[j][i] == '.' && a[j][i + 1] == '.');
			// if (ok[j][i])
				// cerr << "\nxui: " << j << " " << i << "\n";
		}
	}
	puts(ok[ind][0] ? "YES" : "NO");
}

int main(){

	int t = nxt();
	while (t--){
		solve();
	}

	return 0;
}