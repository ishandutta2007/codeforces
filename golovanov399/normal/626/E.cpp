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

struct Ans{
	vector<int> a;
	double val;

	Ans(double val = 0):val(val){}
	Ans(const vector<int>& a, double val):a(a),val(val){}

	bool operator <(const Ans& x) const {
		return val < x.val;
	}

	bool operator >(const Ans& x) const {
		return val > x.val;
	}

	void out(){
		sort(all(a));
		printf("%d\n", (int)a.size());
		for (auto x : a)
			printf("%d ", x);
		puts("");
	}
};

double get_res(vector<int> a){
	sort(all(a));
	int n = a.size();
	double med = (n % 2 ? a[n / 2] : 0.5 * (a[n / 2] + a[n / 2 - 1]));
	double avg = 1.0 * accumulate(all(a), 0) / n;
	return fabs(med - avg);
}

void solve(vector<int> a){
	int n = a.size();

	sort(all(a));
	double ans = 0;
	int qw = 0, rad = 0;

	vector<long long> S(n + 1);
	for (itn i = 0; i < n; i++)
		S[i + 1] = S[i] + a[i];

	for (int i = 1; i < n - 1; i++){
		int l = 1;
		int r = min(i, n - 1 - i) + 1;
		while (r > l + 1){
			int mid = (l + r) / 2;
			double avg = 1.0 * (S[i + 1] - S[i - mid] + S[n] - S[n - mid]) / (2 * mid + 1);
			double md = (a[i - mid] + a[n - mid]) * 0.5;
			if (md < avg)
				r = mid;
			else
				l = mid;
		}
		double avg = 1.0 * (S[i + 1] - S[i - l] + S[n] - S[n - l]) / (2 * l + 1);
		if (avg - a[i] > ans){
			ans = avg - a[i];
			qw = i;
			rad = l;
		}
	}

	cout.sync_with_stdio(0);
	// cout << setprecision(10) << fixed;
	// cout << ans << "\n";
	cout << 2 * rad + 1 << "\n";
	for (int i = qw - rad; i <= qw; i++)
		cout << a[i] << " ";
	for (int i = n - rad; i < n; i++){
		cout << a[i] << " ";
	}
	cout << "\n";
}

double stupid(vector<int> a){
	int n = a.size();
	int N = (1 << n);
	double res = 0;
	// int ans = 0;
	for (int mask = 1; mask < N; mask++){
		vector<int> qw;
		for (int i = 0; i < n; i++){
			if (mask & (1 << i)){
				qw.push_back(a[i]);
			}
		}
		sort(all(qw));
		int sz = qw.size();
		double med = (sz % 2 ? qw[sz / 2] : 0.5 * (qw[sz / 2] + qw[sz / 2 - 1]));
		double avg = 1.0 * accumulate(all(qw), 0) / sz;
		double cur = fabs(med - avg);
		if (cur > res){
			res = cur;
			// ans = mask;
		}
	}

	return res;
}

int main(){

	int n = nxt();
	vector<int> a(n);
	for (int i = 0; i < n; i++){
		a[i] = nxt();
	}

	solve(a);

	return 0;
}