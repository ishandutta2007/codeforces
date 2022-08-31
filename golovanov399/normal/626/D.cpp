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

const int N = 5555;
long long cnt[N * 2];

int main(){

	int n = nxt();
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		a[i] = nxt();
	vector<int> diff;
	sort(all(a));
	for (int i = 0; i < n; i++){
		for (int j = 0; j < i; j++){
			diff.push_back(a[i] - a[j]);
		}
	}

	long long ans = 0;
	sort(all(diff));
	int sz = diff.size();
	vector<int> cn(N);
	for (auto x : diff){
		cn[x]++;
		// cerr << x << " ";
	}

	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			cnt[i + j] += 1ll * cn[i] * cn[j];
		}
	}

	// for (int i = 0; i < 10; i++)
	// 	cerr << cnt[i] << " ";
	// cerr << "\n";
	// for (int i = 0; i < 10; i++)
	// 	cerr << cn[i] << " ";
	// cerr << "\n";

	long long S = 0;
	for (int i = 0; i < N; i++){
		ans += S * cn[i];
		S += cnt[i];
	}

	cout << setprecision(10) << fixed;
	cout << 1.0 * ans / sz / sz / sz << "\n";

	return 0;
}