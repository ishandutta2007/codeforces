#include <bits/stdc++.h>

#define MP make_pair
#define MN 200200
#define L first.first
#define R first.second

using namespace std;
typedef pair<pair<int,int>,int> piii;

int n,t,sqn,l,r;
vector <piii> queries;
long long ans[MN], a[MN], freq[1000100];

bool cmp(piii a, piii b) {
	if(a.L/sqn == b.L/sqn)
		return (a.R < b.R);
	return a.L < b.L;
}

void solve() {
	long long ret = 0;
	int left = 0, right = -1;

	for(int i=0;i<t;i++) {
		int ql = queries[i].L, qr = queries[i].R;

		while(right < qr) { // add
			right++;
			ret += a[right] * (2*freq[a[right]] + 1);
			freq[a[right]]++;
		}

		while(right > qr) { // remove
			ret += a[right] * (-2*freq[a[right]] + 1);
			freq[a[right]]--;
			right--;
		} 

		while(left < ql) { // remove
			ret += a[left] * (-2*freq[a[left]] + 1);
			freq[a[left]]--;
			left++;
		}

		while(left > ql) { // add
			left--;
			ret += a[left] * (2*freq[a[left]] + 1);
			freq[a[left]]++;
		}

		ans[queries[i].second] = ret;
	}
}

int main() {
	scanf("%d %d",&n,&t);
	sqn = (int)sqrt(n);


	for(int i=0;i<n;i++) scanf("%lld",&a[i]);

	for(int i=0;i<t;i++) {
		scanf("%d %d",&l,&r);
		queries.push_back(MP(MP(--l,--r),i));
	}

	sort(queries.begin(),queries.end(),cmp);
	solve();

	for(int i=0;i<t;i++) printf("%lld\n", ans[i]);

	return 0;
}