#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < (n); i++)
typedef long long int ll;

const int offset = (1 << 17);
const int inf = 1e9;

struct query {
	int l, r, target;
	query(int _l, int _r, int _target) {
		l = _l;
		r = _r;
		target = _target;
	}
	friend bool operator <(query A, query B) {
		if(A.r != B.r) return A.r < B.r;
		return A.l < B.l;
	}
};

struct tournament {
	int mini[2 * offset];
	
	void build() {
		REP(i, 2 * offset) mini[i] = -1;
	}
	void update(int poz, int sta) {
		poz += offset;
		mini[poz] = sta;
		poz /= 2;
		while(poz) {
			mini[poz] = min(mini[poz * 2], mini[poz * 2 + 1]);
			poz /= 2;
		}
		return;
	}
	int upit(int cvor, int a, int b, int l, int r) {
		if(l > b || r < a) return inf;
		if(l >= a && r <= b) return mini[cvor];
		int mid = (l + r) / 2;
		return min(upit(cvor * 2, a, b, l, mid), upit(cvor * 2 + 1, a, b, mid + 1, r));
	}
} T;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	T.build();
	int n;
	cin >> n;
	vector <int> svi(n), zad(n, -1);
	vector <bool> ide(n + 1, 0);
	vector <query> upiti;
	bool ima_1 = 1;
	REP(i, n) {
		cin >> svi[i];
		if(svi[i] != 1) ima_1 = 0;
		if(zad[svi[i] - 1] == i - 1) continue;
		upiti.push_back(query(zad[svi[i] - 1] + 1, i - 1, svi[i] - 1));
		zad[svi[i] - 1] = i;
	}
	REP(i, n) if(zad[i] < n - 1) upiti.push_back(query(zad[i] + 1, n - 1, i));
	upiti.push_back(query(0, n - 1, n));
	sort(upiti.begin(), upiti.end());
	int dg = -1;
	REP(i, (int)upiti.size()) {
		if(upiti[i].target == 0) {
			ide[0] = 1;
			continue;
		}
		for(int j = dg + 1; j <= upiti[i].r; j++) T.update(svi[j] - 1, j);
		dg = upiti[i].r;
		if(T.upit(1, 0, upiti[i].target - 1, 0, offset - 1) >= upiti[i].l) ide[upiti[i].target] = 1;
	}
	int rj = 1;
	REP(i, n + 1) if(ide[i]) rj++; else break;
	if(!ima_1) cout << rj << "\n";
	else cout << "1\n";
	return 0;
}