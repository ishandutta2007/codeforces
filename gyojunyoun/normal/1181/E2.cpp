#include <bits/stdc++.h>
#define eb emplace_back
#define sz(V) ((int)(V).size())
#define upmin(a,b) (a)=min((a),(b))
#define upmax(a,b) (a)=max((a),(b))
using namespace std;
typedef pair<int, int> pii;
 
const int MAXN = 100055;
 
struct REC {
	int sx, sy, ex, ey;
 
	void input() {
		cin >> sx >> sy >> ex >> ey;
	}
} rec[MAXN];
 
struct NOD {
	set<int> V;
	set<pii> XS, XE, YS, YE;
 
	void push(int v) {
		V.insert(v);
		XS.insert(pii(rec[v].sx, v));
		XE.insert(pii(-rec[v].ex, v));
		YS.insert(pii(rec[v].sy, v));
		YE.insert(pii(-rec[v].ey, v));
	}
 
	void pop(int idx) {
		V.erase(idx);
		XS.erase(pii(rec[idx].sx, idx));
		XE.erase(pii(-rec[idx].ex, idx));
		YS.erase(pii(rec[idx].sy, idx));
		YE.erase(pii(-rec[idx].ey, idx));
	}
};
 
void f(NOD &nod) {
	const int n = sz(nod.V);
	if(n < 4) return;
 
	auto xsit = nod.XS.begin(), xeit = nod.XE.begin();
	auto ysit = nod.YS.begin(), yeit = nod.YE.begin();
	int mxex = rec[xsit->second].ex, mnsx = rec[xeit->second].sx;
	int mxey = rec[ysit->second].ey, mnsy = rec[yeit->second].sy;
	int type = -1;
 
	xsit++; xeit++; ysit++; yeit++;
	for(int i = 1; i < n; i++) {
		if(mxex <= rec[xsit->second].sx) {
			type = 0;
			break;
		}
		if(rec[xeit->second].ex <= mnsx) {
			type = 1;
			break;
		}
		if(mxey <= rec[ysit->second].sy) {
			type = 2;
			break;
		}
		if(rec[yeit->second].ey <= mnsy) {
			type = 3;
			break;
		}
		upmax(mxex, rec[xsit->second].ex);
		upmin(mnsx, rec[xeit->second].sx);
		upmax(mxey, rec[ysit->second].ey);
		upmin(mnsy, rec[yeit->second].sy);
		xsit++; xeit++; ysit++; yeit++;
	}
	if(!type) {
		NOD ret;
		for(;;) {
			if(nod.XS.begin() == xsit) break;
			xsit--;
			ret.push(xsit->second);
		}
		for(int v : ret.V) nod.pop(v);
		f(ret);
		f(nod);
		return;
	} else if(1 == type) {
		NOD ret;
		for(;;) {
			if(nod.XE.begin() == xeit) break;
			xeit--;
			ret.push(xeit->second);
		}
		for(int v : ret.V) nod.pop(v);
		f(ret);
		f(nod);
		return;
	} else if(2 == type) {
		NOD ret;
		for(;;) {
			if(nod.YS.begin() == ysit) break;
			ysit--;
			ret.push(ysit->second);
		}
		for(int v : ret.V) nod.pop(v);
		f(ret);
		f(nod);
		return;
	} else if(3 == type) {
		NOD ret;
		for(;;) {
			if(nod.YE.begin() == yeit) break;
			yeit--;
			ret.push(yeit->second);
		}
		for(int v : ret.V) nod.pop(v);
		f(ret);
		f(nod);
		return;
	}
 
	puts("NO");
	exit(0);
}
 
int N;
 
int main() {
	ios::sync_with_stdio(false);
 
	cin >> N;
	NOD nod;
	for(int i = 0; i < N; i++) {
		rec[i].input();
		nod.push(i);
	}
 
	f(nod);
 
	puts("YES");
 
	return 0;
}