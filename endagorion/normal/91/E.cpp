#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <set>
#include <map>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

#ifdef ONLINE_JUDGE

#define fin cin
#define fout cout

#else

fstream fin("input.txt", fstream::in);
fstream fout("output.txt", fstream::out);

#endif

struct TMom {
	long long t;
	int x;

	TMom(long long _t = 0, int _x = 0)
		: t(_t)
		, x(_x)
	{
	}
};

struct TTower {
	long long x, v;
	int i;

	TTower(long long _x = 0, long long _v = 0, int _i = 0)
		: x(_x)
		, v(_v)
		, i(_i)
	{
	}

	bool operator<(const TTower &a) const {
		if (v != a.v) {
			return v < a.v;
		}
		return x < a.x;
	}
};

bool higher(const TTower &a, const TTower &b, long long t) {
	return a.x + a.v * t >= b.x + b.v * t;
}

long long chase(const TTower &a, const TTower &b) {
	long long P = b.x - a.x;
	long long Q = a.v - b.v;
	return P / Q + (P % Q > 0 ? 1 : 0);
}

int main() {
	fout << fixed;

	int N, Q;
	fin >> N >> Q;
	vector<TTower> a(N);
	for (int i = 0; i < N; ++i) {
		fin >> a[i].x >> a[i].v;
		a[i].i = i;
	}

	int L = max((int)ceil(sqrt(N * log(1.0 * N) / log(2.0))), 1);

	vector<int> l, r;
	int cur = 0;
	while (cur < N) {
		l.push_back(cur);
		r.push_back(min(cur + L, N));
		cur += L;
	}

	int s = l.size();
	vector< vector<TMom> > maxs(s);

	for (int i = 0; i < s; ++i) {
		vector<TTower> sub(a.begin() + l[i], a.begin() + r[i]);
		sort(sub.begin(), sub.end());
		maxs[i].push_back(TMom(0, sub[0].i));
		for (size_t j = 1; j < sub.size(); ++j) {
			TTower cur = sub[j];
			while (!maxs[i].empty() && higher(cur, a[maxs[i].back().x], maxs[i].back().t)) {
				maxs[i].pop_back();
			}
			if (maxs[i].empty()) {
				maxs[i].push_back(TMom(0, cur.i));
			} else {
				maxs[i].push_back(TMom(chase(cur, a[maxs[i].back().x]), cur.i));
			}
		}
	}

	for (int q = 0; q < Q; ++q) {
		int li, ri, t;
		fin >> li >> ri >> t;
		--li;
		long long height = 0;
		int ans = -1;
		for (int i = 0; i < s; ++i) {
			if (li >= r[i] || l[i] >= ri) {
				continue;
			}
			if (li <= l[i] && r[i] <= ri) {
				int low = 0;
				int high = maxs[i].size();
				while (high - low > 1) {
					int mid = (low + high) / 2;
					if (maxs[i][mid].t > t) {
						high = mid;
					} else {
						low = mid;
					}
				}
				int top = maxs[i][low].x;
				if (a[top].x + t * a[top].v > height) {
					height = a[top].x + t * a[top].v;
					ans = top;
				}
			} else {
				for (int j = max(l[i], li); j < min(r[i], ri); ++j) {
					if (a[j].x + t * a[j].v > height) {
						height = a[j].x + t * a[j].v;
						ans = j;
					}
				}
			}
		}
		fout << ans + 1 << '\n';
	}

	return 0;
}