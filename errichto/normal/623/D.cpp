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
const int nax = 105;

ld p[nax], h[nax], x[nax];
int cnt[nax];

void act(int i) {
	ld tmp = pow(1 - p[i], cnt[i]);
	x[i] = 1 - tmp;
	h[i] = x[i] / (1 - tmp * (1 - p[i]));
	//h[i] = x[i] / (1 - pow(1 - p[i], cnt[i]+1));
}

int main() {
	int n;
	scanf("%d", &n);
	RI(i, n) {
		int tmp;
		scanf("%d", &tmp);
		p[i] = tmp / 100.;
	}
	RI(i, n) cnt[i] = 1;
	ld ans = 0;
	ld m_prev = 0;
	int MAX = 600000;
	RI(i, n) act(i);
	ld m = 1;
	RI(i, n) m *= x[i];
	FOR(tura, n, MAX) {
		ans += tura * (m - m_prev);
		m_prev = m;
		int best = 1;
		RI(i, n) if(h[i] < h[best]) best = i;
		cnt[best]++;
		m /= x[best];
		act(best);
		m *= x[best];
	}
	ans += MAX * (1 - m_prev);
	printf("%.10lf\n", double(ans));
	return 0;
}