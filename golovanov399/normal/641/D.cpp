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

pair<long double, long double> res(long double sum, long double prod){
	long double D = sum * sum - 4 * prod;
	D = sqrtl(D);
	sum *= 0.5;
	D *= 0.5;
	return {sum - D, sum + D};
}

int main(){

	cin.sync_with_stdio(0);
	cout.sync_with_stdio(0);

	int n;
	cin >> n;
	vector<long double> a(n), b(n);
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	for (int i = 0; i < n; i++){
		cin >> b[i];
	}

	for (int i = 1; i < n; i++)
		a[i] += a[i - 1];

	for (int i = n - 1; i > 0; i--)
		b[i - 1] += b[i];

	vector<long double> s(n, 1), t(n, 1);
	for (int i = 1; i < n; i++){
		auto p = res(a[i - 1] - b[i] + 1, a[i - 1]);
		s[i - 1] = p.first;
		t[i - 1] = p.second;
		// cerr << s[i - 1] << " " << t[i - 1] << "\n";
	}

	for (int i = n - 1; i > 0; i--){
		s[i] -= s[i - 1];
		t[i] -= t[i - 1];
	}

	cout << setprecision(10) << fixed;
	for (int i = 0; i < n; i++)
		cout << (double)s[i] << " ";
	cout << "\n";
	for (int i = 0; i < n; i++)
		cout << (double)t[i] << " ";
	cout << "\n";

	return 0;
}