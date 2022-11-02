#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < (n); i++)
typedef long long int ll;

vector <vector <int> > graf;

vector <bool> smije, bio;
vector <int> rj;

void rek(int cvor) {
	bio[cvor] = 1;
	if(smije[cvor]) {
		smije[cvor] = 0;
		rj.push_back(cvor);
		for(int sus : graf[cvor]) {
			smije[sus] = 0;
		}
	}
	for(int sus : graf[cvor]) if(!bio[sus]) rek(sus);
	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	REP(tt, t) {
		int n, m;
		cin >> n >> m;
		graf.clear();
		smije.clear();
		bio.clear();
		rj.clear();
		graf.resize(n, vector <int>());
		smije.resize(n, 1);
		bio.resize(n, 0);
		int a, b;
		REP(i, m) {
			cin >> a >> b;
			a--; b--;
			graf[a].push_back(b);
			graf[b].push_back(a);
		}
		rek(0);
		bool moze = 1;
		REP(i, n) {
			if(!bio[i]) {
				moze = 0;
				break;
			}
		}
		if(moze) {
			cout << "YES\n";
			cout << rj.size() << "\n";
			for(int r : rj) cout << r + 1 << " ";
			cout << "\n";
		}
		else cout << "NO\n";
	}
	return 0;
}