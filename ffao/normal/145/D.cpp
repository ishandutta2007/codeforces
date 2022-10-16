#include <bits/stdc++.h> 

using namespace std;

typedef long long ll; 
typedef pair<int, int> pii;

#define REP(i,n) for(int(i)=0;(i)<(int)(n);(i)++)

int n;
int a[110000];
int lucky[110000];
vector<int> luckies;
int next_eq[110000];
map<int,int> nxt;

void update(set<int>& s, int idx, ll& cnt) {
	while (*s.begin() <= idx) {
		if (s.size() >= 2) {
			auto k = s.begin(); ++k;
			auto b = s.begin();

			int len = *k - *b - 1;
			cnt -= (len)*1ll*(len+1)/2;
		}
		bool already = (*s.begin() == idx);
		s.erase(s.begin());
		if (already) return;
	}

	int k = next_eq[idx];
	while (k != n) {
		auto nxtit = s.lower_bound(k);
		if (nxtit != s.begin()) {
			auto pit = nxtit; --pit;

			int len = (*nxtit) - (*pit) - 1;
			cnt -= (len)*1ll*(len+1)/2;

			int nlen = k - (*pit) - 1;
			cnt += (nlen)*1ll*(nlen+1)/2;
		}

		s.insert(k);
		int nlen = (*nxtit) - k - 1;
		cnt += (nlen)*1ll*(nlen+1)/2;
		k = next_eq[k];
	}
}

ll C3(int n) {
	return n*1ll*(n-1)*1ll*(n-2)/6;
}

int main() {
	scanf("%d", &n);
	REP(i,n) scanf("%d", &a[i]);
	for (int i = n-1; i >= 0; i--) {
		int ti = a[i];
		lucky[i] = 1;
		while (ti) {
			if (ti%10 != 4 && ti%10 != 7) {
				lucky[i] = 0; 
				break;
			}
			ti /= 10;
		}

		if (lucky[i]) luckies.push_back(i);
		if (nxt.count(a[i])) next_eq[i] = nxt[a[i]];
		else next_eq[i] = n;
		nxt[a[i]] = i;
	}

	reverse(luckies.begin(), luckies.end());
	int lucky_cnt = luckies.size();
	ll ans = 0;

	int last_lucky = -1;
	REP(int1_end, n) {
		if (lucky[int1_end]) {
			last_lucky = int1_end;
			continue;
		}
		int s = int1_end - last_lucky;
		int rem = n - int1_end - 1;
		ll k = (rem*1ll*(rem+1))/2;
		ans += s * k;
	}

	REP(int1_start, lucky_cnt) {
		set<int> forbidden;
		long long curr = 0;
		forbidden.insert(n);

		update(forbidden, luckies[int1_start], curr);

		for (int int1_end = int1_start; int1_end < lucky_cnt; int1_end++) {
			update(forbidden, luckies[int1_end], curr);

			int poss_1 = luckies[int1_start]+1;
			if (int1_start != 0) poss_1 -= luckies[int1_start-1]+1; 
			int poss_2 = n - luckies[int1_end];
			if (int1_end+1 != lucky_cnt) poss_2 += (luckies[int1_end+1] - n);
			int first_ival = *forbidden.begin() - luckies[int1_end] - 1;
			
			ll poss_finc = C3(first_ival+2) - C3( (first_ival - poss_2) + 2);
			poss_finc += (poss_2 * 1ll * curr);
			//printf("%d %d %d %d %lld %lld\n", int1_start, int1_end, poss_1, poss_2, curr, poss_finc);
			ans += poss_finc * poss_1;			
		}
	}

	printf("%lld\n", ans);
}