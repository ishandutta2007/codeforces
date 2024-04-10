#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<set>
using namespace std;
#define FOR(i,a,n) for(int i = (a); i <= (n); ++i)
#define FORD(i,a,n) for(int i = (a); i >= (n); --i)
#define REP(i,n) FOR(i,0,(n)-1)
#define RI(i,n) FOR(i,1,(n))
#define pb push_back
#define mp make_pair
#define st first
#define nd second
#define mini(a,b) a=min(a,(b))
#define maxi(a,b) a=max(a,(b))
#ifdef LOK
#define debug printf
#else
#define debug if(0)printf
#endif
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int inf = 1e9 + 5;
const int nax = 1e6 + 5;

bool ok[nax];

int main() {
	int n, cel;
	scanf("%d%d", &n, &cel);
	ok[1] = true;
	RI(i, n - 1) {
		int a;
		scanf("%d", &a);
		if(ok[i]) ok[i + a] = true;
	}
	if(ok[cel]) puts("YES");
	else puts("NO");
	
	
	return 0;
}