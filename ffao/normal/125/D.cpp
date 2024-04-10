#include <bits/stdc++.h> 

using namespace std;

typedef long long ll; 
typedef pair<int, int> pii;

#define REP(i,n) for(int(i)=0;(i)<(int)(n);(i)++)

int a[31000];
int n;
vector<int> f;
vector<int> s;

bool rec(int cur, int flast, int slast, int df, int ds) {
	//printf("%d %d %d %d %d\n", cur,flast,slast,df,ds);
	if (cur == n) return true;
	if ((s.size() == 1 || a[cur]-slast == ds) && a[cur]-flast == df) {
		int nds = ds;
		if (s.size() == 1) nds = a[cur]-slast;
		
		if (nds == df || cur == n-1 || a[cur+1] - flast == 2*df) {
			f.push_back(a[cur]);
			return rec(cur+1, a[cur], slast, df, ds);
		}
		else if (s.size() == 1) {
			vector<int> ff = f, ss = s;
			f.push_back(a[cur]);
			if (rec(cur+1, a[cur], slast, df, ds)) return true;
			f = ff, s = ss;
			s.push_back(a[cur]);
			return rec(cur+1, flast, a[cur], df, nds);
		}
		else {
			s.push_back(a[cur]);
			return rec(cur+1, flast, a[cur], df, nds);
		}
	}
	else if (s.size() == 1 || a[cur]-slast == ds) {
		s.push_back(a[cur]);
		return rec(cur+1,flast,a[cur],df,s[1]-s[0]);
	}
	else if (a[cur]-flast == df) {
		f.push_back(a[cur]);
		return rec(cur+1,a[cur],slast,df,ds);
	}
	return false;
}

bool test(int in_f, int in_s) {
	f.clear();
	s.clear();
	int ad = 0;

	f.push_back(a[ad++]);
	REP(i,in_f) f.push_back(a[ad++]);
	REP(i,in_s) s.push_back(a[ad++]);
	if (s.size() == 0) s.push_back(a[ad++]);
	if (f.size() < 2 && s.size() < 2) f.push_back(a[ad++]);
	if (f.size() == 1) swap(f, s);

	int df = -1, ds = -1;
	if (f.size() >= 2) df = f[1]-f[0];
	if (s.size() >= 2) ds = s[1]-s[0];

	if (rec(ad, f.back(), s.back(), df, ds)) {
		for (int x: f) printf("%d ", x);
		printf("\n");
		for (int x: s) printf("%d ", x);
		printf("\n");
		return true;
	}
	return false;
}

int main() {
	scanf("%d", &n);
	REP(i,n)scanf("%d", &a[i]);

	int r0 = a[1]-a[0];
	int la = 1;
	for (int i = 2; i < n; i++) {
		if (a[i]-a[i-1] == r0) la = i;
		else break;
	}

	if (n == 2) {printf("%d\n%d\n", a[0],a[1]); return 0;}
	if (n >= 3) if (test(0,1)) return 0;
	if (n >= 4) if (test(0,2)) return 0;
	if (la > 1) if (test(la-1,0)) return 0;
	if (la != n-1) if (test(la,0)) return 0;

	printf("No solution\n");
}