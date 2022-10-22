#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;

const int mod = 1000000007;
const int P = 3232323;

char buf[100010];
string s, t;
int fail[100010], pos[100010];
long long hl[100010], hr[100010], power[100010]; 
int n, all;

void getfail(string &s){
	fail[0] = -1;
	int j = -1;
	for (int i = 1; i <= n; i++){
		while (~j && s[j] != s[i - 1]) j = fail[j];
		fail[i] = ++j;
		if (i != n && s[i] == s[fail[i]] && ~fail[fail[i]]) fail[i] = fail[fail[i]];
	}
}

void match(string &s, string &t){
	int j = 0;
	for (int i = 0; i < n; i++){
		while (~j && t[i] != s[j]) j = fail[j];
		j++, all = max(all, j);
		if (pos[j] == -1) pos[j] = i + 1;
	}
	pos[0] = 0;
}

long long get_hl(int l, int r){return (hl[r] - hl[l - 1] * power[r - l + 1] % mod + mod) % mod;}
long long get_hr(int l, int r){return (hr[l] - hr[r + 1] * power[r - l + 1] % mod + mod) % mod;}

int check(int x, int len){
	return get_hl(x - len + 1, x) == get_hr(x, x + len - 1);
}

int max_len(int x){
	int l = 1, r = min(x, n - x + 1);
	while (l < r){
		int mid = l + r + 1 >> 1;
		if (check(x, mid)) l = mid;
		else r = mid - 1;
	}
	return l;
}

int main(){
	memset(pos, -1, sizeof(pos));
	scanf("%s", buf), s = buf;
	n = s.size(), t = s;
	reverse(t.begin(), t.end());
	getfail(t), match(t, s);
//	cout << "pos:";
//	for (int i = 0; i <= n; i++){
//		cout << pos[i] << " ";
//	}
//	cout << endl;
	s = " " + s;
	power[0] = 1;
	for (int i = 1; i <= n; i++){
		power[i] = power[i - 1] * P % mod;
		hl[i] = (hl[i - 1] * P + s[i] - 'a' + 1) % mod;
	}
	for (int i = n; i >= 1; i--){
		hr[i] = (hr[i + 1] * P + s[i] - 'a' + 1) % mod;
	}
	int maxj = 0;
	vector <pii> ans;
	for (int i = 1; i <= n; i++){
//		cout << "i:" << i << endl;
		int len = max_len(i);
//		cout << "  len:" << len << endl;
		int l = 0, r = min(n - i - len + 1, all);
		while (l < r){
			int mid = l + r + 1 >> 1;
			if (pos[mid] < i - len + 1) l = mid;
			else r = mid - 1; 
		}
		if (maxj < 2 * len - 1 + 2 * l){
//			cout << "    change:" << endl;
//			cout << "    max_l:" << l << endl;
			maxj = 2 * len - 1 + 2 * l;
			ans = {{pos[l] - l + 1, l}, {i - len + 1, 2 * len - 1}, {n - l + 1, l}};
		}
	}
	int tot = 0;
	for (int i = 0; i < ans.size(); i++){
		if (ans[i].se) tot++;
	}
	printf("%d\n", tot);
	for (int i = 0; i < ans.size(); i++){
		if (ans[i].se) printf("%d %d\n", ans[i].fi, ans[i].se);
	}
	return 0;
}