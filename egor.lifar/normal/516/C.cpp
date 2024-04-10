#include <iostream>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <string>
#include <string.h>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <cstring>
#include <queue>
#include <bitset>


using namespace std;


#define INF 1000000000000000LL


int n, m;
long long d2[200000];
int ss;
long long h[200000];
pair<pair<long long, int>, pair<long long, int> > d[500000], d1[500000];
long long dsum[200000];


inline void change(int i, long long x) {
	d[i] = make_pair(make_pair(x, i - ss + 1), make_pair(-INF, -INF));
	while (i / 2 > 0) {
		i /= 2;
		 pair<long long, int>  v, v1, v2, v3;
		v = d[i * 2].first;
		v1 = d[i * 2].second;
		v2 = d[i * 2 + 1].first;
		v3 = d[i * 2 + 1].second;

		pair<long long, int> ans =  make_pair(-INF, -INF), ans1 =  make_pair(-INF, -INF);
	//	for (int j = 0; j < (int)v.size(); j++) {
			if (v.first > ans.first) {
				ans1 = ans;
				ans = v;
			} else {
				ans1 = max(v, ans1);
			}
	//	}
			if (v1.first > ans.first) {
				ans1 = ans;
				ans = v1;
			} else {
				ans1 = max(v1, ans1);
			}
			if (v2.first > ans.first) {
				ans1 = ans;
				ans = v2;
			} else {
				ans1 = max(v2, ans1);
			}
			if (v3.first > ans.first) {
				ans1 = ans;
				ans = v3;
			} else {
				ans1 = max(v3, ans1);
			}
		d[i] = make_pair(ans, ans1);
	}
}


inline void change1(int i, long long x) {
	d1[i] = make_pair(make_pair(x, i - ss + 1), make_pair(-INF, -INF));
	while (i / 2 > 0) {
		i /= 2;
		 pair<long long, int>  v, v1, v2, v3;
		v = d1[i * 2].first;
		v1 = d1[i * 2].second;
		v2 = d1[i * 2 + 1].first;
		v3 = d1[i * 2 + 1].second;

		pair<long long, int> ans =  make_pair(-INF, -INF), ans1 =  make_pair(-INF, -INF);
	//	for (int j = 0; j < (int)v.size(); j++) {
			if (v.first > ans.first) {
				ans1 = ans;
				ans = v;
			} else {
				ans1 = max(v, ans1);
			}
	//	}
			if (v1.first > ans.first) {
				ans1 = ans;
				ans = v1;
			} else {
				ans1 = max(v1, ans1);
			}
			if (v2.first > ans.first) {
				ans1 = ans;
				ans = v2;
			} else {
				ans1 = max(v2, ans1);
			}
			if (v3.first > ans.first) {
				ans1 = ans;
				ans = v3;
			} else {
				ans1 = max(v3, ans1);
			}
		d1[i] = make_pair(ans, ans1);
	}
}


inline pair<pair<long long, int>, pair<long long, int> >  rmq(int l, int r, int vl, int vr, int v5) {
	if (r < vl || l > vr) {
		return  make_pair(make_pair(-INF, -INF), make_pair(-INF, -INF));
	}
	if (l <= vl && vr <= r) {
		return d[v5];
	}
	 pair<pair<long long, int>, pair<long long, int> > p = rmq(l, r, vl, (vl + vr) / 2, v5 * 2);
	 pair<pair<long long, int>, pair<long long, int> > p1 = rmq(l, r, (vl + vr) / 2 + 1, vr, v5 * 2 + 1);
	  pair<long long, int>  v, v1, v2, v3;
	v = p.first;
	v1 = p1.first;
	v2 = p1.second;
	v3 = p.second;
	pair<long long, int> ans =  make_pair(-INF, -INF), ans1 =  make_pair(-INF, -INF);
	if (v.first > ans.first) {
				ans1 = ans;
				ans = v;
			} else {
				ans1 = max(v, ans1);
			}
	//	}
			if (v1.first > ans.first) {
				ans1 = ans;
				ans = v1;
			} else {
				ans1 = max(v1, ans1);
			}
			if (v2.first > ans.first) {
				ans1 = ans;
				ans = v2;
			} else {
				ans1 = max(v2, ans1);
			}
			if (v3.first > ans.first) {
				ans1 = ans;
				ans = v3;
			} else {
				ans1 = max(v3, ans1);
			}
	return make_pair(ans, ans1);
}


inline pair<pair<long long, int>, pair<long long, int> >  rmq1(int l, int r, int vl, int vr, int v5) {
	if (r < vl || l > vr) {
		return  make_pair(make_pair(-INF, -INF), make_pair(-INF, -INF));
	}
	if (l <= vl && vr <= r) {
		return d1[v5];
	}

	 pair<pair<long long, int>, pair<long long, int> > p = rmq1(l, r, vl, (vl + vr) / 2, v5 * 2);
	 pair<pair<long long, int>, pair<long long, int> > p1 = rmq1(l, r, (vl + vr) / 2 + 1, vr, v5 * 2 + 1);
	  pair<long long, int>  v, v1, v2, v3;
	v = p.first;
	v1 = p1.first;
	v2 = p1.second;
	v3 = p.second;
	pair<long long, int> ans =  make_pair(-INF, -INF), ans1 =  make_pair(-INF, -INF);
	if (v.first > ans.first) {
				ans1 = ans;
				ans = v;
			} else {
				ans1 = max(v, ans1);
			}
	//	}
			if (v1.first > ans.first) {
				ans1 = ans;
				ans = v1;
			} else {
				ans1 = max(v1, ans1);
			}
			if (v2.first > ans.first) {
				ans1 = ans;
				ans = v2;
			} else {
				ans1 = max(v2, ans1);
			}
			if (v3.first > ans.first) {
				ans1 = ans;
				ans = v3;
			} else {
				ans1 = max(v3, ans1);
			}
	return make_pair(ans, ans1);
}


int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> d2[i];
		dsum[i] = (long long)d2[i] + (i > 0 ? dsum[i - 1]: 0);
	}
	for (int i = n; i <  2 * n; i++) {
		dsum[i] = (long long)d2[i - n] + (i > 0 ? dsum[i - 1]: 0);
	}
	ss = 1;
	while (ss < 2 * n) {
		ss *= 2;
	}
	for (int i = 0; i < n; i++) {
		change(i + ss, -INF);
		change1(i + ss, -INF);
	}
	for (int i = 0; i < n; i++) {
		cin >> h[i];
		change(i + ss, (i > 0 ? dsum[i - 1]: 0) + 2LL * h[i]);
		//cout << (i > 0 ? dsum[i - 1]: 0) + 2LL * h[i] << endl;
		change1(i + ss, -(i > 0 ? dsum[i - 1]: 0) + 2LL * h[i]);
		change(i + n + ss, (dsum[n + i - 1]) + 2LL * h[i]);
		change1(i + n + ss, -(dsum[n + i - 1]) + 2LL * h[i]);
	//	cout <<  -(dsum[n + i - 1]: 0) + 2LL * h[i] << endl;
	}
	//cout << rmq(2, 3, 1, s, 1) << endl;
	if (n == 100000) {
	//	cout << "opa" << endl;
	}
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
//				if (n == 68950)  {
		//	cout <<  a << ' ' << b << endl;
		//return 0;
//	}
		int t;
		t = a + n - 1;
		int t1 = 1;
		if (b < a) {
			t1 = b + 1;
			b += n;
			t = a - 1;
		}
		pair<pair<long long, int>, pair<long long, int> > ans = make_pair(make_pair(-INF, -INF), make_pair(-INF, -INF));
		pair<pair<long long, int>, pair<long long, int> > ans1 = make_pair(make_pair(-INF, -INF), make_pair(-INF, -INF));
		if (a > 2 && a- 1 >= t1 && a - 1 != 0) {
			ans = rmq(t1, a - 1, 1, ss, 1);
			ans1 = rmq1(t1, a - 1, 1, ss, 1);
		}
		if (n == 100000) {
	//	cout << "opa" << endl;
	}
		pair<pair<long long, int>, pair<long long, int> > ans2 = make_pair(make_pair(-INF, -INF), make_pair(-INF, -INF));
		pair<pair<long long, int>, pair<long long, int> > ans3 = make_pair(make_pair(-INF, -INF), make_pair(-INF, -INF));
		if (b < t - 1) {
			ans2 = rmq(b + 1, t, 1, ss, 1);
			ans3 = rmq1(b + 1, t, 1, ss, 1);
		}
		long long s = -2LL * INF;
		long long s1 = -2LL * INF;
		//cout << ans2.first.second << ' ' << ans3.first.second << endl;
		if (ans.first.second != ans1.first.second) {
			s = ans.first.first + ans1.first.first;
		} else {
			s = max(ans.first.first + ans1.second.first, ans.second.first + ans1.first.first);
		}
		if (ans2.first.second != ans3.first.second) {
			s1 = ans2.first.first + ans3.first.first;
		} else {
			s1 = max(ans2.first.first + ans3.second.first, ans2.second.first + ans3.first.first);
		}
	//	cout << ans2 + ans3 << endl;
//cout << s1 << endl;
		cout << max(s, s1) << endl;
	}
    return 0;
}