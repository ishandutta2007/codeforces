#include <bits/stdc++.h>
using namespace std;

const long long P = 10, mod = 1000000007;

char buf[1000010];
string s;
long long h[1000010], power[1000010];
int n;

long long get_h(int l, int r){
	return (h[r] - h[l - 1] * power[r - l + 1] % mod + mod) % mod;
}

void print(int a, int b){
	for (int i = 1; i <= n; i++){
		if (i == a) printf("+");
		if (i == b) printf("=");
		printf("%c", s[i]);
	}
}

int main(){
	scanf("%s", buf), s = buf;
	n = s.length();
	s = " " + s;
	power[0] = 1;
	for (int i = 1; i <= n; i++){
		h[i] = h[i - 1] * P % mod + s[i] - '0', h[i] %= mod;
		power[i] = power[i - 1] * P % mod;
	}
	for (int i = n; i >= 1; i--){
		long long c = get_h(i, n);
		int len = n - i + 1;
		if (s[i] == '0' && len != 1) continue;
		{
			int pos = i - len;
			long long a = get_h(1, pos - 1), b = get_h(pos, i - 1);
			if ((len - max(pos - 1, i - pos) == 0 || len - max(pos - 1, i - pos) == 1) && (a + b) % mod == c && !(pos - 1 != 1 && s[1] == '0') && !(i - pos != 1 && s[pos] == '0')){
				print(pos, i);
				return 0;
			}
			a = get_h(1, pos), b = get_h(pos + 1, i - 1);
			if ((len - max(pos, i - pos - 1) == 0 || len - max(pos, i - pos - 1) == 1) && (a + b) % mod == c && pos + 1 != i && !(pos != 1 && s[1] == '0') && !(i - pos - 1 != 1 && s[pos + 1] == '0')){
				print(pos + 1, i);
				return 0;
			}
		}
		{
			int pos = len;
			long long a = get_h(1, pos - 1), b = get_h(pos, i - 1);
			if ((len - max(pos - 1, i - pos) == 0 || len - max(pos - 1, i - pos) == 1) && (a + b) % mod == c && !(pos - 1 != 1 && s[1] == '0') && !(i - pos != 1 && s[pos] == '0')){
				print(pos, i);
				return 0;
			}
			a = get_h(1, pos), b = get_h(pos + 1, i - 1);
			if ((len - max(pos, i - pos - 1) == 0 || len - max(pos, i - pos - 1) == 1) && (a + b) % mod == c && pos != 1 && !(pos != 1 && s[1] == '0') && !(i - pos - 1 != 1 && s[pos + 1] == '0')){
				print(pos + 1, i);
				return 0;
			}
		}
	}
	return 0;
}