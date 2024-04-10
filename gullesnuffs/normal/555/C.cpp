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

struct Region{
	int xl, xr;
	int boundx, boundy;

	bool operator<(const Region &other) const{
		return make_pair(xl, xr) < make_pair(other.xl, other.xr);
	}
};

set<Region> S;
set<int> done;

int main(){
	Region start;
	int n, q;
	scanf("%d%d", &n, &q);
	start.xl=0;
	start.xr=n+1;
	start.boundx=0;
	start.boundy=0;
	S.insert(start);
	rep(i,0,q){
		int x, y;
		scanf("%d%d", &x, &y);
		char dir[3];
		scanf("%s", dir);
		if(done.find(x) != done.end()){
			printf("0\n");
			continue;
		}
		done.insert(x);
		Region r;
		r.xl=x;
		r.xr=2000000000;
		auto it = S.lower_bound(r);
		--it;
		r=*it;
		S.erase(it);
		Region rl, rr;
		rl.xl=r.xl;
		rl.xr=x;
		rr.xl=x;
		rr.xr=r.xr;
		if(dir[0] == 'U'){
			printf("%d\n", y-r.boundy);
			rl.boundx=r.boundx;
			rl.boundy=r.boundy;
			rr.boundx=x;
			rr.boundy=r.boundy;
		}
		else{
			printf("%d\n", x-r.boundx);
			rl.boundx=r.boundx;
			rl.boundy=y;
			rr.boundx=r.boundx;
			rr.boundy=r.boundy;
		}
		S.insert(rl);
		S.insert(rr);
	}
}