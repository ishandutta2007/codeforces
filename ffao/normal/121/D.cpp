#include <bits/stdc++.h> 

using namespace std;

typedef unsigned long long ll; 
typedef pair<int, int> pii;

#define REP(i,n) for(int(i)=0;(i)<(int)(n);(i)++)

int n;
ll k;
ll minlen = 1e18 + 0.5;

ll lefts[110000];
ll rights[110000];
ll sum_lefts[110000];
ll sum_rights[110000];

vector<ll> luckies;
void gen_lucky(int rem, ll cur) {
	if (cur) luckies.push_back(cur);
	if (rem == 0) return;
	gen_lucky(rem-1, cur*10 + 4);
	gen_lucky(rem-1, cur*10 + 7);
}

ll calc(ll st, ll ed) {
	int idxL = upper_bound(lefts, lefts+n, st) - lefts;
	int idxR = upper_bound(rights, rights+n, ed) - rights;

	ll sL = sum_lefts[n] - sum_lefts[idxL];
	ll sR = sum_rights[idxR];
	return (sL - st*(n-idxL)) + (ed*(idxR) - sR);
}

int main() {
	scanf("%d %llu", &n, &k);
	REP(i, n) {
		scanf("%llu %llu", &lefts[i], &rights[i]);
		minlen = min(minlen, rights[i]-lefts[i]);
	}

	gen_lucky(18, 0);
	sort(luckies.begin(), luckies.end());
	sort(lefts,lefts+n);
	sort(rights,rights+n);

	REP(i, n) {
		sum_lefts[i+1] = sum_lefts[i] + lefts[i];
		sum_rights[i+1] = sum_rights[i] + rights[i];
	}

	ll stL = 0, edL = 1e18 + 0.5;
	while (stL < edL) {
		ll m = (stL+edL)/2;
		ll cursum = 0;
		bool ok = true;
		REP(i, n) {
			if (m < lefts[i]) cursum += lefts[i] - m;
			if (cursum > k) ok = false;
		}
		//printf("%llu %d\n", m, ok);
		if (ok) edL = m;
		else stL = m+1;
	}
	ll stR = 0, edR = 1e18 + 0.5;
	while (stR < edR) {
		ll m = (stR+edR+1)/2;
		ll cursum = 0;
		bool ok = true;
		REP(i, n) {
			if (m > rights[i]) cursum += m - rights[i];
			if (cursum > k) ok = false;
		}
		if (ok) stR = m;
		else edR = m-1;
	}

	//printf("hi ls %d stL %llu stR %llu\n", luckies.size(), stL, stR);
	int best = 0;
	int right = -1;
	REP(left, luckies.size()) {
		if (luckies[left] < stL) continue;
		right = max(right, left-1);
		
		while (right+1 < (int)luckies.size()) {
			if (luckies[right+1] > stR) break;
			if (luckies[right+1] - luckies[left] > minlen) break;
			ll tot = calc(luckies[left], luckies[right+1]);
			if (tot > k) break;
			right++;
		}

		//if (left < 10) printf("le %d ri %d\n", left, right);
		best = max(best, right-left+1);
	}

	printf("%d\n", best);
}