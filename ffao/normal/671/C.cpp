#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int(i)=0;(i)<(int)(n);(i)++)


int n;
int a[310000];
int loc[310000];

int minfac[310000][2];
int maxfac[310000][2];

set< pair<int, int> > limits;

long long ins(int min_pref, int min_suf) {
	//printf("adding %d %d\n", min_pref, min_suf);
	pair<int,int> p = make_pair(min_pref, min_suf);

	if (limits.size() == 0) {
		limits.insert(p);
		
		long long inside = n-min_pref;
		//printf("-> %lld\n", inside * (inside+1) / 2);
		return inside * (inside+1) / 2; 
	}

	auto it = limits.upper_bound(p);

	int max_pref = n-1;
	int max_suf = n-1;

	auto it2 = it;
	if (it2 != limits.begin()) {
		it2--;
		if (it2->second <= min_suf) return 0;
		max_suf = it2->second-1;
	}

	vector< pair<int, int> > lims;
	while (it != limits.end() && it->second >= min_suf) {
		lims.push_back(*it);
		auto it2 = it;
		it++;
		limits.erase(it2);
	}

	if (it != limits.end()) {
		max_pref = it->first-1;
	}

	limits.insert(p);

	int tmis = -1;
	int tmas = -1;

	long long ans = 0;

	for (int kkk = lims.size()-1; kkk >= 0; kkk--) {
		pair<int, int> limp = lims[kkk];
		tmis = max(min_suf, tmas+1);
		tmas = limp.second-1;

		int min_i = min_pref;
		int max_j = n-1-tmis;
		int max_i = min(max_j, max_pref);
		int min_j = max(min_i, n-1-tmas);

		long long ret = (max_j - min_j + 1) * 1ll * (max_i - min_i + 1);
		long long overlap = 0;

		if (max_i >= min_j) 
			overlap = (max_i - min_j + 1) * 1ll * (max_i - min_j) / 2;

		ans += ret - overlap;
		//printf("adding %lld from lim (%d)\n", ret-overlap,tmas);
		max_pref = limp.first-1;
	}

	if (tmas != -1) min_suf = tmas+1;
	//printf("minsuf %d\n", min_suf);

	int min_i = min_pref;
	int max_j = n-1-min_suf;
	int max_i = min(max_j, max_pref);
	int min_j = max(min_i, n-1-max_suf);
	

	long long ret = (max_j - min_j + 1) * 1ll * (max_i - min_i + 1);
	long long overlap = 0;

	if (max_i >= min_j) 
		overlap = (max_i - min_j + 1) * 1ll * (max_i - min_j) / 2;

	ans += ret - overlap;
	//printf("%d %d %d %d\n", min_pref, max_pref, min_suf, max_suf);
	//printf("%d %d %d %d -> %lld %lld\n", min_i,max_i,min_j,max_j,ret,overlap);
	return ans;
}

void solve() {
	scanf("%d", &n);

	for (int i = 1; i <= 200000; i++) {
		loc[i] = -1;
		minfac[i][0]=minfac[i][1]=-1;
		maxfac[i][0]=maxfac[i][1]=-1;
	}

	REP(i,n) scanf("%d", &a[i]);
	REP(i,n) loc[a[i]] = i;

	for (int i = 1; i <= 200000; i++) {
		for (int j = i; j <= 200000; j += i) {
			if (loc[j] != -1) {
				if (minfac[i][0] == -1) {
					minfac[i][0] = loc[j];
					maxfac[i][0] = loc[j];
					continue;
				}
				else if (minfac[i][1] == -1) {
					minfac[i][1] = loc[j];
					maxfac[i][1] = loc[j];
				}
				else {
					if (minfac[i][1] > loc[j]) minfac[i][1] = loc[j];
					if (maxfac[i][1] < loc[j]) maxfac[i][1] = loc[j];
				}

				if (minfac[i][1] < minfac[i][0]) swap(minfac[i][1], minfac[i][0]);
				if (maxfac[i][1] > maxfac[i][0]) swap(maxfac[i][1], maxfac[i][0]);
			}
		}
	}

	long long ans = 0;

	for (int i = 200000; i >= 1; i--) if (minfac[i][1] != -1) {
		//printf("proc %d\n", i);
		int bigpref = minfac[i][1];
		ans += i * 1ll * ins(bigpref+1, 0);

		int bigsuf = maxfac[i][1];
		ans += i * 1ll * ins(0, n-bigsuf);

		int smpref = minfac[i][0], smsuf = maxfac[i][0];
		ans += i * 1ll * ins(smpref+1, n-smsuf);
	}

	printf("%lld\n", ans);
}	

int main() {
    solve();
}