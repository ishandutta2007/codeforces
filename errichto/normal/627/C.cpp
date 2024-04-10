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

pii t[nax];

struct P {
	int x;
	ll so_far;
	int speed;
	int szer;
};

int main() {
	int L, volume, n;
	scanf("%d%d%d", &L, &volume, &n);
	REP(i, n) scanf("%d%d", &t[i].st, &t[i].nd);
	t[n] = mp(L, 170);
	++n;
	sort(t, t + n);
	list<P> kol;
	kol.push_back(P{0,0LL,0,volume});
	REP(i, n) {
		int now = t[i].first;
		int my_price = t[i].second;
		while(!kol.empty()) {
			P p = kol.front();
			if(p.x >= now) break;
			kol.pop_front();
			if(p.x + p.szer >= now) {
				int diff = now - p.x;
				kol.push_front(P{now, p.so_far + (ll)p.speed*diff, p.speed,p.szer-diff});
			}
		}
		if(kol.empty()) {
			puts("-1");
			return 0;
		}
		P memo;
		while(!kol.empty()) {
			memo = kol.back();
			if(memo.speed < my_price) break;
			kol.pop_back();
		}
		if(kol.empty()) memo.szer = 0;
		kol.push_back(P{memo.x+memo.szer, memo.so_far + (ll)memo.speed*memo.szer, t[i].second, t[i].first+volume-(memo.x+memo.szer)});
		
		//wzgledem += diff;
	}
	assert(!kol.empty());
	printf("%lld\n", kol.front().so_far);
	return 0;
}