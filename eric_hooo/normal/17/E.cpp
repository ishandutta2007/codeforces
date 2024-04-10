#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

const int mod = 51123987;
const int P = 3232323;

char buf[2000010];
string s;
int p[2000010];
int suml[2000010], sumr[2000010];
ull hl[2000010], hr[2000010];
ull power[2000010];
int n;

ull get_hl(int l, int r){return hl[r] - hl[l - 1] * power[r - l + 1];}
ull get_hr(int l, int r){return hr[l] - hr[r + 1] * power[r - l + 1];}

bool check(int i, int j, int len){
	if (len == 0) return 1;
	if (i - len + 1 < 1 || j + len - 1 > n) return 0;
	return get_hl(i - len + 1, i) == get_hr(j, j + len - 1);
}

void work(int i, int j){
	int l = 0, r = n;
	while (l < r){
		int mid = l + r + 1 >> 1;
//		cout << "  " << l << " " << r << " " << mid << endl;
		if (check(i, j, mid)) l = mid;
		else r = mid - 1;
	}
	int len = l;
	suml[i - len + 1]++, suml[i + 1]--;
	sumr[j]++, sumr[j + len]--;
}

int main(){
	scanf("%d", &n);
	scanf("%s", buf), s = buf;
	s = " " + s, power[0] = 1;
	for (int i = 1; i <= n; i++){
		power[i] = power[i - 1] * P;
		hl[i] = hl[i - 1] * P + s[i] - 'a' + 1;
	}
	for (int i = n; i >= 1; i--){
		hr[i] = hr[i + 1] * P + s[i] - 'a' + 1;
	}
	for (int i = 1; i <= n; i++){
		work(i, i);
		if (i != 1) work(i - 1, i);
	}
	long long ans = 0, now = 0;
	for (int i = 1; i <= n; i++){
		suml[i] += suml[i - 1];
		sumr[i] += sumr[i - 1];
		ans = (ans + now * suml[i] % mod + 1ll * suml[i] * (suml[i] - 1) / 2 % mod) % mod;
		now = (now + suml[i] - sumr[i] + mod) % mod;
	}
	printf("%I64d\n", ans);
	return 0;
}