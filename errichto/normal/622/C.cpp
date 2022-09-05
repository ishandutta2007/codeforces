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

int t[nax];
int ans;
int a, b, x;
void f(int i) {
	if(a <= i && i <= b && t[i] != x)
		ans = i;
}

int main() {
	int n, q;
	scanf("%d%d", &n, &q);
	RI(i, n) scanf("%d", &t[i]);
	set<int> s;
	RI(i, n) if(i == 1 || t[i] != t[i-1]) s.insert(i);
	while(q--) {
		scanf("%d%d%d", &a, &b, &x);
		ans = -1;
		f(a);
		f(b);
		f(a+1);
		f(b-1);
		auto it = s.lower_bound(a+1);
		if(it != s.end()) f(*it);
		printf("%d\n", ans);
	}
	return 0;
}