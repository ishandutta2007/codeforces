/*input
10
35 1 2 1 2 35 100 200 100 200
*/
#include <bits/stdc++.h>

using namespace std;

struct medis {
	int f, t;
	int val = INT_MAX;
	medis *kair = NULL, *des = NULL;
	medis(int f, int t) : f(f), t(t) {
		assert(f <= t);

		if (f == t)
			return;

		int vid = (f + t) / 2;
		kair = new medis(f, vid);
		des = new medis(vid + 1, t);
	}
	void add(int viet, int vall) {
		assert(f <= t);

		val = min(val, vall);

		if (f == t)
			return;

		int vid = (f + t) / 2;

		if (viet <= vid)
			kair->add(viet, vall);
		else
			des->add(viet, vall);
	}
	int get(int fr, int to) {
		if (to < f or t < fr)
			return INT_MAX;

		if (fr <= f and t <= to)
			return val;

		return min(kair->get(fr, to), des->get(fr, to));
	}
};

int main () {
	int n;
	cin >> n;
	int sk[n];

	for (int i = 0; i < n; i++)
		cin >> sk[i];

	int sek[n];

	for (int i = 0; i < n; i++)
		sek[i] = INT_MAX;

	{
		map<int, int> buv;

		for (int i = n - 1; i >= 0; i--) {
			if (buv.count(sk[i]) > 0)
				sek[i] = buv[sk[i]];

			buv[sk[i]] = i;
		}
	}

	medis me(0, n - 1);

	int din[n];
	int firr[n];
	int secc[n];

	for (int i = 0; i < n; i++)
		din[i] = n;

	pair<int, int> eil[n];

	for (int i = 0; i < n; i++)
		eil[i] = make_pair(sek[i], i);

	sort(eil, eil + n, [](const auto & i, const auto & j) -> bool {
		return i > j;
	});

	for (int i = 0; i < n; i++) {
		if (eil[i].first >= INT_MAX)
			continue;

		int dab = eil[i].second;
		int &tol = din[dab];
		int &fir = firr[dab];
		int &sec = secc[dab];

		if (dab + 1 != sek[dab]) {
			if (sek[dab] < n) {
				int ge = me.get(dab + 1, sek[dab] - 1);
				if (ge < tol) {
					tol = ge;
					fir = sk[dab];
					sec = sk[ge];
				}
			}
		}

		if (sek[dab] < tol and sek[sek[dab]] < tol and sek[sek[sek[dab]]] < tol) {
			tol = sek[sek[sek[dab]]];
			fir = sk[dab];
			sec = sk[dab];
		}

		me.add(eil[i].second, eil[i].first);
	}

	int tol = n;
	int dab = 0;
	vector<int> ats;

	while (dab < n) {
		int opt = 0;

		while (dab <= tol and dab < n) {
			if (tol > din[dab]) {
				tol = din[dab];
				opt = dab;
			}

			dab++;
		}

		if (tol == n)
			break;

		dab = tol + 1;
		tol = n;
		ats.push_back(firr[opt]);
		ats.push_back(secc[opt]);
		ats.push_back(firr[opt]);
		ats.push_back(secc[opt]);
	}

	cout << ats.size() << endl;

	for (auto && i : ats)
		cout << i << " ";

	return 0;
}