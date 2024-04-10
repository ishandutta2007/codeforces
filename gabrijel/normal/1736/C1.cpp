#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < (n); i++)
typedef long long int ll;

vector <int> svi, dokud;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	REP(tt, t) {
		int n;
		cin >> n;
		svi.clear();
		svi.resize(n);
		dokud.clear();
		dokud.resize(n, n);
		REP(i, n) cin >> svi[i];
		ll rj = 0;
		int mini = n - 1;
		for(int i = n - 1; i >= 0; i--) {
			int tr = i + 1 - svi[i];
			if(tr > 0) {
				if(tr > i) mini = min(mini, tr);
				dokud[tr] = min(dokud[tr], i);
			}
			if(i < n - 1) mini = min(mini, dokud[i + 1] - 1);
			//cout << mini << endl;
			rj += mini - i + 1;
		}
		cout << rj << "\n";
	}
	return 0;
}