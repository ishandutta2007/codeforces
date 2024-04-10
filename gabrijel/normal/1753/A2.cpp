#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < (n); i++)
typedef long long int ll;

vector <int> svi;
vector <pair <int, int> > rj;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	REP(tt, t) {
		int n, s = 0;
		cin >> n;
		svi.clear();
		svi.resize(n);
		REP(i, n) {
			cin >> svi[i];
			s += svi[i];
		}
		if(s % 2) {
			cout << -1 << "\n";
			continue;
		}
		s /= 2;
		bool uzeo = 1;
		int zad = -1;
		rj.clear();
		REP(i, n) {
			if(uzeo) {
				uzeo = 0;
				continue;
			}
			if(s > 0 && svi[i] == 1) {
				s--;
				uzeo = 1;
			}
			else if(s < 0 && svi[i] == -1) {
				s++;
				uzeo = 1;
			}
			else {
				rj.push_back(make_pair(zad + 1, i - 1));
				zad = i - 1;
			}
		}
		rj.push_back(make_pair(zad + 1, n - 1));
		cout << (int)rj.size() << "\n";
		for(pair <int, int> p : rj) {
			cout << p.first + 1 << " " << p.second + 1 << "\n";
		}
	}
	return 0;
}