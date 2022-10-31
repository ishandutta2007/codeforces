#include <bits/stdc++.h>


using namespace std;


using ll = long long;
mt19937 mt(736);

using point = pair<double, double>;
using ipoint = pair<int, int>;


const int miss = 30000;


ipoint operator-(ipoint a, ipoint b)
{
	return {a.first - b.first, a.second - b.second};
}


template<class T>
T dist(T d, T r1, T r2)
{
	auto ans = numeric_limits<T>::max();

	for (int a : {-1, 1})
		for (int b : {-1, 1})
			ans = min(ans, d + a * r1 + b * r2);

	return ans;
}


template<class T>
T sqr(T x)
{
	return x * x;
}


double len2(ipoint A)
{
	return sqr((ll) A.first) + sqr((ll) A.second);
}


point circumcircle(ipoint A, ipoint B, ipoint C)
{
	auto D = A.first * (B.second - (double) C.second) + B.first * (C.second - (double) A.second) +
	         C.first * (A.second - (double) B.second);
	D *= 2;


	double x = (len2(A) * (B.second - C.second) + (len2(B)) * (C.second - A.second) +
	            len2(C) * (A.second - B.second)) / D;
	double y = (len2(A) * (C.first - B.first) + len2(B) * (A.first - C.first) +
	            len2(C) * (B.first - A.first)) / D;

	ipoint U(x, y);

	if (max(abs(x), abs(y)) > 1e6 || len2(U) > 1e12)
		return {numeric_limits<int>::max(), numeric_limits<int>::max()};
	return U;
}


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int k, n;

	cin >> k >> n;

	vector<ipoint> pts(n * k);

	for (auto &it : pts)
		cin >> it.first >> it.second;

	shuffle(pts.begin(), pts.end(), mt);

	while (true)
	{
		vector<ipoint> bad = pts;
		vector<pair<ipoint, int>> centers;

		for (int i = 0; i < 1e3 && !bad.empty(); i++)
		{
			shuffle(bad.begin(), bad.end(), mt);

			if (bad.size() < 3)
			{
				// do something
				break;
			}
			else
			{
				auto cent = circumcircle(bad[0], bad[1], bad[2]);

				if (cent.first != numeric_limits<int>::max())
				{
					int r = (int) round(sqrt(len2(cent - bad[0])));
					int cnt = 0;

					r = min(r, 750000);
					r = max(r, 250000);

					for (auto it : pts)
						if (abs(sqrt(len2(cent - it)) - r) <= 0.1 * r + miss)
							cnt++;

					if (cnt >= n)
					{
						if (centers.size() < k)
						{
							centers.emplace_back(cent, r);
						}
						else
						{
							vector<int> d(k);

							for (int j = 0; j < k; j++)
								d[j] = dist((int) sqrt(len2(centers[j].first - cent)), centers[j].second, r);

							int wh = min_element(d.begin(), d.end()) - d.begin();

							centers[wh].first.first = (centers[wh].first.first + cent.first) / 2;
							centers[wh].first.second = (centers[wh].first.second + cent.second) / 2;
							centers[wh].second = (centers[wh].second + r) / 2;
						}
					}
				}
			}

			bad.clear();

			for (auto it : pts)
			{
				bool good = false;

				for (auto cent : centers)
				{
					if (abs(sqrt(len2(cent.first - it)) - cent.second) <= 0.1 * cent.second + miss)
					{
						good = true;
						break;
					}
				}

				if (!good)
					bad.push_back(it);
			}
		}

		if (bad.empty() && centers.size() == k)
		{
			for (auto it : centers)
				cout << it.first.first << ' ' << it.first.second << ' ' << it.second << endl;

			return;
		}
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cout << fixed;

#ifdef LOCAL
	ifstream fin("../input.txt");

	solve(fin);

	cout << setprecision(4);
	cout << "clock: " << clock() / (double) CLOCKS_PER_SEC << endl;
#else
	solve();
#endif

	return 0;
}