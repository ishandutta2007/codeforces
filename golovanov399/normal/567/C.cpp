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
	for (int i = 0; i < n; i++){
		a[i] = nxt();
	}
	vector<int> l(n), r(n);
	map<int, int> M, N;
	for (int i = 0; i < n; i++){
		if (a[i] % k == 0)
			l[i] = M[a[i] / k];
		if (M.count(a[i]))
			M[a[i]]++;
		else
			M[a[i]] = 1;
	}
	for (int i = n - 1; i >= 0; i--){
		if (a[i] % k == 0 && abs(a[i]) < 1.5e9 / k)
			r[i] = N[a[i] * k];
		if (N.count(a[i]))
			N[a[i]]++;
		else
			N[a[i]] = 1;
	}
	long long ans = 0;
	for (int i = 0; i < n; i++)
		ans += 1ll * l[i] * r[i];
	cout << ans << "\n";

	return 0;
}