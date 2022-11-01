#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < (n); i++)
typedef long long int ll;

const int inf = 1e9;
const int offset = (1 << 19);

struct tournament {
	int pad[2 * offset];
	int rast[2 * offset];
	bool prop_pad[2 * offset];
	bool prop_rast[2 * offset];
	void build() {
		REP(i, 2 * offset) {
			pad[i] = inf;
			rast[i] = inf;
			prop_pad[i] = 0;
			prop_rast[i] = 0;
		}
	}
	void salji_prop(int cvor, bool sta) {
		if(sta) {
			if(prop_pad[cvor]) {
				pad[cvor * 2] = inf;
				pad[cvor * 2 + 1] = inf;
				prop_pad[cvor * 2] = 1;
				prop_pad[cvor * 2 + 1] = 1;
			}
			prop_pad[cvor] = 0;
		}
		else {
			if(prop_rast[cvor]) {
				rast[cvor * 2] = inf;
				rast[cvor * 2 + 1] = inf;
				prop_rast[cvor * 2] = 1;
				prop_rast[cvor * 2 + 1] = 1;
			}
			prop_rast[cvor] = 0;
		}
		return;
	}
	void makni_interval(int cvor, int a, int b, int l, int r, bool sta) {
		if(l > b || r < a) return;
		if(l >= a && r <= b) {
			if(sta) {
				pad[cvor] = inf;
				prop_pad[cvor] = 1;
			}
			else {
				rast[cvor] = inf;
				prop_rast[cvor] = 1;
			}
			return;
		}
		salji_prop(cvor, sta);
		int mid = (l + r) / 2;
		makni_interval(cvor * 2, a, b, l, mid, sta);
		makni_interval(cvor * 2 + 1, a, b, mid + 1, r, sta);
		if(sta) pad[cvor] = min(pad[cvor * 2], pad[cvor * 2 + 1]);
		else rast[cvor] = min(rast[cvor * 2], rast[cvor * 2 + 1]);
		return;
	}
	void postavi_vr(int cvor, int a, int l, int r, int vr, bool sta) {
		if(l == r) {
			if(sta) pad[cvor] = vr;
			else rast[cvor] = vr;
			return;
		}
		salji_prop(cvor, sta);
		int mid = (l + r) / 2;
		if(mid >= a) postavi_vr(cvor * 2, a, l, mid, vr, sta);
		else postavi_vr(cvor * 2 + 1, a, mid + 1, r, vr, sta);
		if(sta) pad[cvor] = min(pad[cvor * 2], pad[cvor * 2 + 1]);
		else rast[cvor] = min(rast[cvor * 2], rast[cvor * 2 + 1]);
		return;
	}
	int upit(int cvor, int a, int b, int l, int r, bool sta) {
		if(l > b || r < a) return inf;
		//cout << a << " " << b << " " << l << " " << r << " " << sta << endl;
		if(l >= a && r <= b) {
			if(sta) return pad[cvor];
			else return rast[cvor];
		}
		salji_prop(cvor, sta);
		int mid = (l + r) / 2;
		return min(upit(cvor * 2, a, b, l, mid, sta), upit(cvor * 2 + 1, a, b, mid + 1, r, sta));
	}
} T;

int main() {
	T.build();
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector <int> orig(n);
	vector <int> svi(n);
	REP(i, n) {
		cin >> orig[i];
	}
	svi = orig;
	sort(svi.begin(), svi.end());
	svi.erase(unique(svi.begin(), svi.end()), svi.end());
	int a, prosli = -1, dp, prosli_dp;
	multiset <int> pad, rast;
	multiset <int> :: iterator it, it2;
	REP(i, n) {
		a = lower_bound(svi.begin(), svi.end(), orig[i]) - svi.begin();
		if(i == 0) {
			dp = 0;
			T.postavi_vr(1, a, 0, offset - 1, dp, 0);
			T.postavi_vr(1, a, 0, offset - 1, dp, 1);
			pad.insert(a);
			rast.insert(-a);
		}
		else {
			dp = prosli_dp + 1;
			if(prosli < a) {
				it = pad.lower_bound(a);
				if(it == pad.end()) it--;
				dp = min(dp, T.upit(1, 0, *it, 0, offset - 1, 1) + 1);
				T.makni_interval(1, 0, a, 0, offset - 1, 1);
				while(pad.size() && *pad.begin() <= a) pad.erase(pad.begin());
				T.postavi_vr(1, a, 0, offset - 1, dp, 1);
				pad.insert(a);
				T.postavi_vr(1, a, 0, offset - 1, dp, 0);
				rast.insert(-a);
			}
			else if(prosli > a) {
				it = rast.lower_bound(-a);
				if(it == rast.end()) it--;
				dp = min(dp, T.upit(1, -*it, offset - 1, 0, offset - 1, 0) + 1);
				T.makni_interval(1, a, offset - 1, 0, offset - 1, 0);
				while(rast.size() && *rast.begin() <= -a) rast.erase(rast.begin());
				T.postavi_vr(1, a, 0, offset - 1, dp, 0);
				rast.insert(-a);
				T.postavi_vr(1, a, 0, offset - 1, dp, 1);
				pad.insert(a);
			}
			else {
				it = pad.lower_bound(a);
				if(it == pad.end()) it--;
				dp = min(dp, T.upit(1, 0, *it, 0, offset - 1, 1) + 1);
				T.makni_interval(1, 0, a, 0, offset - 1, 1);
				while(pad.size() && *pad.begin() <= a) pad.erase(pad.begin());
				T.postavi_vr(1, a, 0, offset - 1, dp, 1);
				pad.insert(a);
				//
				it = rast.lower_bound(-a);
				if(it == rast.end()) it--;
				dp = min(dp, T.upit(1, -*it, offset - 1, 0, offset - 1, 0) + 1);
				T.makni_interval(1, a, offset - 1, 0, offset - 1, 0);
				while(rast.size() && *rast.begin() <= -a) rast.erase(rast.begin());
				T.postavi_vr(1, a, 0, offset - 1, dp, 0);
				rast.insert(-a);
			}
		}
		prosli = a;
		prosli_dp = dp;
	}
	cout << prosli_dp << endl;
	return 0;
}