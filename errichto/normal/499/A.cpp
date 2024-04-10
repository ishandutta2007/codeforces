#include<cstdio>
#include<algorithm>
#include<cstring>
#include<assert.h>
#include<vector>
using namespace std;
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;++i)
#define RI(i,n) FOR(i,1,n)
#define REP(i,n) FOR(i,0,(n)-1)
#define mini(a,b) a=min(a,b)
#define maxi(a,b) a=max(a,b)
#define pb push_back
#define st first
#define nd second
typedef long long ll;
typedef vector<int> vi;
typedef long double ld;
typedef pair<int,int> pii;
const int nax = 1e6 + 5;
const int inf = 1e9 + 5;



int main() {
	int n, x;
	scanf("%d%d", &n, &x);
	int tera = 1;
	int res = 0;
	RI(i, n) {
		int a, b;
		scanf("%d%d", &a, &b);
		while(tera + x <= a) tera += x;
		res += a - tera;
		assert(tera <= a);
		tera = a;
		res += b - a + 1;
		tera = b + 1;
	}
	printf("%d\n", res);
	return 0;
}