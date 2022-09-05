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
const int nax = 1e6 + 35;

int t[nax];

int main() {
	int n;
	scanf("%d", &n);
	REP(i, n) {
		int a;
		scanf("%d", &a);
		t[a]++;
	}
	#define n dupa
	int res = 0;
	REP(i, nax - 1) if(t[i]) {
		t[i+1] += t[i] / 2;
		if(t[i] % 2) ++res;
	}
	printf("%d\n", res);
	return 0;
}