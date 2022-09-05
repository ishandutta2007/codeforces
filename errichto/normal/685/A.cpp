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

int in[2], len[2];
bool vis[7];
ll answer = 0;

void rec(int which, int rem_len, ll so_far) {
	if(so_far >= in[which]) return;
	if(rem_len == 0) {
		if(which == 0) rec(1, len[1], 0LL);
		else {
			//printf("> %lld\n", so_far);
			++answer;
		}
		return;
	}
	REP(dig, 7) if(!vis[dig]) {
		vis[dig] = true;
		rec(which, rem_len - 1, so_far * 7 + dig);
		vis[dig] = false;
	}
}

int main() {
	REP(i, 2) scanf("%d", &in[i]);
	REP(i, 2) {
		ll mul = 7;
		len[i] = 1;
		while(mul < in[i]) {
			mul *= 7;
			++len[i];
		}
	}
	rec(0, len[0], 0LL);
	printf("%lld\n", answer);
	return 0;
}