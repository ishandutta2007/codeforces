#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i = a; i <= b; ++i)
#define FORD(i,a,b) for(int i = a; i >= b; --i)
#define RI(i,n) FOR(i,1,(n))
#define REP(i,n) FOR(i,0,(n)-1)
#define mini(a,b) a=min(a,b)
#define maxi(a,b) a=max(a,b)
#define mp make_pair
#define pb push_back
#define st first
#define nd second
#define sz(w) (int) w.size()
bool debug;
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int inf = 1e9 + 5;
const int nax = 1e6 + 5;

int in[nax];
int spec[nax];

int main(int argc, char *argv[])
{
	debug = argc > 1;
	
	int n;
	scanf("%d", &n);
	REP(_, n) {
		int a;
		scanf("%d", &a);
		in[a]++;
	}
	int res = 0;
	RI(i, 1000 * 1000) {
		maxi(res, in[i] + spec[i]);
		for(int j = 2 * i; j <= 1000 * 1000; j += i)
			maxi(spec[j], in[i] + spec[i]);
	}
	printf("%d\n", res);
	
	return 0;
}