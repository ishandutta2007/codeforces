#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
#define FOR(i,a,n) for(int i=(a),_n=(n); i <= _n; ++i)
#define FORD(i,a,n) for(int i=(a),_n=(n); i >= _n; --i)
#define REP(i,n) FOR(i,0,(n)-1)
#define RI(i,n) FOR(i,1,(n))
#define pb push_back
#define mp make_pair
#define st first
#define nd second
#define mini(a,b) a=min(a,(b))
#define maxi(a,b) a=max(a,(b))
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int inf = 1e9 + 5, nax = 1e6 + 5;

int t[nax];

int main()
{
	int n;
	scanf("%d", &n);
	REP(i,n) scanf("%d", &t[i]);
	printf("%d\n", n);
	REP(i,n) {
		pii b = mp(t[i], i);
		FOR(j,i,n-1) mini(b, mp(t[j],j));
		printf("%d %d\n", i, b.nd);
		swap(t[i], t[b.nd]);
	}
	
	return 0;
}