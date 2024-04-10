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
const int nax = 205;

char sl[nax];
bool dp[nax][nax][nax];
int A, B, C;

void read(int n) {
	int a = 0, b = 0, c = 0;
	scanf("%s", sl);
	REP(i, n) {
		if(sl[i] == 'R') ++a;
		else if(sl[i] == 'G') ++b;
		else if(sl[i] == 'B') ++c;
		else assert(false);
	}
	dp[a][b][c] = true;
	A = a;
	B = b;
	C = c;
}

int main() {
	int n;
	scanf("%d", &n);
	read(n);
	FORD(s, n, 0) FOR(a,0,n) FOR(b,0,n) {
		int c = s - a - b;
		if(0 <= c && c <= n && dp[a][b][c]) {
			if(a >= 2) dp[a-1][b][c] = true;
			if(b >= 2) dp[a][b-1][c] = true;
			if(c >= 2) dp[a][b][c-1] = true;
			if(a && b) dp[a-1][b-1][c+1] = true;
			if(a && c) dp[a-1][b+1][c-1] = true;
			if(b && c) dp[a+1][b-1][c-1] = true;
		}
	}
	vector<char> ans;
	if(dp[1][0][0]) ans.pb('R');
	if(dp[0][1][0]) ans.pb('G');
	if(dp[0][0][1]) ans.pb('B');
	sort(ans.begin(), ans.end());
	for(char z : ans) printf("%c", z);
	puts("");
	return 0;
}