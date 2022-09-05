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

char sl[nax];
bool dp[nax][4];

bool same(int a, int b, int c, int d) {
	if(b - a != d - c) return false;
	FOR(i,a,b) if(sl[i] != sl[i+c-a]) return false;
	return true;
}

int main() {
	scanf("%s", sl);
	int n = strlen(sl);
	if(n -2 >= 5) dp[n-2][2] = true;
	if(n - 3 >= 5) dp[n-3][3] = true;
	FORD(i, n, 5)
		FOR(len, 2, 3) {
			int i2 = i + len - 1;
			if(i2 >= n) continue;
			FOR(len2, 2, 3)
				if(dp[i2+1][len2] && !same(i,i2,i2+1,i2+len2))
				dp[i][len] = true;
		}
	
	set<string> secik;
	FOR(i, 0, n)
		FOR(len,2,3)
			if(dp[i][len]) {
				string em = "";
				REP(j,len) em += sl[i+j];
				secik.insert(em);
			}
	printf("%d\n", (int) secik.size());
	for(string s : secik) printf("%s\n", s.c_str());
	return 0;
}