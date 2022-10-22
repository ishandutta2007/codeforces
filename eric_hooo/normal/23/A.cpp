#include <bits/stdc++.h>
using namespace std;

const int mod = 10000019;

char buf[110];
int t[10000020];
string s;
int power[110], sum[110];

int get_hash(int i, int len){
	int j = i + len - 1;
	return (sum[j] - 1ll * sum[i - 1] * power[len] % mod + mod) % mod;
}

int main(){
	scanf("%s", buf), s = buf, s = " " + s;
	int n = s.length();
	power[0] = 1;
	for (int i = 1; i <= n; i++){
		power[i] = power[i - 1] * 26 % mod;
	}
	for (int i = 1; i < n; i++){
		sum[i] = (sum[i - 1] * 26 % mod + s[i] - 'a') % mod;
	}
	for (int len = n - 1; len > 0; len--){
		for (int i = 1; i <= n - len; i++){
			t[get_hash(i, len)]++;
			if (t[get_hash(i, len)] == 2){
				printf("%d\n", len);
				return 0;
			}
		}
		for (int i = 1; i <= n - len; i++){
			t[get_hash(i, len)]--;
		}
	}
	printf("0\n");
	return 0;
}