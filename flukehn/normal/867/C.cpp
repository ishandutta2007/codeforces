#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a),i##_end=(b);i<=i##_end;i++)
#define per(i,b,a) for(int i=(b),i##_st=(a);i>=i##_st;i--)
#define pb push_back
#define ALL(x) (x).begin(),(x).end()
typedef pair<int,int> pii;
typedef long long ll;
const int inf=~0u>>1,MOD=1e9+7;/*
char *TT,*mo,but[(1<<15)+2];
#define getchar() ((TT==mo&&(mo=((TT=but)+fread(but,1,1<<15,stdin)),TT==mo))?-1:*TT++)//*/
inline int rd() {
	int x=0,c=0,f=1;
	for(; c<'0'||c>'9'; c=getchar())f=c!='-';
	for(; c>='0'&&c<='9'; c=getchar())x=x*10+c-'0';
	return f?x:-x;
}
const int N = 100010;
int n, m, s[N], a[N], b[N];
vector<pii> f, g;

int main() {
	scanf("%d%d",&n,&m);
	ll cnt = 0, cnta = 0, cntb = 0, ans = 0;
	for( int i = 0; i < n; ++i) {
		scanf( "%d%d%d", s+i, a+i, b+i );
		cnt += s[i];
		if( a[i] > b[i] ) {
			cnta += s[i];
			ans += 1LL*s[i] * a[i];
			f.pb( pii(a[i]-b[i], s[i]) );
		} else {
			cntb += s[i];
			ans += 1LL*s[i] * b[i];
			g.pb( pii(b[i]-a[i], s[i]) );
		}
	}
	sort(ALL(f));
	sort(ALL(g));
	ll bought = (cnt / m) + bool(cnt % m);
	ll boughta = (cnta / m) + bool(cnta % m);
	ll boughtb = (cntb / m) + bool(cntb % m);
	if( boughta + boughtb > bought ) {
		ll t_233a = cnta % m, ansa = ans;
		ll t_233b = cntb % m, ansb = ans;
		for( int i = 0; i < (int)f.size() && t_233a; ++i ) {
			ll t_233 = min(t_233a, (ll)f[i].second);
			ansa -= (ll)f[i].first * t_233;
			t_233a -= t_233;
		}
		for( int i = 0; i < (int)g.size() && t_233b; ++i ) {
			ll t_233 = min(t_233b, (ll)g[i].second);
			ansb -= (ll)g[i].first * t_233;
			t_233b -= t_233;
		}
		ans = max(ansa, ansb);
	}
	cout << ans << endl;
}