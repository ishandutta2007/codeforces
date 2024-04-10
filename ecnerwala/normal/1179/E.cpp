#include<bits/stdc++.h>
using namespace std;

using ll = long long;

mt19937 mt(48);

const int MAXN = 1100;
int N;
ll L;
ll lind[MAXN];
ll lval[MAXN];
ll rind[MAXN];
ll rval[MAXN];

map<pair<int, ll>, ll> cache;
int numQueries = 0;
ll query(int i, ll x) {
	pair<int, ll> st(i, x);
	if (cache.count(st)) return cache[st];

	if (x == 0) return cache[st] = 0;
	if (x == ll(1e18)) return cache[st] = L;

	numQueries++;
#if 1
	cout << "?" << ' ' << i+1 << ' ' << x << '\n' << flush;
	ll v; cin >> v;
#else
	ll v = min(x, L);
#endif
	return cache[st] = v;
}

void dfs(vector<int> inds, ll l, ll r) {
	//cerr << inds.size() << ' ' << l << ' ' << r << '\n';
	assert(!inds.empty());
	if (inds.size() == 1) {
		lind[inds[0]] = l;
		rind[inds[0]] = r;
		return;
	}
	assert(inds.size() >= 2);
	int ltarget = int(inds.size()) / 2;
	int rtarget = int(inds.size()) - ltarget;

	shuffle(inds.begin(), inds.end(), mt);

	vector<int> linds;
	vector<int> rinds;
	vector<int> minds = std::move(inds);
	ll curL = l, curR = r;
	while (true) {
		ll mi = 0, ma = ll(1e18);
		ll md;
		while (ma - mi > 1) {
			md = (mi + ma) / 2;
			if (md >= curR) {
				ma = md;
			} else if (md <= curL) {
				mi = md;
			} else {
				int i = minds[0];
				ll ldiff = query(i, md) - query(i, l);
				ll rdiff = query(i, r) - query(i, md);
				if (ldiff < ((L / N) * ltarget)) {
					mi = md;
				} else if (rdiff < ((L / N) * rtarget)){
					ma = md;
				} else {
					break;
				}
			}
		}
		// md is the midpoint
		vector<int> lgoods;
		vector<int> rgoods;
		vector<int> bgoods;
		for (int i : minds) {
			ll ldiff = query(i, md) - query(i, l);
			ll rdiff = query(i, r) - query(i, md);
			bool lgood = ldiff >= ((L / N) * ltarget);
			bool rgood = rdiff >= ((L / N) * rtarget);
			assert(lgood || rgood);
			if (lgood && rgood) {
				bgoods.push_back(i);
			} else if (lgood) {
				lgoods.push_back(i);
			} else if (rgood) {
				rgoods.push_back(i);
			} else assert(false);
		}
		if (int(linds.size() + lgoods.size() + bgoods.size()) >= ltarget && int(rinds.size() + rgoods.size() + bgoods.size()) >= rtarget){
			// we've found the point
			linds.insert(linds.end(), lgoods.begin(), lgoods.end());
			rinds.insert(rinds.end(), rgoods.begin(), rgoods.end());
			while (int(linds.size()) < ltarget) {
				linds.push_back(bgoods.back());
				bgoods.pop_back();
			}
			rinds.insert(rinds.end(), bgoods.begin(), bgoods.end());

			dfs(linds, l, md);
			dfs(rinds, md, r);
			return;
		} else if (int(linds.size() + lgoods.size() + bgoods.size()) < ltarget) {
			linds.insert(linds.end(), lgoods.begin(), lgoods.end());
			linds.insert(linds.end(), bgoods.begin(), bgoods.end());
			minds = std::move(rgoods);
			curL = md;
		} else {
			rinds.insert(rinds.end(), rgoods.begin(), rgoods.end());
			rinds.insert(rinds.end(), bgoods.begin(), bgoods.end());
			minds = std::move(lgoods);
			curR = md;
		}
	}

	/*
	ll mi = 0, ma = ll(1e18);
	while (ma - mi > 1) {
		ll md = (mi + ma) / 2;
		if (md >= r) {
			ma = md;
		} else if (md <= l) {
			mi = md;
		} else {
			assert(l < md && md < r);
			int cnt = 0;
			for (int i : inds) {
				ll ldiff = query(i, md) - query(i, l);
				//ll rdiff = query(i, r) - query(i, md);
				if (ldiff >= ((L / N) * ltarget)) {
					cnt++;
				}
			}
			if (cnt >= ltarget) {
				ma = md;
			} else {
				mi = md;
			}
		}
	}

	ll md = ma;

	vector<int> linds;
	vector<int> rinds;
	for (int i : inds) {
		ll ldiff = query(i, md) - query(i, l);
		//ll rdiff = query(i, r) - query(i, md);
		if (ldiff >= ((L / N) * ltarget)) {
			linds.push_back(i);
		} else {
			rinds.push_back(i);
		}
	}

	while (int(linds.size()) > ltarget) {
		rinds.push_back(linds.back());
		linds.pop_back();
	}

	dfs(linds, l, md);
	dfs(rinds, md, r);
	*/
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N >> L;
	for (int i = 0; i < N; i++) {
		lind[i] = 0;
		lval[i] = 0;

		rind[i] = ll(1e18);
		rval[i] = L;
	}

	vector<int> inds;
	for (int i = 0; i < N; i++) inds.push_back(i);
	dfs(inds, 0, ll(1e18));

	cout << "!" << '\n';
	for (int i = 0; i < N; i++) {
		cout << lind[i] << ' ' << rind[i] << '\n';
	}
	cerr << "numQueries " << numQueries << '\n';

	return 0;
}