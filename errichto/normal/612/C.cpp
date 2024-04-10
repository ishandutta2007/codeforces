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
string wzo = "<>{}[]()";

int find(char znak) {
	REP(i, 8) if(znak == wzo[i]) return i;
	assert(false);
}
bool open(int znak) { return znak % 2 == 0; }
bool close(int znak) { return !open(znak); }

void NO() {
	puts("Impossible");
	exit(0);
}

int main() {
	scanf("%s", sl);
	int n = strlen(sl);
	vi w;
	int ans = 0;
	REP(iii, n) {
		int znak = find(sl[iii]);
		if(open(znak)) w.pb(znak);
		else {
			if(w.empty()) NO();
			int la = w.back();
			w.pop_back();
			if(la != (znak ^ 1)) ++ans;
		}
	}
	if(!w.empty()) NO();
	printf("%d\n", ans);
	return 0;
}