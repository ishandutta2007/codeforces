#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < (n); i++)
typedef long long int ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector <int> svi(n);
	vector <int> popuni2, popuni3;
	vector <pair <int, int> > rj;
	REP(i, n) {
		cin >> svi[i];
		if(svi[i] == 0) continue;
		else if(svi[i] == 1) {
			if(popuni2.size()) {
				rj.push_back(make_pair(popuni2.back(), i));
				popuni2.pop_back();
			}
			else {
				if(popuni3.size()) {
					rj.push_back(make_pair(popuni3.back(), i));
					popuni3.pop_back();
				}
				rj.push_back(make_pair(i, i));
			}
		}
		else if(svi[i] == 2) {
			if(popuni3.size()) {
				rj.push_back(make_pair(popuni3.back(), i));
				popuni3.pop_back();
			}
			rj.push_back(make_pair(i, i));
			popuni2.push_back(i);
		}
		else {
			if(popuni3.size()) {
				rj.push_back(make_pair(popuni3.back(), i));
				popuni3.pop_back();
			}
			rj.push_back(make_pair(i, i));
			popuni3.push_back(i);
		}
	}
	if(popuni2.size() || popuni3.size()) {
		cout << -1 << "\n";
	}
	else {
		cout << (int)rj.size() << "\n";
		REP(i, (int)rj.size()) {
			cout << rj[i].first + 1 << " " << rj[i].second + 1 << "\n";
		}
	}
	return 0;
}