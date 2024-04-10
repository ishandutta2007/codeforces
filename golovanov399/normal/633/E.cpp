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

const int N = 1111111;
const int K = 22;

int V[N][K], C[N][K];

int main(){

	int n = nxt(), k = nxt();
	vector<int> v(n), c(n);
	for (int i = 0; i < n; i++)
		v[i] = nxt() * 100;
	for (int i = 0; i < n; i++)
		c[i] = nxt();

	// for (int i = 0; i < n; i++){
	// 	for (int j = i; j < n; j++){
	// 		cerr << i << ", " << j << ": " << tree_v.get(i, j + 1) << ", " << inf-tree_c.get(i, j + 1) << "\n";
	// 	}
	// }

	for (int i = 0; i < n; i++){
		V[i][0] = v[i];
		C[i][0] = c[i];
	}
	for (int j = 1; (1 << j) <= n; j++){
		int J = (1 << j);
		for (int i = 0; i + J <= N; i++){
			V[i][j] = max(V[i][j - 1], V[i + J / 2][j - 1]);
			C[i][j] = min(C[i][j - 1], C[i + J / 2][j - 1]);
		}
	}

	// cerr << "qwe\n";

	vector<int> val(n);
	for (itn i = 0; i < n; i++){
		// if (i % (n / 10) == 0)
		// 	cerr << i << "\n";
		int l = i + 1;
		int cur_v = v[i], cur_c = c[i];
		for (int j = K - 1; j >= 0; j--){
			if (l + (1 << j) > n)
				continue;
			if (max(cur_v, V[l][j]) <= min(cur_c, C[l][j])){
				cur_v = max(cur_v, V[l][j]);
				cur_c = min(cur_c, C[l][j]);
				l += (1 << j);
			}
		}
		val[i] = min(cur_v, cur_c);
		if (l < n){
			cur_v = max(cur_v, v[l]);
			cur_c = min(cur_c, c[l]);
			val[i] = max(val[i], min(cur_v, cur_c));
		}
	}

	// cerr << "rty\n";

	sort(all(val));

	long double ans = 0;
	long double cur = 1;
	int pr = 0;
	for (int i = 0; i + k - 1 < n; i++){
		ans += cur * (val[i] - pr);
		pr = val[i];
		cur = cur * (n - k - i) / (n - i);
	}

	cout << setprecision(10) << fixed;
	cout << ans << "\n";

	return 0;
}