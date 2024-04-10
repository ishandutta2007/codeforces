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

void rec(int mid, const vector<vector<int>>& pp, vector<pair<pair<int, int>, int>>& a, int kk = 0){
	vector<int> qw(mid);
	pair<int, int> cur;
	int qq = 0;
	cur.first = cur.second = -accumulate(pp[0].begin() + kk, pp[0].begin() + kk + mid, 0);
	do {
		a.push_back({cur, qq++});
		int i = mid - 1;
		do {
			if (qw[i] == 0){
				cur.first += pp[0][kk + i] + pp[1][kk + i];
				cur.second += pp[0][kk + i];
				qw[i] = 1;
				break;
			}
			else
			if (qw[i] == 1){
				cur.first -= pp[1][kk + i];
				cur.second += pp[2][kk + i];
				qw[i] = 2;
				break;
			} else {
				cur.first -= pp[0][kk + i];
				cur.second -= pp[0][kk + i] + pp[2][kk + i];
				qw[i] = 0;
				i--;
			}
		} while (i >= 0);
		if (i < 0)
			break;
	} while (qw[0] < 3);
}

int main(){

	int n = nxt();
	vector<vector<int>> p(3, vector<int>(n));
	for (int i = 0; i < n; i++){
		p[0][i] = nxt(), p[1][i] = nxt(), p[2][i] = nxt();
	}

	if (n == 1){
		if (!p[0][0] && !p[1][0])
			puts("LM");
		else if (!p[0][0] && !p[2][0])
			puts("LW");
		else if (!p[1][0] && !p[2][0])
			puts("MW");
		else
			puts("Impossible");
		return 0;
	}

	int S = accumulate(all(p[1]), 0) - accumulate(all(p[0]), 0);
	int T = accumulate(all(p[2]), 0) - accumulate(all(p[0]), 0);

	int mid = (n + 1) / 2;
	vector<pair<pair<int, int>, int>> a, b;
	rec(mid, p, a);
	rec(n - mid, p, b, mid);

	// cerr << a.size() << " " << b.size() << "\n";
	sort(all(a));
	sort(all(b));
	reverse(all(b));

	// for (auto x : a){
	// 	cerr << x.first.first << " " << x.first.second << " " << x.second << "\n";
	// }

	int l = 0, r = 0;
	vector<pair<int, pair<int, int>>> ans;
	while (l < a.size() && r < b.size()){
		int x = a[l].first.first + b[r].first.first;
		if (x < S)
			l++;
		else if (x > S)
			r++;
		else {
			x = a[l].first.second + b[r].first.second;
			if (x < T)
				l++;
			else if (x > T)
				r++;
			else {
				// cerr << a[l].first.first << " " << a[l].first.second << " " << a[l].second << "\n";
				// cerr << b[r].first.first << " " << b[r].first.second << " " << b[r].second << "\n";
				
				int cr = 0;

				x = a[l].second;
				vector<int> res;
				for (int i = 0; i < mid; i++){
					res.push_back(x % 3);
					x /= 3;
				}
				reverse(all(res));
				for (int i = 0; i < mid; i++){
					if (res[i] == 0)
						continue;
					cr += p[0][i];
				}
				res.clear();

				x = b[r].second;
				for (int i = 0; i < n - mid; i++){
					res.push_back(x % 3);
					x /= 3;
				}
				reverse(all(res));
				for (int i = 0; i < n - mid; i++){
					if (res[i] == 0)
						continue;
					cr += p[0][mid + i];
				}

				ans.push_back({cr, {l, r}});
				l++;
				r++;

			}
		}
	}

	if (ans.empty())
		puts("Impossible");
	else {
		auto v = *max_element(all(ans));
		int l = v.second.first, r = v.second.second;
		int	x = a[l].second;
		vector<int> res;
		for (int i = 0; i < mid; i++){
			res.push_back(x % 3);
			x /= 3;
		}
		reverse(all(res));
		for (auto x : res){
			if (x % 3 == 0)
				puts("MW");
			else if (x % 3 == 1)
				puts("LW");
			else
				puts("LM");
		}
		res.clear();
		x = b[r].second;
		for (int i = 0; i < n - mid; i++){
			res.push_back(x % 3);
			x /= 3;
		}
		reverse(all(res));
		for (auto x : res){
			if (x % 3 == 0)
				puts("MW");
			else if (x % 3 == 1)
				puts("LW");
			else
				puts("LM");
		}
	}

	return 0;
}