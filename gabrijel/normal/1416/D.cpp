#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < (n); i++)
typedef long long int ll;

const int maxn = 200100;
const int maxm = 300100;

const int inf = 1e9;
const int offset = (1 << 18);

struct tournament {
	int maxi[2 * offset];
	void build() {
		REP(i, 2 * offset) {
			maxi[i] = 0;
		}
	}
	void dolje(int tr, int l, int r, int vr) {
		if(l == r) {
			maxi[tr] = 0;
			return;
		}
		int mid = (l + r) / 2;
		if(maxi[tr * 2] == maxi[tr]) dolje(tr * 2, l, mid, vr);
		else dolje(tr * 2 + 1, mid + 1, r, vr);
		maxi[tr] = max(maxi[tr * 2], maxi[tr * 2 + 1]);
		return;
	}
	void makni_najvecu(int tr, int a, int b, int l, int r, int vr) {
		if(l > b || r < a) return;
		if(l >= a && r <= b && maxi[tr] != vr) return;
		else if(l >= a && r <= b) {
			dolje(tr, l, r, vr);
			return;
		}
		int mid = (l + r) / 2;
		makni_najvecu(tr * 2, a, b, l, mid, vr);
		makni_najvecu(tr * 2 + 1, a, b, mid + 1, r, vr);
		maxi[tr] = max(maxi[tr * 2], maxi[tr * 2 + 1]);
		return;
	}
	void postavi_vr(int tr, int a, int l, int r, int vr) {
		if(l == r) {
			maxi[tr] = vr;
			return;
		}
		int mid = (l + r) / 2;
		if(mid >= a) postavi_vr(tr * 2, a, l, mid, vr);
		else postavi_vr(tr * 2 + 1, a, mid + 1, r, vr);
		maxi[tr] = max(maxi[tr * 2], maxi[tr * 2 + 1]);
		return;
	}
	int daj_najvecu(int tr, int a, int b, int l, int r) {
		if(l > b || r < a) return 0;
		if(l >= a && r <= b) {
			return maxi[tr];
		}
		int mid = (l + r) / 2;
		return max(daj_najvecu(tr * 2, a, b, l, mid), daj_najvecu(tr * 2 + 1, a, b, mid + 1, r));
	}
} T;

struct cvor {
	int ind, dist, endt, rod, l, r, vr;
	cvor(int _ind, int _l = -1, int _r = -1) {
		ind = _ind;
		l = _l;
		r = _r;
		rod = _ind;
		vr = 0;
	}
};

int n, m, q;
vector <pair <int, int> > upiti;
vector <pair <int, int> > veze;
vector <cvor> svi;
vector <bool> maknuo;

int daj_rod(int x) {
	if(svi[x].rod == x) return x;
	return svi[x].rod = daj_rod(svi[x].rod);
}

void spoji(int a, int b) {
	int pa = daj_rod(a), pb = daj_rod(b);
	if(pa == pb) return;
	svi[pa].rod = (int)svi.size();
	svi[pb].rod = (int)svi.size();
	svi.push_back(cvor((int)svi.size(), pa, pb));
	return;
}

int br = 0;

void rek(int tr) {
	svi[tr].dist = br;
	if(svi[tr].l == -1) {
		T.postavi_vr(1, br, 0, offset - 1, svi[tr].vr);
		br++;
	}
	else {
		rek(svi[tr].l);
		rek(svi[tr].r);
	}
	svi[tr].endt = br - 1;
	return;
}

int main() {
	T.build();
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> q;
	maknuo.resize(m, 0);
	REP(i, n) svi.push_back(cvor(i));
	REP(i, n) cin >> svi[i].vr;
	REP(i, m) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		veze.push_back(make_pair(a, b));
	}
	REP(i, q) {
		int a, b;
		cin >> a >> b;
		b--;
		if(a == 2) {
			maknuo[b] = 1;
		}
		upiti.push_back(make_pair(a, b));
	}
	REP(i, m) {
		if(!maknuo[i]) {
			spoji(veze[i].first, veze[i].second);
		}
	}
	vector <int> roditelji;
	for(int i = q - 1; i >= 0; i--) {
		if(upiti[i].first == 2) spoji(veze[upiti[i].second].first, veze[upiti[i].second].second);
		else roditelji.push_back(daj_rod(upiti[i].second));
	}
	for(int i = (int)svi.size() - 1; i >= 0; i--) if(svi[i].rod == i) rek(i);
	reverse(roditelji.begin(), roditelji.end());
	REP(i, (int)roditelji.size()) {
		int maxi = T.daj_najvecu(1, svi[roditelji[i]].dist, svi[roditelji[i]].endt, 0, offset - 1);
		cout << maxi << "\n";
		T.makni_najvecu(1, svi[roditelji[i]].dist, svi[roditelji[i]].endt, 0, offset - 1, maxi);
	}
	return 0;
}