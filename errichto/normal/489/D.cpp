#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<set>
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
const int inf = 1e9 + 5, nax = 3e3 + 5;

bool ok[nax][nax];
vi w[nax];

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	while(m--) {
		int a, b;
		scanf("%d%d", &a, &b);
		ok[a][b] = true;
		w[a].pb(b);
	}
	int res = 0;
	RI(a,n) RI(c,n) if(a != c) {
		int licz = 0;
		for(auto b : w[a]) if(ok[b][c]) licz++;
		res += licz * (licz - 1) / 2;
	}
	printf("%d\n", res);
	return 0;
}