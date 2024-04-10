#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<assert.h>
using namespace std;
#define FOR(i,a,b) for(int i = a; i <= b; ++i)
#define FORD(i,a,b) for(int i = a; i >= b; --i)
#define RI(i,n) FOR(i,1,n)
#define REP(i,n) FOR(i,0,(n)-1)
#define mini(a,b) a=min(a,b)
#define maxi(a,b) a=max(a,b)
#define mp make_pair
#define pb push_back
#define st first
#define nd second
#define sz(w) (int) w.size()
bool debug;
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int inf = 1e9 + 5;
const ll INF = (ll) inf * inf;
const int nax = 1e6 + 5;

//int nn[nax], pp[nax];
#include<set>
multiset<int> s;
int res[nax];
set<int> obecne;

int main(int argc, char *argv[])
{
	debug = argc > 1;
	
	int n;
	scanf("%d", &n);
	//REP(i, n + 2) nn[i] = i + 1;
	//RI(i, n + 2) pp[i] = i - 1;
	s.insert(n);
	obecne.insert(0);
	obecne.insert(n+1);
	vector<pii> w;
	RI(i,n) {
		int a;
		scanf("%d", &a);
		w.pb(mp(a,i));
	}
	sort(w.begin(), w.end());
	for(auto para : w) {
		int a = para.st;
		int i = para.nd;
		auto it = obecne.upper_bound(i);
		int nn = *it;
		--it;
		int pp = *it;
		int d = nn-pp-1;
		s.erase(s.find(d));
		s.insert(nn-i-1);
		s.insert(i-pp-1);
		obecne.insert(i);
		auto ha = s.end();
		--ha;
		int ma = *ha;
		if(res[ma]==0)res[ma] = a;
	}
	int ja = 0;
	REP(i, n + 2) {
		if(1 <= i && i <= n) printf("%d ", ja);
		if(res[i] != 0) ja = res[i];
	}
	puts("");
	//REP(i, n + 2) printf("%d ", res[i]);
	
	return 0;
}