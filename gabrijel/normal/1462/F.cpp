#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < (n); i++)
typedef long long int ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	REP(tt, t) {
		int n;
		cin >> n;
		int a, b;
		vector <int> pocetci;
		vector <pair <int, int> > eve, svi;
		vector <int> :: iterator it, it2;
		REP(i, n) {
			cin >> a >> b;
			pocetci.push_back(a);
			eve.push_back(make_pair(a, 0));
			eve.push_back(make_pair(b, 1));
			svi.push_back(make_pair(a, b));
		}
		sort(pocetci.begin(), pocetci.end());
		sort(eve.begin(), eve.end());
		sort(svi.begin(), svi.end());
		int kolko = 0, ptr = 0, maxi = 0;
		it = pocetci.begin();
		for(pair <int, int> tr : svi) {
			//cout << "radim: " << tr.first << " " << tr.second << endl;
			//cout << eve[ptr].first << " " << eve[ptr].second << endl;
			while(it != pocetci.end() && (*it) <= tr.first) it++;
			while(ptr < (int)eve.size() && eve[ptr].first < tr.first) {
				//cout << "hej" << endl;
				kolko--;
				ptr++;
			}
			while(ptr < (int)eve.size() && eve[ptr].first <= tr.first && eve[ptr].second == 0) {
				//cout << "hej" << endl;
				kolko++;
				ptr++;
			}
			//cout << tr.first << " " << tr.second << " " << kolko << endl;
			it2 = upper_bound(pocetci.begin(), pocetci.end(), tr.second);
			int dod = it2 - it;
			maxi = max(maxi, kolko + dod);
		}
		cout << n - maxi << "\n";
	}
	return 0;
}