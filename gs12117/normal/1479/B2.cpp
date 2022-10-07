#include<cstdio>
#include<set>
int n;
int a[100100];
int dp[100100];
int chk[100100];
struct snode {
	int val;
	int loc;
	bool operator<(const snode&r)const {
		if (val == r.val) {
			return loc < r.loc;
		}
		return val < r.val;
	}
};
std::set<snode> pset;
int defval;
int getminexcept(int ea) {
	std::set<snode>::iterator ite = pset.begin();
	while (1) {
		if (ite->loc != ea) {
			return ite->val;
		}
		ite++;
	}
}
void updnode(int loc, int val) {
	snode t;
	if (chk[loc] == 1) {
		t.loc = loc;
		t.val = dp[loc];
		pset.erase(t);
	}
	chk[loc] = 1;
	dp[loc] = val;
	t.loc = loc;
	t.val = dp[loc];
	pset.insert(t);
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	updnode(0, 1);
	for (int i = 1; i < n; i++) {
		int tval = -1;
		if (a[i] == a[i - 1]) {
			tval = getminexcept(a[i]) + 1;
			if (chk[a[i]] != 0 && tval > dp[a[i]])tval = dp[a[i]];
			updnode(a[i], tval);
		}
		else {
			defval++;
			tval = getminexcept(a[i]);
			if (chk[a[i]] != 0 && tval > dp[a[i]] - 1)tval = dp[a[i]] - 1;
			updnode(a[i - 1], tval);
		}
	}
	int ans = defval + getminexcept(-1);
	printf("%d\n", ans);
	return 0;
}