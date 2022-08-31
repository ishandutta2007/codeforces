#include <bits/stdc++.h>
#define ll long long
#define maxn 200005 /*rem*/
#define mod 1000000007 
#define db double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
char s[maxn];
vi cur;
int main() {
	scanf("%s", s);
	int l = strlen(s);
	int pl = -1, rs = l;
	while (1) {
		for (int j = pl + 1; j <= l; j++) {
			if (j == l || s[j] == '(') {
				pl = j;
				break;
			}
		}	
		for (int j = rs - 1; j >= -1; j--) {
			if (j == -1 || s[j] == ')') {
				rs = j;
				break;
			}
		}
		if (pl > rs) break;
		else {
			cur.pb(pl);
			cur.pb(rs);
		}
	}
	if (cur.size()) {
		cout << 1 << endl;
		cout << cur.size() << endl;
		sort(cur.begin(), cur.end());
		for (auto v:cur) cout << v + 1 << ' ';
	}
	else cout << 0 << endl;
	return 0;
}