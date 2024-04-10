#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < (n); i++)
typedef long long int ll;

const ll inf = 1e18;

vector <vector <int> > perm;
vector <pair <int, int> > tocke;

ll izracunaj(int vel) {
	ll ret = inf;
	REP(i, (int)perm.size()) {
		ll tr = 0;
		int potezi[4][4] = {{0}};
		REP(j, (int)perm[i].size()) {
			pair <int, int> to = tocke[perm[i][j]], gdje = make_pair(0, 0);
			if(j == 1 || j == 3) gdje.second += vel;
			if(j == 2 || j == 3) gdje.first += vel;
			tr += abs(to.first - gdje.first) + abs(to.second - gdje.second);
			if(to.first >= gdje.first) potezi[j][0] = to.first - gdje.first;
			else potezi[j][1] = gdje.first - to.first;
			if(to.second >= gdje.second) potezi[j][2] = to.second - gdje.second;
			else potezi[j][3] = gdje.second - to.second;
		}
		//REP(j, 4) {
			//cout << j << endl;
			//REP(k, 4) {
				//cout << potezi[j][k] << " ";
			//}
			//cout << endl;
		//}
		REP(j, 4) {
			int kol = min(min(potezi[0][j], potezi[1][j]), min(potezi[2][j], potezi[3][j]));
			tr -= (ll) 4 * kol;
			potezi[0][j] -= kol;
			potezi[1][j] -= kol;
			potezi[2][j] -= kol;
			potezi[3][j] -= kol;
			if(potezi[0][j] && potezi[1][j] && potezi[2][j]) tr -= (ll) 2 * min(potezi[0][j], min(potezi[1][j], potezi[2][j]));
			if(potezi[0][j] && potezi[1][j] && potezi[3][j]) tr -= (ll) 2 * min(potezi[0][j], min(potezi[1][j], potezi[3][j]));
			if(potezi[0][j] && potezi[2][j] && potezi[3][j]) tr -= (ll) 2 * min(potezi[0][j], min(potezi[2][j], potezi[3][j]));
			if(potezi[3][j] && potezi[1][j] && potezi[2][j]) tr -= (ll) 2 * min(potezi[3][j], min(potezi[1][j], potezi[2][j]));
		}
		ret = min(ret, tr);
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	vector <int> tr;
	tr.push_back(0);
	tr.push_back(1);
	tr.push_back(2);
	tr.push_back(3);
	do {
		perm.push_back(tr);
	} while(next_permutation(tr.begin(), tr.end()));
	//perm.push_back(tr);
	int t;
	cin >> t;
	REP(tt, t) {
		tocke.clear();
		int a, b;
		REP(i, 4) {
			cin >> a >> b;
			tocke.push_back(make_pair(a, b));
		}
		int lo = 0, hi = 1e9 + 100, mid;
		//int lo = 2, hi = 2, mid;
		while(lo < hi) {
			mid = (lo + hi) / 2;
			ll r1 = izracunaj(mid), r2 = izracunaj(mid + 1);
			if(r1 > r2) lo = mid + 1;
			else hi = mid;
		}
		cout << izracunaj(lo) << "\n";
	}
	return 0;
}