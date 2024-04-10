#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i = (a); i <= (b); ++i)
#define FORD(i,a,b) for(int i = (a); i >= (b); --i)
#define RI(i,n) FOR(i,1,(n))
#define REP(i,n) FOR(i,0,(n)-1)
#define mini(a,b) a=min(a,b)
#define maxi(a,b) a=max(a,b)
#define mp make_pair
#define pb push_back
#define st first
#define nd second
#define sz(w) (int) w.size()
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int inf = 1e9 + 5;
const int nax = 1e6 + 5;

int h[nax][26];
char sl[nax];
string s[nax];
char tmp[nax];
int ans[nax];
int T = 0;
pii dp[nax];

int daj(int hasz, char z, bool must) {
	int a;
	if('A' <= z && z <= 'Z') a = z - 'A';
	else a = z - 'a';
	if(h[hasz][a]) return h[hasz][a];
	if(must) return h[hasz][a] = ++T;
	return -2;
}

int main() {
	int d;
	scanf("%d", &d);
	scanf("%s", sl);
	int n; // careful
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%s", tmp);
		s[i] = (string) tmp;
		int len = strlen(tmp);
		reverse(tmp, tmp + len);
		int hasz = 0;
		for(int j = 0; j < len; ++j)
			hasz = daj(hasz, tmp[j], true);
		ans[hasz] = i;
	}
	for(int i = 0; i <= d + 1; ++i) dp[i] = mp(-2,-2);
	dp[0] = mp(0,0);
	for(int i = 0; i < d; ++i) if(dp[i].first >= 0) {
		int hasz = 0;
		for(int j = i; j <= min(i + 1000, d - 1); ++j) {
			hasz = daj(hasz, sl[j], false);
			if(hasz == -2) break;
			if(ans[hasz]) {
				dp[j+1] = mp(i, ans[hasz]);
			}
		}
	}
	vi w;
	while(d > 0) {
		w.pb(dp[d].second);
		d = dp[d].first;
	}
	reverse(w.begin(), w.end());
	for(int x : w) printf("%s ", s[x].c_str());
	puts("");
	return 0;
}