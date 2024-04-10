#include <bits/stdc++.h>
using namespace std;

long long n, a[120][5], cnt[5];

inline long long getScore(long long t, long long c, long long n){
	if(c*2 > n){
		return 500 - 2*t;
	}else if(c*4 > n){
		return 1000 - 4*t;
	}else if(c*8 > n){
		return 1500 - 6*t;
	}else if(c*16 > n){
		return 2000 - 8*t;
	}else if(c*32 > n){
		return 2500 - 10*t;
	}else{
		return 3000 - 12*t;
	}
}

inline bool check(long long m){
	long long diff = 0;
	for(int i = 0; i < 5; i++){
		if(a[0][i] == -1 && a[1][i] == -1){
			continue;
		}else if(a[0][i] == -1){
			diff -= getScore(a[1][i], cnt[i], n + m);
		}else if(a[1][i] == -1){
			diff += getScore(a[0][i], cnt[i], n + m);
		}else{
			long long tmp0 = getScore(a[0][i], cnt[i], n + m) - getScore(a[1][i], cnt[i], n + m);
			long long tmp1 = getScore(a[0][i], cnt[i] + m, n + m) - getScore(a[1][i], cnt[i] + m, n + m);
			diff += max(tmp0, tmp1);	
		}
	}
	return diff > 0;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	memset(cnt, 0, sizeof(cnt));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < 5; j++){
			cin >> a[i][j];
			if(a[i][j] != -1)cnt[j]++;
		}
	}
	for(int i = 0; i <= 100000; i++){
		if(check(i)){
			cout << i << '\n';
			exit(0);
		}
	}
	cout << -1 << '\n';

	return 0;
}