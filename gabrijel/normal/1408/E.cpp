#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < (n); i++)
typedef long long int ll;

vector <int> rod;

int daj_rod(int x) {
	if(rod[x] == x) return x;
	return rod[x] = daj_rod(rod[x]);
}

void spoji(int a, int b) {
	int ra = daj_rod(a), rb = daj_rod(b);
	rod[ra] = rb;
	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int m, n;
	cin >> m >> n;
	rod.resize(n + m);
	REP(i, n + m) rod[i] = i;
	vector <int> a(m), b(n);
	REP(i, m) cin >> a[i];
	REP(i, n) cin >> b[i];
	vector <pair <int, pair <int, int> > > veze;
	ll suma = 0, rj = 0;
	REP(i, m) {
		int c, d;
		cin >> c;
		REP(j, c) {
			cin >> d;
			d--;
			suma += a[i] + b[d];
			veze.push_back(make_pair(a[i] + b[d], make_pair(i, m + d)));
		}
	}
	sort(veze.begin(), veze.end());
	reverse(veze.begin(), veze.end());
	REP(i, (int)veze.size()) {
		int c = veze[i].second.first, d = veze[i].second.second;
		if(daj_rod(c) == daj_rod(d)) continue;
		spoji(c, d);
		rj += veze[i].first;
	}
	cout << suma - rj << endl;
	return 0;
}