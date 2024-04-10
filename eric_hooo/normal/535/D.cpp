#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000007;

char buf[1000010];
string s;
int z[1000010];

int power(int a, int b){
	if (b == 0) return 1;
	long long t = power(a, b / 2);
	return b & 1 ? t * t % mod * a % mod : t * t % mod;
}

void get_z(){
	int n = s.length();
	int L = 0, R = 0;
	for (int i = 1; i < n; i++){
		if (R < i){
			L = R = i;
			while (R < n && s[R - i] == s[R]) R++;
			z[i] = R - L, R--;
			continue;
		}
		int pos = i - L;
		if (z[pos] + i < R){
			z[i] = z[pos];
			continue;
		}
		L = i;
		while (R < n && s[R - i] == s[R]) R++;
		z[i] = R - L, R--;
	}
}

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	scanf("%s", buf), s = buf, get_z();
	int len = s.length();
	int last = 1, tot = 0;
	for (int i = 0; i < m; i++){
		int a; scanf("%d", &a);
		if (a >= last){
			tot += a - last;
			last = a + len;
			continue;
		}
		if (z[len - (last - a)] != last - a){
			printf("0\n");
			return 0;
		}
		last = a + len;
	}
	tot += n + 1 - last;
	printf("%d\n", power(26, tot));
	return 0;
}