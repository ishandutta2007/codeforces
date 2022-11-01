#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < (n); i++)
typedef long long int ll;

vector <int> svi;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, x, a;
	cin >> n >> x;
	svi.resize(x + 1, 0);
	REP(i, n) {
		cin >> a;
		svi[a]++;
		while(a < x && svi[a] == a + 1) {
			svi[a] = 0;
			a++;
			svi[a]++;
		}
	}
	bool ok = 1;
	REP(i, x) if(svi[i]) ok = 0;
	cout << (ok ? "Yes\n" : "No\n");
	return 0;
}