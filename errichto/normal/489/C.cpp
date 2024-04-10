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

int main()
{
	int n, suma;
	scanf("%d%d", &n, &suma);
	if(n == 1 && suma == 0) {
		puts("0 0");
		return 0;
	}
	
	int memo_suma = suma;
	
	vi mala;
	RI(cyf, 9) if(cyf + (n-1) * 9 >= suma) {
		mala.pb(cyf);
		suma -= cyf;
		break;
	}
	FOR(i, 2, n) REP(cyf, 10) if(cyf + (n - i) * 9 >= suma) {
		mala.pb(cyf);
		suma -= cyf;
		break;
	}
	
	if(mala.size() != n || suma != 0) {
		puts("-1 -1");
		return 0;
	}
	
	suma = memo_suma;
	vi duza;
	FORD(cyf, 9, 1) if(cyf <= suma) {
		duza.pb(cyf);
		suma -= cyf;
		break;
	}
	FOR(i, 2, n) FORD(cyf, 9, 0) if(cyf <= suma) {
		duza.pb(cyf);
		suma -= cyf;
		break;
	}
	for(auto a : mala) printf("%d", a);
	printf(" ");
	for(auto a : duza) printf("%d", a);
	puts("");
	
	return 0;
}