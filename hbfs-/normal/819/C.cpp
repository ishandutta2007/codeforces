#include <bits/stdc++.h>
#define x first
#define y second
#define N 2000500
#define tp 2000000

using namespace std;

typedef long long LL;
typedef pair<LL,LL> pii;

int n[3],m[3],s[3];
LL nn,mm,ss;
LL tmp[N],F[N],ans;
bool mark[N];
int cnt,tot,fr[N],pr[N];
vector<pii> yS,yN;

inline int rd() {int r;scanf("%d",&r);return r;}

void init() {
	 n[0] = rd(), n[1] = rd(), n[2] = rd();
	 nn = 1LL * n[0] * n[1] * n[2];
	 m[0] = rd(), m[1] = rd(), m[2] = rd();
	 mm = 1LL * m[0] * m[1] * m[2];
	 s[0] = rd(), s[1] = rd(), s[2] = rd()<<1;
	 ss = 1LL * s[0] * s[1] * s[2];
}

vector<pii> fact(int a[3]) {
	vector<pii> ret;
	int tot = 0;
	for (int _=0;_<3;_++) {
		int t = a[_];
		while (t != 1)
			tmp[++tot] = fr[t], t /= fr[t];
	}
	
	sort(tmp+1, tmp+tot+1); tmp[tot+1] = -1;
	pii cur = pii(0,0);
	for (int i=1;i<=tot+1;i++)
		if (tmp[i] != tmp[i-1]) {
			if (i!=1) ret.push_back(cur);
			cur.x = tmp[i], cur.y = 1;
		}
		else
			cur.y++;
	return ret;
}

void prepare() {
	for (int i=2;i<=tp;i++) {
		if (!mark[i]) pr[++cnt] = i, fr[i] = i;
		for (int j=1;j<=cnt && i*pr[j]<=tp;j++) {
			mark[i*pr[j]] = 1;
			fr[i*pr[j]] = pr[j];
			if (i%pr[j] == 0) break;
		}
	}
}

void dfs0(int dep, LL cur) {
	if (cur > nn) return ;
	if (dep == (int)yS.size()) {
		ans++;
		return ;
	}
	
	LL g = 1LL;
	for (int i=0;i<=yS[dep].y;++i)
		dfs0(dep+1, cur*g), g *= yS[dep].x;
}

void dfs1(int dep,int xs,LL cur) {
	if (dep > tot) {
		ans += 1LL * xs * (mm / cur);
		return ;
	}
	dfs1(dep+1, -xs, cur*F[dep]);
	dfs1(dep+1, xs, cur);
}


void solve() {
	
 	ans = 0LL;
	init();
	
	yS = fact(s);
	yN = fact(n);

//	for (int i=0;i<(int)yS.size();i++) printf("::%d\n",yS[i].x);
	//s
	dfs0(0, 1);
	
	tot = 0;
	for (int i=0;i<(int)yN.size();++i) {
		LL g = yN[i].x;
		for (int _=1;_<=yN[i].y;++_) {
			if (ss%g) {F[++tot] = g; break;}
			g *= yN[i].x;
		}
	}
	
	//
	dfs1(1,1,1);
	cout << ans <<endl;
}

int main() {
	prepare();
	for (int T=rd();T;T--) solve();
	return 0;
}