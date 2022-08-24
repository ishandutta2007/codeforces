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

int main(){

	int n = nxt(), k = nxt();
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		a[i] = nxt();

	vector<long long> s(n + 1);
	vector<long double> t(n + 1);
	vector<long double> S(n + 1);
	s[0] = t[0] = 0;
	for (int i = 0; i < n; i++){
		s[i + 1] = s[i] + a[i];
		t[i + 1] = t[i] + 1.0 / a[i];
		S[i + 1] = S[i] + 1.0 * s[i + 1] / a[i];
	}

	vector<long double> res = S;
	res[0] = 0;
	// for (auto x : res)
	// 	cerr << x << " ";
	// cerr << "\n";
	cout << setprecision(10) << fixed;
	for (int _ = 1; _ < k; _++){
		for (int i = 0; i < n; i++){
			res[i] += s[i] * t[i] - S[i];
		}
		vector<long double> ans(n + 1);
		int cur = 0;
		vector<int> conv(1, _);
		for (int i = _ + 1; i <= n; i++){
			while (cur + 1 < conv.size()){
				int x = conv[cur], y = conv[cur + 1];
				long double pos = (res[x] - res[y]) / (s[x] - s[y]);
				if (t[i] > pos)
					cur++;
				else
					break;
			}
			// while (cur + 1 < i && res[cur] - s[cur] * t[i] > res[cur + 1] - s[cur + 1] * t[i])
				// cur++;
			ans[i] = S[i] + res[conv[cur]] - s[conv[cur]] * t[i];
			while (conv.size() > 1){
				int x = conv.back(), y = conv[conv.size() - 2];
				long double pos = (res[x] - res[y]) / (s[x] - s[y]);
				long double npos = (res[i] - res[y]) / (s[i] - s[y]);
				if (npos < pos)
					conv.pop_back();
				else
					break;
			}
			conv.push_back(i);
			cur = min(cur, (int)conv.size() - 1);
		}

		// for (auto x : ans)
		// 	cerr << x << " ";
		// cerr << "\n";

		res.swap(ans);
	}

	cout << res.back() << "\n";

	return 0;
}