#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < (n); i++)
typedef long long int ll;

vector <pair <int, int> > polja;
vector <pair <int, int> > svi;
vector <bool> bio;
vector <vector <int> > graf;

void ff(int cvor) {
	bio[cvor] = 1;
	for(int sus : graf[cvor]) {
		if(!bio[sus]) ff(sus);
	}
	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	REP(tt, t) {
		int n, m, a, b, rj = 0;
		cin >> n >> m;
		polja.clear();
		svi.clear();
		bio.clear();
		graf.clear();
		polja.insert(polja.begin(), n, make_pair(-1, -1));
		bio.insert(bio.begin(), m, 0);
		graf.insert(graf.begin(), m, vector <int>());
		REP(i, m) {
			cin >> a >> b;
			a--; b--;
			if(a == b) {
				rj--;
				continue;
			}
			svi.push_back(make_pair(a, b));
			if(polja[a].first == -1) polja[a].first = i;
			else {
				polja[a].second = i;
				graf[i].push_back(polja[a].first);
				graf[polja[a].first].push_back(i);
			}
			if(polja[b].first == -1) polja[b].first = i;
			else {
				polja[b].second = i;
				graf[i].push_back(polja[b].first);
				graf[polja[b].first].push_back(i);
			}
		}
		REP(i, m) {
			if(graf[i].size() < 2) ff(i);
		}
		REP(i, m) {
			if(!bio[i]) {
				rj++;
				ff(i);
			}
		}
		cout << m + rj << endl;
	}
	return 0;
}