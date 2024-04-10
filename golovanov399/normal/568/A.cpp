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

const int N = 1200000;
int a[N];

inline bool is_ok(int x){
	vector<int> ar;
	while (x){
		ar.push_back(x % 10);
		x /= 10;
	}
	int n = ar.size();
	for (int i = 0; i < n - 1 - i; i++)
		if (ar[i] != ar[n - 1 - i])
			return false;
	return true;
}

int main(){

	for (int i = 2; i < N; i++){
		if (a[i] == 0){
			if (i < sqrt(N + N)){
				for (int j = i * i; j < N; j += i){
					if (a[j] == 0)
						a[j] = i;
				}
			}
		}
	}
	a[1] = 1;

	vector<pair<int, pair<int, int>>> qw(1, {1, {0, 1}});

	int pi = 0, rub = 1;
	for (int i = 2; i < N; i++){
		if (a[i] == 0)
			pi++;
		if (is_ok(i))
			rub++;
		while (1ll * pi * qw.back().second.second <= 1ll * qw.back().second.first * rub)
			qw.pop_back();
		qw.push_back({i, {pi, rub}});
	}

	int p = nxt(), q = nxt();
	int ans = 0;
	for (auto x : qw){
		if (x.second.first * q > x.second.second * p){
			printf("%d\n", ans);
			return 0;
		}
		ans = x.first;
	}
	printf("%d\n", ans);

	return 0;
}