#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < (n); i++)
typedef long long int ll;

const ll inf = 1e9 + 7;
const int maxn = 1010;

struct tocka {
	ll x, y;
	int komp;
	tocka *gore, *dolje, *lijevo, *desno;
	
	tocka(int _x, int _y) {
		x = _x;
		y = _y;
		gore = 0;
		dolje = 0;
		lijevo = 0;
		desno = 0;
	}
	tocka(){}
};

void spoji(tocka *a, tocka *b) {
	assert(a -> x == b -> x || a -> y == b -> y);
	if(a -> x == b -> x) {
		if(a -> y > b -> y) swap(a, b);
		a -> gore = b;
		b -> dolje = a;
	}
	else {
		if(a -> x > b -> x) swap(a, b);
		a -> desno = b;
		b -> lijevo = a;
	}
	return;
}

int bio[maxn];

int n;
vector <tocka> svi;

void dfs(int x, ll mid, int br_komp) {
	bio[x] = svi[x].komp = br_komp;
	tocka tr = svi[x];
	REP(i, n) {
		if(bio[i] == -1) {
			tocka sus = svi[i];
			if((tr.x == sus.x && abs(tr.y - sus.y) <= mid) || (tr.y == sus.y && abs(tr.x - sus.x) <= mid)) dfs(i, mid, br_komp);
		}
	}
	return;
}

bool ide(ll mid) {
	memset(bio, -1, sizeof bio);
	int br_komp = 0;
	REP(i, n) {
		if(bio[i] == -1) {
			dfs(i, mid, br_komp);
			br_komp++;
		}
	}
	int target = 3;
	if(br_komp == 1) return 1;
	else if(br_komp == 2) {
		REP(i, n) {
			tocka tr = svi[i];
			REP(j, n) {
				if(i == j || bio[i] == bio[j]) continue;
				tocka sus = svi[j];
				if((tr.x == sus.x && abs(tr.y - sus.y) <= 2 * mid) || (tr.y == sus.y && abs(tr.x - sus.x) <= 2 * mid)) return 1;
			}
		}
	}
	else if(br_komp == 3) target = 7;
	else if(br_komp == 4) target = 15;
	else return 0;
	REP(i, n) {
		tocka tr = svi[i];
		REP(j, n) {
			if(i == j) continue;
			tocka sus = svi[j];
			if(tr.x == sus.x || tr.y >= sus.y) continue;
			if(abs(tr.x - sus.x) > mid || abs(tr.y - sus.y) > mid) continue;
			if(bio[i] == bio[j]) continue;
			int maska = (1 << bio[i]) | (1 << bio[j]);
			if(tr.x < sus.x) {
				if(tr.desno && (tr.desno -> x) - sus.x <= mid) maska |= (1 << (tr.desno -> komp));
				if(sus.dolje && tr.y - (sus.dolje -> y) <= mid) maska |= (1 << (sus.dolje -> komp));
				if(maska == target) return 1;
				maska = (1 << bio[i]) | (1 << bio[j]);
				if(tr.gore && (tr.gore -> y) - sus.y <= mid) maska |= (1 << (tr.gore -> komp));
				if(sus.lijevo && tr.x - (sus.lijevo -> x) <= mid) maska |= (1 << (sus.lijevo -> komp));
				if(maska == target) return 1;
			}
			else {
				if(tr.lijevo && sus.x - (tr.lijevo -> x) <= mid) maska |= (1 << (tr.lijevo -> komp));
				if(sus.dolje && tr.y - (sus.dolje -> y) <= mid) maska |= (1 << (sus.dolje -> komp));
				if(maska == target) return 1;
				maska = (1 << bio[i]) | (1 << bio[j]);
				if(tr.gore && (tr.gore -> y) - sus.y <= mid) maska |= (1 << (tr.gore -> komp));
				if(sus.desno && (sus.desno -> x) - tr.x <= mid) maska |= (1 << (sus.desno -> komp));
				if(maska == target) return 1;
			}
		}
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	int x, y;
	REP(i, n) {
		cin >> x >> y;
		svi.push_back(tocka(x, y));
	}
	REP(i, n) {
		tocka &tr = svi[i];
		REP(j, n) {
			if(i == j) continue;
			tocka &sus = svi[j];
			if(tr.x == sus.x && tr.y < sus.y) {
				if(tr.gore == 0 || (tr.gore -> y) - tr.y > sus.y - tr.y) {
					svi[i].gore = &svi[j];
					svi[j].dolje = &svi[i];
				}
			}
			else if(tr.y == sus.y && tr.x < sus.x) {
				if(tr.desno == 0 || (tr.desno -> x) - tr.x > sus.x - tr.x) {
					svi[i].desno = &svi[j];
					svi[j].lijevo = &svi[i];
				}
			}
		}
	}
	ll lo = 0, hi = 2 * inf, mid;
	while(lo < hi) {
		mid = lo + (hi - lo) / 2;
		if(ide(mid)) hi = mid;
		else lo = mid + 1;
	}
	cout << (lo == 2 * inf ? -1 : lo) << "\n";
	return 0;
}