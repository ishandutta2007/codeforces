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

const int N = 222222;
const int K = 30;
int a[N];
int cn[K];
int pw[K];

int main(){

	int n = nxt(), k = nxt(), x = nxt();
	long long qw = 1;
	for (int i = 0; i < k; i++)
		qw *= x;

	for (int i = 0; i < K; i++)
		pw[i] = (1 << i);

	for (int i = 0; i < n; i++){
		int q = nxt();
		a[i] = q;
		for (int j = 0; j < K; j++){
			if (q & pw[j])
				cn[j]++;
		}
	}

	long long ans = 0;
	for (int i = 0; i < K; i++){
		if (cn[i])
			ans |= pw[i];
	}

	long long res = 0;
	for (int i = 0; i < N; i++){
		long long cur = ans;
		for (int j = 0; j < K; j++){
			if ((a[i] & pw[j]) && cn[j] == 1)
				cur ^= pw[j];
		}
		res = max(res, (1ll * a[i] * qw) | cur);
	}
	cout << res << "\n";

	return 0;
}