#include <bits/stdc++.h>
using namespace std;

const int maxN = 200005;

int a[maxN], b[maxN];
array<long long, 2> coef[maxN];
array<long long, 2> pref[maxN];
array<long long, 2> suff[maxN];

inline array<long long, 2> operator+(array<long long, 2> x, array<long long, 2> y){
	return array<long long, 2>({x[0] + y[0], x[1] + y[1]});
}

inline array<long long, 2> operator-(array<long long, 2> x, array<long long, 2> y){
	return array<long long, 2>({x[0] - y[0], x[1] - y[1]});
}

inline long long eval(array<long long, 2> &p, int x){
	return p[1]*x - p[0];
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++){
		cin >> b[i];
	}
	coef[1][0] = -a[1]; coef[1][1] = 1;
	for(int i = 2; i <= n; i++){
		coef[i][0] = b[i] - a[i];
		coef[i][1] = 0;
	}
	for(int i = 1; i <= n; i++){
		for(int j = i + i; j <= n; j += i){
			coef[j] = coef[j] - coef[i];
		}
		if(coef[i][1] < 0){
			coef[i][0] = -coef[i][0];
			coef[i][1] = -coef[i][1];
		}
		coef[i][0] = -coef[i][0];
	}
	long long ans = 0;
	int m = 0;
	for(int i = 1; i <= n; i++){
		if(coef[i][1] == 0){
			ans += abs(coef[i][0]);
		}else{
			coef[m + 1] = coef[i]; m++;
		}
	}
	sort(coef + 1, coef + m + 1, [&](array<long long, 2> p, array<long long, 2> q){
		return p[0]*q[1] < p[1]*q[0];
	});
	pref[0][0] = suff[m + 1][0] = 0;
	pref[0][1] = suff[m + 1][1] = 0;
	for(int i = 1; i <= m; i++){
		pref[i] = coef[i] + pref[i - 1];
	}
	for(int i = m; i >= 1; i--){
		suff[i] = coef[i] + suff[i + 1];
	}
	int q;
	cin >> q;
	while(q--){
		int x;
		cin >> x;
		if(eval(coef[1], x) < 0){
			cout << ans + abs(eval(pref[m], x)) << '\n';
			continue;
		}
		int lo = 1, hi = m;
		while(lo < hi){
			int mi = (lo + hi + 1)/2;
			if(eval(coef[mi], x) >= 0){
				lo = mi;
			}else{
				hi = mi - 1;
			}
		}
		cout << ans + abs(eval(pref[lo], x)) + abs(eval(suff[lo + 1], x)) << '\n';
	}

	return 0;
}