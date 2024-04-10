#include <bits/stdc++.h>

#define itn int
#define LL long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(x) (x).begin(), (x).end()

using namespace std;

inline int nxt(){
	int x;
	scanf("%d", &x);
	return x;
}

struct Fenwick{
	int n;
	vector<int> a;

	Fenwick(int n = 0):n(n){
		a.resize(n);
	}

	void add(int pos, int x){
		while (pos < n){
			a[pos] += x;
			pos = (pos | (pos + 1));
		}
	}

	int get(int pos){
		int res = 0;
		while (pos >= 0){
			res += a[pos];
			pos = (pos & (pos + 1)) - 1;
		}
		return res;
	}
};

int main(){

	int n = nxt();
	vector<int> values;
	vector<int> a(n), t(n), x(n);
	for (int i = 0; i < n; i++){
		a[i] = nxt();
		t[i] = nxt();
		x[i] = nxt();
		values.push_back(x[i]);
	}

	sort(all(values));
	values.resize(unique(all(values)) - values.begin());
	int sz = values.size();
	vector<int> cnt(sz);
	for (int i = 0; i < n; i++){
		cnt[lower_bound(all(values), x[i]) - values.begin()]++;
	}

	vector<vector<int>> moms(sz);
	for (int i = 0; i < n; i++){
		x[i] = lower_bound(all(values), x[i]) - values.begin();
		moms[x[i]].push_back(t[i]);
	}
	for (int i = 0; i < sz; i++){
		sort(all(moms[i]));
	}

	vector<Fenwick> fenv;
	for (int i = 0; i < sz; i++){
		fenv.emplace_back(cnt[i]);
	}

	for (int i = 0; i < n; i++){
		if (a[i] == 1){
			int tt = lower_bound(all(moms[x[i]]), t[i]) - moms[x[i]].begin();
			fenv[x[i]].add(tt, 1);
		} else if (a[i] == 2){
			int tt = lower_bound(all(moms[x[i]]), t[i]) - moms[x[i]].begin();
			fenv[x[i]].add(tt, -1);
		} else {
			int tt = lower_bound(all(moms[x[i]]), t[i]) - moms[x[i]].begin();
			printf("%d\n", fenv[x[i]].get(tt));
		}
	}

	return 0;
}