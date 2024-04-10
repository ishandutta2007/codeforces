#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000007;

char buf[2010];
string s, t1, t2;
int can_t1[2010], can_t2[2010];
long long power[2010];
long long sum[2010];

string read(){
	scanf("%s", buf);
	return buf;
}

int check(string a, string b, int s){
	for (int i = 0; i < b.length(); i++){
		if (a[i + s] != b[i]) return 0;
	}
	return 1;
}

void init(string s){
	power[0] = 1;
	for (int i = 1; i <= s.length(); i++){
		power[i] = power[i - 1] * 255;
	}
	for (int i = s.length() - 1; i >= 0; i--){
		sum[i] = sum[i + 1] * 255 + s[i];
	}
}

long long get_h(int a, int b){
	return sum[a] - sum[a + b] * power[b];
}

int main(){
	s = read(), t1 = read(), t2 = read();
	int n = s.length(), a = t1.length(), b = t2.length();
	init(s);
	for (int i = 0; i <= n - a; i++){
		can_t1[i] = check(s, t1, i);
	}
	for (int i = b - 1; i <= n; i++){
		can_t2[i] = check(s, t2, i - b + 1);
	}
	int res = 0;
	for (int len = max(a, b); len <= n; len++){
		vector <long long> v;
		for (int i = 0; i <= n - len; i++){
			if (can_t1[i] && can_t2[i + len - 1]) v.push_back(get_h(i, len));
		}
		sort(v.begin(), v.end());
		v.erase(unique(v.begin(), v.end()), v.end());
		res += v.size();
	}
	printf("%d\n", res);
	return 0;
}