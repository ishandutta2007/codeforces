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
		vector <pair <int, int> > niz(n);
		int a;
		REP(i, n) {
			cin >> a;
			niz[i] = make_pair(a, i);
		}
		sort(niz.begin(), niz.end());
		vector <int> rj(n, -1);
		int tr = -1, ptr = 0;
		while(ptr < n) {
			tr = niz[ptr].first;
			int maxi = niz[ptr].second + 1, zad = niz[ptr].second;
			ptr++;
			while(ptr < n && niz[ptr].first == tr) {
				maxi = max(niz[ptr].second - zad, maxi);
				zad = niz[ptr].second;
				ptr++;
			}
			ptr--;
			maxi = max(maxi, n - zad);
			if(rj[maxi - 1] == -1) rj[maxi - 1] = niz[ptr].first;
			else rj[maxi - 1] = min(rj[maxi - 1], niz[ptr].first);
			ptr++;
		}
		int zad = -1;
		REP(i, n) {
			if(rj[i] != -1) {
				if(zad != -1) rj[i] = min(rj[i], zad);
			}
			else rj[i] = zad;
			zad = rj[i];
			cout << rj[i] << " ";
		}
		cout << "\n";
	}
	return 0;
}