#include<cstdio>
#include<vector>
#include<algorithm>
#include<set>
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
bool debug;
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int inf = 1e9 + 5;
const int nax = 1e6 + 5;

ld licznik, mianownik;
int t[nax];
int n;

void f(int k) {
	if(k == 0) {
		mianownik++;
		RI(i, n) FOR(j, i + 1, n) if(t[i] > t[j]) licznik++;
		return;
	}
	RI(i, n) FOR(j, i, n) {
		reverse(t + i, t + j + 1);
		f(k-1);
		reverse(t + i, t + j + 1);
	}
}

int main(int argc, char *argv[])
{
	debug = argc > 1;
	
	int k;
	scanf("%d%d", &n, &k);
	RI(i, n) scanf("%d", &t[i]);
	f(k);
	printf("%.10lf\n", double(licznik / mianownik));
	
	return 0;
}