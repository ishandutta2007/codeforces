#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = (a); i < int(b); ++i)
#define rrep(i, a, b) for(int i = (a) - 1; i >= int(b); --i)
#define trav(it, v) for(typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define all(v) (v).begin(), (v).end()
#define what_is(x) cerr << #x << " is " << x << endl;

typedef double fl;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;

char s[100005];
char t[100005];
int dp[100005][10];
int n, m;

void calc(int spos, int tpos){
	//dp[spos+1][tpos+1-(spos+1-5)]=max(max(dp[spos][tpos+1-(spos-5)], dp[spos+1][tpos-(spos+1-5)]), dp[spos][tpos-(spos-5)]+(s[spos] == t[tpos]));
	if(spos <= 0 || tpos <= 0){
		dp[spos][tpos-(spos-5)]=0;
		return;
	}
	dp[spos][tpos-(spos-5)]=max(dp[spos-1][tpos-(spos-1-5)], dp[spos][tpos-1-(spos-5)]);
	if(s[spos-1] == t[tpos-1])
		dp[spos][tpos-(spos-5)]=dp[spos-1][tpos-1-(spos-1-5)]+1;
}

struct State{
	int tlen;
	//char lastChar;
	int dp[3];

	State(int _tlen, /*char _lastChar, */int dp0, int dp1, int dp2){
		tlen=_tlen;
		//lastChar=_lastChar;
		dp[0]=dp0;
		dp[1]=dp1;
		dp[2]=dp2;
	}

	bool operator<(const State &other) const{
		if(tlen != other.tlen)
			return tlen < other.tlen;
		//if(lastChar != other.lastChar)
		//	return lastChar < other.lastChar;
		rep(i,0,3){
			if(dp[i] != other.dp[i])
				return dp[i] < other.dp[i];
		}
		return 0;
	}
};

map<State, ll> cache;

ll rec(int tlen){
	int best=0;
	rep(sp, tlen-1, tlen+2){
		if(sp >= 0){
			calc(sp, tlen);
			best=max(best, dp[sp][tlen-(sp-5)]);
		}
	}
	State curState(tlen, dp[tlen-1][tlen-(tlen-1-5)], dp[tlen][tlen-(tlen-5)], dp[tlen+1][tlen-(tlen+1-5)]);
	if(cache.count(curState))
		return cache[curState];
	if(best < tlen-1){
		cache[curState]=0;
		return 0;
	}
	if(tlen == n){
		if(dp[n][n-(n-5)] == n-1){
			cache[curState]=1;
			return 1;
		}
		cache[curState]=0;
		return 0;
	}
	bool hasUnused=0;
	ll valUnused=0;
	ll ret=0;
	rep(c,'a','a'+m){
		bool unused=1;
		if(tlen && c == s[tlen-1])
			unused=0;
		if(c == s[tlen])
			unused=0;
		if(c == s[tlen+1])
			unused=0;
		if(hasUnused && unused){
			ret += valUnused;
			continue;
		}
		t[tlen]=c;
		ll res = rec(tlen+1);
		if(unused){
			hasUnused=1;
			valUnused=res;
		}
		ret += res;
		
	}
	cache[curState]=ret;
	return ret;
}

int main(){
	scanf("%d%d", &n, &m);
	scanf("%s", s);
	printf("%I64d\n", rec(0));
}