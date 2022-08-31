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

	int n = nxt();
	vector<long long> a(n);
	for (int i = 0; i < n; i++)
		a[i] = nxt() * 2;
	int m = nxt();
	vector<long long> b(m);
	for (int i = 0; i < m; i++)
		b[i] = nxt() * 2;

	vector<pair<long long, long long>> q1(n), q2(m);
	for (int i = 0; i < n; i++)
		q1[i] = {a[i], i};
	for (int i = 0; i < m; i++)
		q2[i] = {b[i], i};

	sort(all(q1));
	sort(all(q2));
	for (int i = 0; i < n; i++)
		a[i] = q1[i].first;
	for (int i = 0; i < m; i++)
		b[i] = q2[i].first;
	vector<pair<int, int>> ans;
	long long res = LLONG_MAX;
	long long s = 0;
	for (auto x : a)
		s += x / 2;
	for (auto x : b)
		s += x / 2;

	long long qw = 0;
	for (auto x : a)
		qw += x;
	res = abs(qw - s);

	// cerr << s << " " << qw << "\n";

	for (int i = 0; i < m; i++){
		int j = lower_bound(all(a), -s + qw + b[i]) - a.begin();
		int jj = j - 1;
		if (j < n && abs(qw + b[i] - a[j] - s) < res){
			res = abs(qw + b[i] - a[j] - s);
			ans.resize(1);
			ans[0] = {j, i};
		}
		if (jj >= 0 && abs(qw + b[i] - a[jj] - s) < res){
			res = abs(qw + b[i] - a[jj] - s);
			ans.resize(1);
			ans[0] = {jj, i};
		}
	}

	vector<pair<long long, pair<int, int>>> A, B;
	for (int i = 0; i < n; i++){
		for (int j = i + 1; j < n; j++){
			A.push_back({a[i] + a[j], {i, j}});
		}
	}
	for (int i = 0; i < m; i++){
		for (int j = i + 1; j < m; j++){
			B.push_back({b[i] + b[j], {i, j}});
		}
	}

	sort(all(A));
	sort(all(B));

	// for (auto x : A)
	// 	cerr << x.first << " ";
	// cerr << "\n";
	// for (auto x : B)
	// 	cerr << x.first << " ";
	// cerr << "\n";

	int N = A.size(), M = B.size();
	for (int i = 0; i < M; i++){
		int j = lower_bound(all(A), make_pair(-s + qw + B[i].first, make_pair(0, 0))) - A.begin();
		int jj = j - 1;
		// cerr << B[i].first << " " << A[j].first << " " << A[jj].first << "\n";
		// cerr << i << " " << j << " " << jj << "\n";
		if (j < N && abs(qw + B[i].first - A[j].first - s) < res){
			res = abs(qw + B[i].first - A[j].first - s);
			ans.resize(2);
			ans[0] = {A[j].second.first, B[i].second.first};
			ans[1] = {A[j].second.second, B[i].second.second};
		}
		if (jj >= 0 && abs(qw + B[i].first - A[jj].first - s) < res){
			res = abs(qw + B[i].first - A[jj].first - s);
			ans.resize(2);
			ans[0] = {A[jj].second.first, B[i].second.first};
			ans[1] = {A[jj].second.second, B[i].second.second};
		}
	}

	cout << res << "\n";
	cout << ans.size() << "\n";
	for (auto p : ans){
		cout << q1[p.first].second + 1 << " " << q2[p.second].second + 1 << "\n";
	}

	return 0;
}