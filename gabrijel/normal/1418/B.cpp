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
		vector <int> niz(n);
		vector <int> zak(n);
		vector <int> slob;
		slob.clear();
		REP(i, n) {
			cin >> niz[i];
		}
		REP(i, n) {
			cin >> zak[i];
			if(!zak[i]) slob.push_back(niz[i]);
		}
		sort(slob.begin(), slob.end());
		int mini = n + 1, suma, tr;
		vector <int> rj;
		for(int i = 0; i <= (int)slob.size(); i++) {
			int ind = 0, ind_poc = 0;
			suma = 0;
			tr = 0;
			REP(j, n) {
				if(!zak[j]) {
					if(ind < i) {
						niz[j] = slob[(int)slob.size() - 1 - ind];
						ind++;
					}
					else {
						niz[j] = slob[ind_poc];
						ind_poc++;
					}
				}
				suma += niz[j];
				if(suma < 0) tr = j + 1;
			}
			if(tr < mini) {
				mini = tr;
				rj = niz;
			}
		}
		REP(i, n) cout << rj[i] << " ";
		cout << "\n";
	}
	return 0;
}