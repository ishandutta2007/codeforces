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
const int inf = 1e9 + 5, nax = 1e6 + 5;

int t[nax];

int main()
{
	multiset<int> a, b;
	int n;
	scanf("%d", &n);
	while(n--) {
		int pom;
		scanf("%d", &pom);
		a.insert(pom);
	}
	scanf("%d", &n);
	while(n--) {
		int pom;
		scanf("%d", &pom);
		b.insert(pom);
	}
	int licz = 0;
	while(!(a.empty() || b.empty())) {
		int aa = *a.begin(), bb = *b.begin();
		if(abs(aa - bb) <= 1) {
			a.erase(a.begin());
			b.erase(b.begin());
			licz++;
		}
		else if(aa < bb) a.erase(a.begin());
		else b.erase(b.begin());
	}
	printf("%d\n", licz);
	
	return 0;
}